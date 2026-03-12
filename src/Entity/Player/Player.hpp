#pragma once

#include "../../Physics/Physics.hpp"
#include "../Entity.hpp"
#include "pch.hpp"
#include <cstdint>
#include <raylib.h>

namespace therraria
{

class Player : public PhysicsBody, public Entity
{
  uint16_t m_ID;

  uint32_t m_Speed = 900;
  Vector2 m_Pos = {};

public:
  Player();

  void Update(float_t dt);
  void Draw() const;

  Vector2& GetPosition() override;
  uint32_t& GetSpeed() override;

  uint16_t GetID() override;
};

} // namespace therraria
