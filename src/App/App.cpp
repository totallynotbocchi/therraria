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
    m_World.Update();

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
