#pragma once

#include "../pch.hpp"
#include <raylib.h>
#include <unordered_map>

namespace therraria
{

enum class TextureID : uint8_t
{
  None,
  Grass
};

class AssetManager
{
  std::unordered_map<TextureID, Texture2D> m_Textures;

public:
  AssetManager() = default;
  ~AssetManager();

  void LoadAll();

  void AddTexture(TextureID id, const char* path);
  void AddTexture(TextureID id, Texture2D texture);
  Texture2D* GetTexture(TextureID id);
};

} // namespace therraria
