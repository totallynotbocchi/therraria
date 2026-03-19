#pragma once

#include "Entity/Entity.hpp"
#include "pch.hpp"

namespace therraria
{

class Player : public Entity
{
  EntityID m_ID;

  uint32_t m_MoveSpeed = 3000, m_MaxSpeed = 3000;
  float m_Friction = 0.70f;
  Vector2 m_Pos = {0, 0}, m_Vel = {0, 0};

  bool m_IsCollidable = true;
  bool m_IsAffectedByGravity = true;

  static constexpr int32_t DEFAULT_HEALTH = 100;
  int32_t m_CurrentHealth = DEFAULT_HEALTH, m_MaxHealth = DEFAULT_HEALTH;

public:
  Player();
  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;

  EntityID GetID() const override;

  void Update() override;
  void Draw() const override;

  Vector2& GetPosition() override;
  Vector2& GetVelocity() override;

  std::optional<Rectangle> GetCollisionBody() override;
  bool IsCollidable() const override;
  bool IsAffectedByGravity() const override;

  std::optional<int32_t> GetHealth() const override;
  void AddHealth(int32_t amount) override;
  void SetHealth(int32_t value) override;
};

} // namespace therraria
