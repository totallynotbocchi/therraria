#include "Player.hpp"
using namespace therraria;

Player::Player()
    : m_Pos({GetScreenWidth() / 2.f, GetScreenHeight() / 2.f})
    , m_ID(Entity::GenerateID())
{
  std::println("Created player object with entity ID '{}'.", m_ID);
}

void Player::Update(float dt)
{
  // movement
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    m_Pos.x -= m_Speed * dt;
  else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    m_Pos.x += m_Speed * dt;
}

void Player::Draw() const
{
  DrawRectangle(m_Pos.x, m_Pos.y, 50, 50, WHITE);
}

Vector2& Player::GetPosition()
{
  return m_Pos;
}

uint32_t& Player::GetSpeed()
{
  return m_Speed;
}

uint16_t Player::GetID()
{
  return m_ID;
}
