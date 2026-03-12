#include "Player.hpp"
#include <raylib.h>
using namespace therraria;

Player::Player()
    : m_Pos({GetScreenWidth() / 2.f, GetScreenHeight() / 2.f})
{
  std::println("Created player object.");
}

void Player::Update(float dt)
{
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    m_Pos.x -= m_Speed * dt;
  else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    m_Pos.x += m_Speed * dt;
}

void Player::Draw() const
{
  DrawRectangle(m_Pos.x, m_Pos.y, 50, 50, WHITE);
}
