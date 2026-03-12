#include "World.hpp"
#include <raylib.h>
using namespace therraria;

World::World()
    : m_Player(Player())
{
  m_Tiles.resize(WIDTH * HEIGHT);

  Tile grass(TileType::Grass);
  PlaceTile({0.f, 0.f}, grass);

  m_AssetManager.LoadAll();
}

Tile& World::GetTile(Vector2 pos)
{
  return m_Tiles.at(WIDTH * pos.x + pos.y);
}

void World::PlaceTile(Vector2 pos, Tile& tile)
{
  m_Tiles[WIDTH * pos.x + pos.y] = tile;
}

void World::Update(float dt)
{
  m_Player.Update(dt);
}

void World::Draw()
{
  m_Player.Draw();

  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; i < HEIGHT; j++)
    {
      // get the tile
      Tile& tile = GetTile({(float)i, (float)j});

      // get its texture data
      TextureID id = TILE_DATA_TABLE[(int)tile.type].textureID;
      Texture2D* texture = m_AssetManager.GetTexture(id);

      // draw it
      DrawTexture(*texture, i, j, WHITE);
    }
  }
}
