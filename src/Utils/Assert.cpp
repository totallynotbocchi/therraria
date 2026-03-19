#include "Assert.hpp"
using namespace therraria;

void therraria::therr_assert(bool cond, std::string_view msg, std::source_location loc)
{
  if (!cond)
  {
    std::println("[ASSERT FAILED] {} (at {}:{})", msg, loc.file_name(), loc.line());
    __builtin_trap(); // raise SIGILL
  }
}
