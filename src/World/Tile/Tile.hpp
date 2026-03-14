#pragma once

#include "../../Asset/Manager.hpp"
#include "pch.hpp"

namespace therraria
{

enum class TileType : uint8_t
{
  Air,
  Grass
};

// instead of each tile storing its data, use a data table
struct TileData
{
  bool transparent;
  bool solid;
  uint32_t maxHealth;
  TextureID textureID;
};

// WARNING: this might not compile on MSVC
constexpr TileData TILE_DATA_TABLE[] = {
    [(int)TileType::Air] = {true, false, 0, TextureID::None},
    [(int)TileType::Grass] = {false, true, 30, TextureID::Grass}};

struct Tile
{
  TileType type = TileType::Air;
  uint16_t health = 0;

  // methods

  Tile() = default;
  explicit Tile(TileType type);
};

} // namespace therraria
