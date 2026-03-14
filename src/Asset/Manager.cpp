#include "Manager.hpp"
#include <cassert>
#include <raylib.h>

using namespace therraria;

AssetManager::~AssetManager()
{
  // unload all assets

  for (std::pair<TextureID, Texture2D> entry : m_Textures)
    UnloadTexture(entry.second);
}

void AssetManager::LoadAll()
{
  AddTexture(TextureID::Grass, "assets/textures/grass.png");
}

void AssetManager::AddTexture(TextureID id, const char* path)
{
  std::println("Loading texture from path...");

  // safely load texture
  Texture2D texture = LoadTexture(path);
  assert(IsTextureValid(texture));

  // place it if the id is unused
  m_Textures.emplace(id, texture);
  std::println("Loaded!");
}

void AssetManager::AddTexture(TextureID id, Texture2D texture)
{
  std::println("Loading texture from object...");

  // check if the texture is loaded
  assert(IsTextureValid(texture));

  // place it jf the id is unused
  m_Textures.emplace(id, texture);
  std::println("Loaded!");
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
