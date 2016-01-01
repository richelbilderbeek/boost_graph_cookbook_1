#include "set_graph_name.h"

#include "set_graph_name_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_directed_graph_with_graph_name.h"
#include "get_graph_name.h"

void set_graph_name_test() noexcept
{
  auto g = create_empty_directed_graph_with_graph_name();
  set_graph_name("Ralph", g);
  assert(get_graph_name(g) == "Ralph");
  set_graph_name_demo();
  
}
