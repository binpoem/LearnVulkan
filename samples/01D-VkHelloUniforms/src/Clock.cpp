
#include "Clock.hpp"

void Clock::Initialize()
{
  deltaTime = 0.0f;

  currentTime = std::chrono::steady_clock::now();
  lastTime = currentTime;

  isInitialized = true;
}

void Clock::Update()
{
  currentTime = std::chrono::steady_clock::now();
  elapsedTime = currentTime - lastTime;

  lastTime = currentTime;

  if (isInitialized) {
    deltaTime = elapsedTime.count() > 0.1 ? 0.1f : static_cast<float>(elapsedTime.count());

    timeSinceStart += deltaTime * timeScale;
  } else {
    Initialize();
  }
}

float Clock::GetFrameRate() const { return 1.0f / (deltaTime); }

float Clock::GetDeltaTime() const { return deltaTime * timeScale; }
