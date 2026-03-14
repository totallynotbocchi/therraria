#include "World.hpp"
#include <print>
#include <raylib.h>
using namespace therraria;

World::World()
{
  m_Tiles.resize(WIDTH * HEIGHT);

  AddEntity(std::make_unique<Player>());

  Tile grass(TileType::Grass);
  PlaceTile({0.f, 30.f}, grass);
  PlaceTile({1.f, 30.f}, grass);
  PlaceTile({2.f, 30.f}, grass);
}

Tile& World::GetTile(Vector2 pos)
{
  return m_Tiles.at(WIDTH * pos.y + pos.x);
}

void World::PlaceTile(Vector2 pos, Tile& tile)
{
  m_Tiles[WIDTH * pos.y + pos.x] = tile;
}

void World::Load()
{
  m_AssetManager.LoadAll();
}

void World::Update()
{
  for (auto& entity : m_Entities)
  {
    m_Physics.ApplyGravityOnEntity(*entity);
    entity->Update();

    // slow as ass
    // TODO: make it only check ~9 tiles around the entity
    for (float i = 0; i < WIDTH; i++)
      for (float j = 0; j < HEIGHT; j++)
      {
        Tile& tile = GetTile({i, j});
        if (tile.type == TileType::Air)
          continue;

        Rectangle body = m_Physics.MakeBodyFromTile(tile.type, {16 * i, 16 * j});

        if (m_Physics.EntityTouchesTile(*entity, body))
        {
          entity->GetVelocity().y = 0;
          entity->GetPosition().y = body.y - 50; // NOTE: this might cause a bug later, 50
                                                 // is supposed to be the player height
        }
      }
  }
}

void World::Draw()
{
  // draw tiles
  // TODO: only render tiles in the view
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
      // get the tile
      Tile& tile = GetTile({(float)i, (float)j});

      // skip air
      if (tile.type == TileType::Air)
        continue;

      // get its texture data
      TextureID tid = TILE_DATA_TABLE[(int)tile.type].textureID;
      const Texture2D* texture = m_AssetManager.GetTexture(tid);

      if (texture == nullptr)
      {
        std::println("Texture not found for tile type '{}'.", (int)tile.type);
        continue;
      }

      // draw it
      DrawTexture(*texture, 16 * i, 16 * j, WHITE);
    }
  }

  // the player is above tiles
  m_Player->Draw();

  // draw debug data
  DrawText(std::format("FPS: {}", GetFPS()).c_str(), 10, 10, 25, GREEN);
  DrawText(std::format("Vel: ({}, {})\nPos: ({}, {})", m_Player->GetVelocity().x,
                       m_Player->GetVelocity().y, m_Player->GetPosition().x,
                       m_Player->GetPosition().y)
               .c_str(),
           10, 35, 25, GREEN);
}
