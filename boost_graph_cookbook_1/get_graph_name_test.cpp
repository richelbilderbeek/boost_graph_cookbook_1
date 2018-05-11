#include "get_graph_name.h"
#include "get_graph_name_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_directed_graph_with_graph_name.h"
#include "set_graph_name.h"

BOOST_AUTO_TEST_CASE(get_graph_name_thorough)
{
  auto g = create_empty_directed_graph_with_graph_name();
  const std::string name{"Dex"};
  set_graph_name(name, g);
  BOOST_CHECK(get_graph_name(g) == name);
}
