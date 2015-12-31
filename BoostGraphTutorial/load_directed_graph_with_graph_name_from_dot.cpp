#include "load_directed_graph_with_graph_name_from_dot.h"

#include "load_directed_graph_with_graph_name_from_dot.impl"

#include "load_directed_graph_with_graph_name_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_markov_chain_with_graph_name.h"
#include "convert_dot_to_svg.h"
#include "helper.h"
#include "set_graph_name.h"

void load_directed_graph_with_graph_name_from_dot_test() noexcept
{
  //Create the picture 'load_directed_graph_with_graph_name_from_dot_test_markov_chain.svg'
  {
    auto g = create_empty_directed_graph_with_graph_name();
    //const auto g = create_markov_chain_with_graph_name();
    const std::string base_filename{"create_empty_directed_graph_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    set_graph_name("TestGraph", g);
    assert(get_graph_name(g) == "TestGraph");
    save_graph_with_graph_name_to_dot(g, dot_filename);
    const auto h = load_directed_graph_with_graph_name_from_dot(dot_filename);
    assert(get_graph_name(g) == get_graph_name(h));
    convert_dot_to_svg(dot_filename, svg_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  load_directed_graph_with_graph_name_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
