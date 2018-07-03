#include "get_graph_text.h"
#include "get_graph_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_directed_graph_with_graph_text.h"
#include "set_graph_text.h"

BOOST_AUTO_TEST_CASE(get_graph_text_thorough)
{
  auto g = create_empty_directed_graph_with_graph_text();
  const std::string text{"Dex"};
  set_graph_text(text, g);
  BOOST_CHECK(get_graph_text(g) == text);
}
