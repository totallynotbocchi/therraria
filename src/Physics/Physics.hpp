#pragma once

#include "pch.hpp"
#include <raylib.h>

namespace therraria
{

// base class for things affected by physics
class PhysicsBody
{
public:
  virtual ~PhysicsBody() = default;

  virtual Vector2& GetPosition() = 0;
  virtual uint32_t& GetSpeed() = 0;
};

// the physics "engine"
class Physics
{
  uint16_t m_Gravity = 981;

public:
  Physics(uint16_t gravity);
  Physics() = default;

  void ApplyGravity(float_t dt, PhysicsBody& body);
};

} // namespace therraria
