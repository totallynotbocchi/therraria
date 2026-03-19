#pragma once

#include <format>
#include <print>

namespace therraria
{

struct Logger
{
  std::string path = "log.txt"; // TODO: use this file lol

  template <typename... Args> static void Info(std::string fmt, Args&&... args)
  {
    std::println("[\033[36mINFO\033[0m] {}",
                 std::vformat(fmt, std::make_format_args(args...)));
  }

  template <typename... Args> static void Warn(std::string fmt, Args&&... args)
  {
    std::println("[\033[33mWARN\033[0m] {}",
                 std::vformat(fmt, std::make_format_args(args...)));
  }

  template <typename... Args> static void Err(std::string fmt, Args&&... args)
  {
    std::println("[\033[31mError\033[0m] {}",
                 std::vformat(fmt, std::make_format_args(args...)));
  }
};

} // namespace therraria
