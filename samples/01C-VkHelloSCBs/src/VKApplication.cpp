#include "VKApplication.hpp"
#include "VKSample.hpp"
#include <cstring>


VKSample *VKApplication::m_pVKSample = nullptr;
std::vector<const char *> VKApplication::m_args;
WindowParameters VKApplication::winParams{};
Settings VKApplication::settings{};
bool VKApplication::resizing = false;


void VKApplication::Setup(VKSample *pSample, bool enableValidation, void *hInstance, int nCmdShow)
{
  m_pVKSample = pSample;
  settings.validation = enableValidation;

  if (GLFW_FALSE == glfwInit()) { glfwTerminate(); }
  GLFWmonitor *selectedMonitor = nullptr;

  if (settings.fullscreen) selectedMonitor = glfwGetPrimaryMonitor();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  winParams.window = glfwCreateWindow(static_cast<int>(m_pVKSample->GetWidth()),
    static_cast<int>(m_pVKSample->GetHeight()),
    m_pVKSample->GetTitle(),
    selectedMonitor,
    nullptr);


  if (settings.fullscreen) {}
  glfwSetWindowSizeCallback(
    winParams.window, [](GLFWwindow *window, int width, int height) { m_pVKSample->WindowResize(width, height); });

  // Initialize the sample. OnInit is defined in each child-implementation of VKSample.
  pSample->OnInit();
}

int VKApplication::RenderLoop()
{
  // Main sample loop
  while (!glfwWindowShouldClose(winParams.window)) {

    glfwPollEvents();

    if (!winParams.quit && m_pVKSample->IsInitialized()) {
      m_pVKSample->OnUpdate();
      m_pVKSample->OnRender();
    }

    if (m_pVKSample->GetFrameCounter() % 1000 == 0) { std::string windowTitle = m_pVKSample->GetWindowTitle(); }
  }

  m_pVKSample->OnDestroy();
  return 0;
}
