#include "is_graphviz_friendly.h"
#include "is_graphviz_friendly.impl"

#include <cassert>

void is_graphviz_friendly_test() noexcept
{
  assert( is_graphviz_friendly("abcdef"));
  assert(!is_graphviz_friendly("ab< \" \\ cd$ef"));
}
