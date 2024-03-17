#pragma once

#include <GLFW/glfw3.h>

/** @brief Example settings that can be changed e.g. by command line arguments */
#include <vector>
struct Settings
{
  /** @brief Activates validation layers (and message output) when set to true */
  bool validation = false;
  /** @brief Set to true if fullscreen mode has been requested via command line */
  bool fullscreen = false;
  /** @brief Set to true if v-sync will be forced for the swapchain */
  bool vsync = false;
};

struct WindowParameters
{
  bool quit = false;
  GLFWwindow *window;
};

class VKSample;

class VKApplication
{
public:
  static void Setup(VKSample *pSample, bool enableValidation, void *hInstance = nullptr, int nCmdShow = 0);
  static int RenderLoop();
  static std::vector<const char *> *GetArgs() { return &m_args; }
  static VKSample *GetVKSample() { return m_pVKSample; }
  static Settings settings;
  static WindowParameters winParams;
  static bool resizing;

private:
  static VKSample *m_pVKSample;
  static std::vector<const char *> m_args;
};