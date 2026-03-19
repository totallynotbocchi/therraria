#include "Manager.hpp"
using namespace therraria;

void AssetManager::Unload()
{
  Logger::Info("Unloading textures...");

  for (std::pair<TextureID, Texture2D> entry : m_Textures)
    UnloadTexture(entry.second);
}

void AssetManager::LoadAll()
{
  AddTexture(TextureID::Grass, "assets/textures/grass.png");
}

void AssetManager::AddTexture(TextureID id, const char* path)
{
  Logger::Info("Loading texture from path...");

  // safely load texture
  Texture2D texture = LoadTexture(path);
  therr_assert(IsTextureValid(texture),
               std::format("Invalid texture from path '{}'.", path));

  if (!IsTextureValid(texture))
  {
    Logger::Err("Failed to load texture from path '{}'.", path);
    return;
  }

  // place it if the id is unused
  m_Textures.emplace(id, texture);
  Logger::Info("Loaded!");
}

void AssetManager::AddTexture(TextureID id, Texture2D texture)
{
  Logger::Info("Loading texture from object...");

  // check if the texture is loaded
  therr_assert(
      IsTextureValid(texture),
      std::format("Invalid texture from object with OpenGL ID '{}'.", texture.id));

  // place it jf the id is unused
  m_Textures.emplace(id, texture);
  Logger::Info("Loaded!");
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
