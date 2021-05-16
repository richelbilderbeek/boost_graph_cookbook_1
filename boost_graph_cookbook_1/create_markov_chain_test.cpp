#include "create_markov_chain.h"
#include "create_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "save_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_markov_chain_basic)
{
  // Basic tests
  {
    const auto g = create_markov_chain();
    BOOST_CHECK(boost::num_edges(g) == 4);
    BOOST_CHECK(boost::num_vertices(g) == 2);

  }
}
