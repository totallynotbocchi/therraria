#include "Physics.hpp"
#include <print>
using namespace therraria;

Physics::Physics(uint16_t gravity)
    : m_Gravity(gravity)
{
}

void Physics::ApplyGravityOnEntity(Entity& entity)
{
  if (!entity.IsAffectedByGravity())
    return;

  entity.GetVelocity().y += m_Gravity;
}

// here, collision means literal body collision, whereas touching just means overlapping
bool Physics::EntitiesTouch(Entity& e1, Entity& e2, bool collision_matters)
{
  // get collision bodies
  auto body1 = e1.GetCollisionBody();
  auto body2 = e2.GetCollisionBody();

  if (body1 == std::nullopt || body2 == std::nullopt)
    return false;

  // check rect collision
  Rectangle bodyRect1 = body1.value(), bodyRect2 = body2.value();

  if (collision_matters)
    return CheckCollisionRecs(bodyRect1, bodyRect2) && e1.IsCollidable() &&
           e2.IsCollidable();
  else
    return CheckCollisionRecs(bodyRect1, bodyRect2);
}

bool Physics::EntityTouchesTile(Entity& entity, Rectangle tileBody)
{
  auto entityBody = entity.GetCollisionBody();

  if (entityBody == std::nullopt)
    return false;

  return CheckCollisionRecs(entityBody.value(), tileBody);
}

Rectangle Physics::MakeBodyFromTile(TileType tileType, Vector2 tilePosition)
{
  return {tilePosition.x, tilePosition.y, 16, 16};
}
