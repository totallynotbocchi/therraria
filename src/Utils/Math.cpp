#include "Math.hpp"
using namespace therraria;

float therraria::utils::MoveTowards(float current, float target, float maxDelta)
{
  // if we are already close enough, just return the target
  if (abs(target - current) <= maxDelta)
    return target;

  // otherwise, move current closer to target by exactly max detla
  return current + sgn(target - current) * maxDelta;
}
