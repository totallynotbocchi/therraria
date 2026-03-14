#pragma once

#include "pch.hpp"
#include <cstdint>
#include <raylib.h>

namespace therraria
{

using EntityID = uint16_t;

extern EntityID LAST_ID;
EntityID GenerateID();

struct Entity
{
  virtual ~Entity() = default;

  // basic

  virtual EntityID GetID() const = 0;
  virtual void Update() = 0;
  virtual void Draw() const = 0;

  // physics

  virtual Vector2& GetPosition() = 0;
  virtual Vector2& GetVelocity() = 0;

  virtual bool IsCollidable() const = 0;
  virtual bool IsAffectedByGravity() const = 0;
  virtual std::optional<Rectangle> GetCollisionBody() = 0;

  // health

  virtual std::optional<int32_t> GetHealth() const = 0;
  virtual void SetHealth(int32_t value) = 0;
  virtual void AddHealth(int32_t amount) = 0;
};

} // namespace therraria
