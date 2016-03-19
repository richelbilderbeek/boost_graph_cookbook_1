#include "set_graph_name.h"
#include "set_graph_name_demo.impl"


#include <boost/test/unit_test.hpp>


#include "create_empty_directed_graph_with_graph_name.h"
#include "get_graph_name.h"

BOOST_AUTO_TEST_CASE(set_graph_name_thorough)
{
  auto g = create_empty_directed_graph_with_graph_name();
  set_graph_name("Ralph", g);
  BOOST_CHECK(get_graph_name(g) == "Ralph");
  
}
