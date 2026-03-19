#pragma once

#include "pch.hpp"
#include <concepts>
#include <cstdlib>

namespace therraria::utils
{

// sign function
// overcomplication go brr
template <typename T>
  requires std::integral<T> || std::floating_point<T>
int sgn(T val)
{
  if (val > 0)
    return 1;
  else if (val < 0)
    return -1;

  return 0;
}

// too lazy to make this a template
float MoveTowards(float current, float target, float maxDelta);

} // namespace therraria::utils
