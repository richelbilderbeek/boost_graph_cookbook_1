#include "get_sorted_vertex_names.h"

#include "create_named_vertices_path_graph.h"

void get_sorted_vertex_names_test() noexcept
{
  const auto g = create_named_vertices_path_graph(
    {"F", "B", "A", "C", "E", "D"}
  );
  const std::vector<std::string> expected{
    "A", "B", "C", "D", "E", "F"
  };
  const auto found = get_sorted_vertex_names(g);
  assert(found == expected);
}
