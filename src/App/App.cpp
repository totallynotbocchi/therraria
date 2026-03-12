#include "App.hpp"
#include <raylib.h>
using namespace therraria;

App::App()
{
  InitWindow(1600, 900, "Therarria");
  SetTargetFPS(60);
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

    EndDrawing();
  }

  Quit();
}

void App::Quit()
{
  CloseWindow();
}
