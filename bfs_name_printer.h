#ifndef BFS_NAME_PRINTER_H
#define BFS_NAME_PRINTER_H

#include <iostream>
#include <boost/graph/breadth_first_search.hpp>

//Breadth-first searching visitor
//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 11
template <typename VertexNameMap>
class bfs_name_printer
  : public boost::default_bfs_visitor { // in boost/graph/breadth_first_search.hpp
public:
  bfs_name_printer(VertexNameMap n_map) : m_name_map{n_map} { }

  template <typename Vertex, typename Graph>
  void discover_vertex(Vertex u, const Graph&) const { //Why the second argument?
    std::cout << get(m_name_map, u) << ' ';
  }

private:
  VertexNameMap m_name_map;
};

void test_bfs_name_printer() noexcept;

#endif // BFS_NAME_PRINTER_H
