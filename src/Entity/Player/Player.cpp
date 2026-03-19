#include "Player.hpp"
using namespace therraria;

Player::Player()
    : m_ID(GenerateID())
{
  std::println("Created player object with entity ID '{}'.", m_ID);
}

// TODO: generalize some things
void Player::Update()
{
  float_t dt = GetFrameTime();
  Vector2 inputForce = {0, 0};

  // movement
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    inputForce.x -= m_MoveSpeed;
  else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    inputForce.x += m_MoveSpeed;

  // apply the input force to the velocity
  m_Vel.x += inputForce.x * dt;
  m_Vel.y += inputForce.y * dt;

  // apply friction when there is no input
  if (inputForce.x == 0)
    m_Vel.x *= m_Friction;

  // convert velocity to movement
  m_Pos.x += m_Vel.x * dt;
  m_Pos.y += m_Vel.y * dt;
}

void Player::Draw() const
{
  DrawRectangle(m_Pos.x, m_Pos.y, 50, 50, WHITE);
}

Vector2& Player::GetPosition()
{
  return m_Pos;
}

Vector2& Player::GetVelocity()
{
  return m_Vel;
}

uint16_t Player::GetID() const
{
  return m_ID;
}

bool Player::IsCollidable() const
{
  return m_IsCollidable;
}

bool Player::IsAffectedByGravity() const
{
  return m_IsAffectedByGravity;
}

std::optional<Rectangle> Player::GetCollisionBody()
{
  // created on the spot
  // TODO: maybe pre initialize it instead?
  return (Rectangle){m_Pos.x, m_Pos.y, 50, 50};
}

std::optional<int32_t> Player::GetHealth() const
{
  return m_CurrentHealth;
}

void Player::AddHealth(int32_t amount)
{
  m_CurrentHealth = std::clamp(m_CurrentHealth + amount, 0, m_MaxHealth);
}

void Player::SetHealth(int32_t value)
{
  m_CurrentHealth = std::clamp(value, 0, m_MaxHealth);
}
