#include "World.hpp"
#include "World/Tile/Tile.hpp"
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
  PlaceTile({2.f, 31.f}, grass);
  PlaceTile({2.f, 32.f}, grass);
}

void World::Clean()
{
  m_AssetManager.Unload();
  m_Entities.clear();
  m_Tiles.clear();
}

Tile& World::GetTile(Vector2 pos)
{
  return m_Tiles.at(WIDTH * pos.y + pos.x);
}

void World::PlaceTile(Vector2 pos, Tile& tile)
{
  m_Tiles[WIDTH * pos.y + pos.x] = tile;
}

Vector2 World::ToWorldCoords(Vector2 v) const
{
  return {v.x / PIXEL_SCALE, v.y / PIXEL_SCALE};
}

Vector2 World::ClampToWorldSize(Vector2 v) const
{
  return {std::clamp(v.x, 0.f, (float)WIDTH * PIXEL_SCALE),
          std::clamp(v.y, 0.f, (float)HEIGHT * PIXEL_SCALE)};
}

void World::Load()
{
  m_AssetManager.LoadAll();
}

void World::Update()
{
  for (auto& entity : m_Entities)
  {
    m_Physics.ApplyGravity(*entity);
    entity->GetPosition() = ClampToWorldSize(entity->GetPosition());
    entity->Update();

    // skip entities early if they dont collide to avoid useless checks
    if (!entity->IsCollidable())
      continue;

    // FIX: ts broken
    Vector2 scaledEntityPos = ToWorldCoords(entity->GetPosition());
    for (float i = scaledEntityPos.x - TILE_NEIGHBORS;
         i < scaledEntityPos.x + TILE_NEIGHBORS; i++)
    {

      for (float j = scaledEntityPos.y - TILE_NEIGHBORS;
           j < scaledEntityPos.y + TILE_NEIGHBORS; j++)
      {
        Tile& tile = GetTile({i, j});
        Vector2 tilePos = {PIXEL_SCALE * i, PIXEL_SCALE * j};

        m_Physics.ResolveTileCollision(*entity, tile, tilePos);
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

      // skip air SPECIFICALLY since its the most basic case
      if (tile.type == TileType::Air)
        continue;

      // get its texture data
      TextureID tid = Tile::GetFromDataTable(tile.type).textureID;

      // skip when it has no texture
      if (tid == TextureID::None)
        continue;

      // load the object
      const Texture2D* texture = m_AssetManager.GetTexture(tid);
      if (texture == nullptr)
      {
        std::println("Texture not found for tile type '{}'.", (int)tile.type);
        continue;
      }

      // draw it
      DrawTexture(*texture, PIXEL_SCALE * i, PIXEL_SCALE * j, WHITE);
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
