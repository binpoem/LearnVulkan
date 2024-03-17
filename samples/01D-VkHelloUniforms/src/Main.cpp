#include "VKApplication.hpp"
#include "VKHelloUniforms.hpp"

int main(const int argc, const char *argv[])
{
  for (int i = 0; i < argc; i++) { VKApplication::GetArgs()->push_back(argv[i]); };

  VKHelloUniforms sample(1280, 720, "VK Hello Window");
  VKApplication::Setup(&sample, true);
  return VKApplication::RenderLoop();
}