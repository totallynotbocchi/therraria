#pragma once

#include "../Asset/Manager.hpp"
#include "../Entity/Player/Player.hpp"
#include "../Physics/Physics.hpp"
#include "../pch.hpp"
#include "Tile/Tile.hpp"
#include <raylib.h>

namespace therraria
{
class World
{
  // NOTE: this member is a dynamic vector cus world size will be dynamic later
  std::vector<Tile> m_Tiles;

  std::vector<std::unique_ptr<Entity>> m_Entities;

  Player* m_Player;
  AssetManager m_AssetManager;
  Physics m_Physics;

public:
  static constexpr int WIDTH = 100;
  static constexpr int HEIGHT = 300;
  static constexpr int PIXEL_SCALE = 16;
  static constexpr int TILE_NEIGHBORS = 8;

  World();
  World(const World&) = delete;
  World& operator=(const World&) = delete;

  Tile& GetTile(Vector2 pos);
  void PlaceTile(Vector2 pos, Tile& tile);

  Vector2 ToWorldCoords(Vector2 v) const;
  Vector2 ClampToWorldSize(Vector2 v) const;

  template <std::derived_from<Entity> T> void AddEntity(std::unique_ptr<T> entity)
  {
    m_Entities.push_back(std::move(entity));

    // update the current player reference if we are adding a player
    // TODO: find a cleaner implementation
    if constexpr (std::is_same_v<T, Player>)
      m_Player = static_cast<Player*>(m_Entities.back().get());
  }

  void Load();
  void Clean();
  void Update();
  void Draw();
};

} // namespace therraria
