#include "VKApplication.hpp"
#include "VKHelloSCB.hpp"

int main(const int argc, const char *argv[])
{
  for (int i = 0; i < argc; i++) { VKApplication::GetArgs()->push_back(argv[i]); };

  VKHelloSCB sample(1280, 720, "VK Hello Window");
  VKApplication::Setup(&sample, true);
  return VKApplication::RenderLoop();
}