#pragma once

#include "../Entity/Entity.hpp"
#include "../World/Tile/Tile.hpp"
#include "pch.hpp"
#include <raylib.h>

namespace therraria
{

// the physics "engine"
class Physics
{
  uint16_t m_Gravity = 20;

public:
  explicit Physics(uint16_t gravity);
  Physics() = default;

  // entity methods
  void ApplyGravityOnEntity(Entity& entity);
  void ResolveEntityTileCollision(Entity& entity, Tile& tile, Vector2& tilePos);

  bool EntityTouchesTile(Entity& entity, Rectangle tileBody);
  // TODO: rename the function below (maybe)
  bool EntitiesTouch(Entity& e1, Entity& e2,
                     bool collision_matters); // TODO: rename maybe

  // tile methods
  Rectangle MakeBodyFromTile(TileType tileType, Vector2 tilePosition);
};

} // namespace therraria
