#ifndef COUNT_MAX_NUMBER_OF_PIECES_H
#define COUNT_MAX_NUMBER_OF_PIECES_H

#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include "get_bits.h"
#include "remove_nth_vertex.h"
#include "count_undirected_graph_connected_components.h"

///Imagine shooting the vertices of a graph
///How many connected components can you maximally get?
///Examples:
/// A             can only be one piece
/// A--B          can only be one piece
/// A--B--C       can be shot to A C and thus two pieces
/// A--B--C--D    can be shot to 'A C--D', or 'A--B D', or 'A C' or 'A D' or 'B D' and thus two pieces
/// A--B--C--D--E can be shot to 'A C E' and thus three pieces
template <typename graph>
int count_max_number_of_pieces(
  const graph& g
)
{
  const int sz{static_cast<int>(boost::num_vertices(g))};
  if (sz <= 1) { return sz; }

  int max_connected_components{1};
  //Brute force starts here
  const int n_combinations{1 << sz};
  for (int i=0; i!=n_combinations; ++i)
  {
    //Copy the original graph
    graph h{g};

    //Delete vertices according to combinator
    std::vector<int> bits = get_bits(i);
    std::reverse(std::begin(bits), std::end(bits));
    assert(bits.size() < 2 || bits[0] > bits[1]); //Indices must be big first
    for (const int index: bits)
    {
      remove_nth_vertex(index, h);
    }

    //Count the number of connected components
    max_connected_components = std::max(
      max_connected_components,
      count_undirected_graph_connected_components(h)
    );
  }
  return max_connected_components;

}


#endif // COUNT_MAX_NUMBER_OF_PIECES_H
