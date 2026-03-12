#include "Manager.hpp"
#include <cassert>
#include <format>
#include <raylib.h>
#include <stdexcept>

using namespace therraria;

AssetManager::AssetManager() {}

AssetManager::~AssetManager()
{
  // unload all assets

  for (auto& pair : m_Textures)
    UnloadTexture(pair.second);
}

void AssetManager::LoadAll()
{
  AddTexture(TextureID::Grass, "assets/textures/grass.png");
}

void AssetManager::AddTexture(TextureID id, const char* path)
{
  // safely load texture
  Texture2D texture = LoadTexture(path);
  assert(IsTextureValid(texture));

  m_Textures.emplace(id, texture);
}

void AssetManager::AddTexture(TextureID id, Texture2D& texture)
{
  assert(IsTextureValid(texture));

  m_Textures.emplace(id, texture);
}

Texture2D* AssetManager::GetTexture(TextureID id)
{
  try
  {
    return &m_Textures.at(id);
  }
  catch (std::out_of_range)
  {
    return nullptr;
  }
}
