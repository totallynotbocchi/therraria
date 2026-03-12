#pragma once

#include "pch.hpp"

namespace therraria
{

class Entity
{
  static uint16_t LAST_ID;

public:
  virtual ~Entity() = default;

  virtual uint16_t GetID() = 0;

  static uint16_t GenerateID();
};

} // namespace therraria
