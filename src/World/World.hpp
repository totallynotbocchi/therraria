#pragma once

#include "../Asset/Manager.hpp"
#include "../Physics/Physics.hpp"
#include "../Player/Player.hpp"
#include "Tile/Tile.hpp"
#include "pch.hpp"

namespace therraria
{

class World
{
  // NOTE: this member is a dynamic vector cus world size will be dynamic later
  std::vector<Tile> m_Tiles;

  Player m_Player;
  AssetManager m_AssetManager;
  Physics m_Physics;

public:
  static constexpr int WIDTH = 10;
  static constexpr int HEIGHT = 10;

  World();

  Tile& GetTile(Vector2 pos);
  void PlaceTile(Vector2 pos, Tile& tile);

  void Update(float dt);
  void Draw();
};

} // namespace therraria
