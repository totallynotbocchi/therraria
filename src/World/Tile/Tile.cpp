#include "Tile.hpp"
#include <raylib.h>
using namespace therraria;

Tile::Tile(TileType type)
    : type(type)
    , health(TILE_DATA_TABLE[(int)type].maxHealth)
{
}
