#pragma once

#include "pch.hpp"
#include <raylib.h>

namespace therraria
{

class Player
{
  uint32_t m_Speed = 900;
  Vector2 m_Pos = {};

public:
  Player();

  void Update(float_t dt);
  void Draw() const;
};

} // namespace therraria
