#include "is_read_graphviz_correct.h"

#include <cassert>
#include <iostream>

#include "my_custom_edge.h"
#include "my_custom_vertex.h"

void is_read_graphviz_correct_test() noexcept
{
  assert(is_read_graphviz_correct<my_custom_edge>());
  assert(is_read_graphviz_correct<my_custom_vertex>());
  std::cout << __func__ << ": OK" << std::endl;
}
