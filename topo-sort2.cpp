//Modified from Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Pages 15-18
#include <cassert>
#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>

int main()
{
  const std::vector<std::string> tasks{
    "0. pick up kids from school",
    "1. buy groceries (and snacks)",
    "2. get cash at ATM",
    "3. drop off kids at soccer practice",
    "4. cook dinner",
    "5. pick up kids from soccer",
    "6. eat dinner"
  };


  boost::adjacency_list<boost::listS,boost::vecS,boost::directedS> g{
    tasks.size()
  };

  boost::add_edge(0, 3, g);
  boost::add_edge(1, 3, g);
  boost::add_edge(1, 4, g);
  boost::add_edge(2, 1, g);
  boost::add_edge(3, 5, g);
  boost::add_edge(4, 6, g);
  boost::add_edge(5, 6, g);

  //boost::topological_sort first spawns the things that needs to be done last
  std::vector<int> topo_order;
  boost::topological_sort(
    g,
    std::back_inserter(topo_order),
    vertex_index_map(boost::identity_property_map())
  );
  //Reverse the order
  std::reverse(std::begin(topo_order),std::end(topo_order));

  const std::vector<int> topo_order_expected = {2, 1, 4, 0, 3, 5, 6};
  assert(topo_order == topo_order_expected);

  //Displays the tasks
  for (const int i: topo_order) {
    std::cout << tasks[i] << '\n';
  }
}

/* Screen output:

2. get cash at ATM
1. buy groceries (and snacks)
4. cook dinner
0. pick up kids from school
3. drop off kids at soccer practice
5. pick up kids from soccer
6. eat dinner
Press <RETURN> to close this window...

*/
