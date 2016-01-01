#include "get_graph_name.h"

#include "get_graph_name_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_directed_graph_with_graph_name.h"
#include "set_graph_name.h"

void get_graph_name_test() noexcept
{
  auto g = create_empty_directed_graph_with_graph_name();
  const std::string name{"Dex"};
  set_graph_name(name, g);
  assert(get_graph_name(g) == name);
  get_graph_name_demo();
  
}
