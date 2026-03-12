#include "App.hpp"
#include <raylib.h>
using namespace therraria;

App::App()
{
  InitWindow(1600, 900, "Therarria++");
  SetTargetFPS(60);

  // load world data
  m_World.Load();
}

void App::Run()
{
  while (!WindowShouldClose())
  {
    // logic update
    float_t dt = GetFrameTime();

    m_World.Update(dt);

    // drawing
    BeginDrawing();
    ClearBackground(BLACK);

    m_World.Draw();

    // draw debug data
    DrawText(std::format("FPS: {}", GetFPS()).c_str(), 10, 10, 24, GREEN);

    EndDrawing();
  }

  Quit();
}

void App::Quit()
{
  CloseWindow();
}
