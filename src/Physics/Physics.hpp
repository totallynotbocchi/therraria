#pragma once

#include "pch.hpp"

namespace therraria
{

class Physics
{
  uint16_t m_Gravity = 981;

public:
  Physics(uint16_t gravity);
  Physics();
};

} // namespace therraria
