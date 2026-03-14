#include "Entity.hpp"
using namespace therraria;

EntityID therraria::LAST_ID = 0;

EntityID therraria::GenerateID()
{
  return LAST_ID++;
}
