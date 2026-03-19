#pragma once

#include <source_location>

namespace therraria
{

void therr_assert(bool cond, std::string_view msg,
                  std::source_location loc = std::source_location::current());
}
