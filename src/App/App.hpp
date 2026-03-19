#pragma once

#include "../World/World.hpp"
#include "../pch.hpp"

namespace therraria
{

class App
{
  World m_World;

public:
  App();
  ~App();

  void Run();
};

} // namespace therraria
