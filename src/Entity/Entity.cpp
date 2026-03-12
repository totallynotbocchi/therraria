#include "Entity.hpp"
using namespace therraria;

uint16_t Entity::LAST_ID = 0;

uint16_t Entity::GenerateID()
{
  return Entity::LAST_ID++;
}
