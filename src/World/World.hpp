#pragma once

#include "../Asset/Manager.hpp"
#include "../Entity/Player/Player.hpp"
#include "../Physics/Physics.hpp"
#include "../pch.hpp"
#include "Tile/Tile.hpp"
#include <concepts>
#include <type_traits>

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

  World();
  World(const World&) = delete;
  World& operator=(const World&) = delete;

  Tile& GetTile(Vector2 pos);
  void PlaceTile(Vector2 pos, Tile& tile);

  template <std::derived_from<Entity> T> void AddEntity(std::unique_ptr<T> entity)
  {
    m_Entities.push_back(std::move(entity));

    // update the current player reference if we are adding a player
    if (std::is_same_v<T, Player>)
      m_Player = static_cast<Player*>(m_Entities.back().get());
  }

  void Load();
  void Update();
  void Draw();
};

} // namespace therraria
