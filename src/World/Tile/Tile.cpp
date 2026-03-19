#include "Tile.hpp"
using namespace therraria;

Tile::Tile(TileType type)
    : type(type)
    , health(GetFromDataTable(type).maxHealth)
{
}

TileData Tile::GetFromDataTable(TileType type)
{
  therr_assert(int(type) < std::size(TILE_DATA_TABLE),
               std::format("Tile '{}' type not defined.", (int)type));

  return TILE_DATA_TABLE[int(type)];
}
