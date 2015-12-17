#include "is_read_graphviz_correct.h"

#include <cassert>
#include <iostream>

#include "my_vertex.h"

void is_read_graphviz_correct_test() noexcept
{
  assert(is_read_graphviz_correct<my_vertex>());
  std::cout << __func__ << ": DONE" << std::endl;
}
