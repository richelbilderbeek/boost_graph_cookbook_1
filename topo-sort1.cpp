//Modified from Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Pages 15-18
#include <cassert>
#include <iostream>
#include <vector>
#include <boost/graph/vector_as_graph.hpp>
#include <boost/graph/topological_sort.hpp>

int main()
{
  //Adapted from 15b
  const std::vector<std::string> tasks{
    "0. pick up kids from school",
    "1. buy groceries (and snacks)",
    "2. get cash at ATM",
    "3. drop off kids at soccer practice",
    "4. cook dinner",
    "5. pick up kids from soccer",
    "6. eat dinner"
  };

  //Adapted from 15c
  const std::vector<std::vector<int>> g{
    {3},   //[0] Need to pick up kids before dropping them off at soccer practice
    {3,4}, //[1] Need to buy groceries (and snacks) before dropping kids off at soccer practice and before cooking dinner
    {1},   //[2] Need cash from ATM to buy groceries (and snacks)
    {5},   //[3] Need to drop off kids at soccer practice before picking them up
    {6},   //[4] Need to cook dinner before eating it (with the kids)
    {6},   //[5] Need to pick up kids from soccer before eating it (with the kids)
    {}     //[6] Need to eat dinner to do ... nothing!
  };

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
