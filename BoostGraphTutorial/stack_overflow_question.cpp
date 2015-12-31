#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <cassert>
#include <fstream>
#include <string>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::no_property,
  boost::no_property,
  boost::property<boost::graph_name_t,std::string>
>
create_empty_directed_graph_with_graph_name() noexcept
{
  return {};
}

template <typename graph>
void set_graph_name(const std::string& name, graph& g) noexcept
{
  get_property(g, boost::graph_name) = name;
}

template <typename graph>
std::string get_graph_name(const graph& g) noexcept
{
  return get_property(g, boost::graph_name
  );
}

template <typename graph>
void save_graph_with_graph_name_to_dot(
  const graph& g, const std::string& filename
)
{
  std::ofstream f(filename);
  boost::write_graphviz(
    f,
    g,
    boost::default_writer(),
    boost::default_writer(),
    //Unsure if this results in a graph that can be loaded correctly from a .dot file
    [g](std::ostream& os) {
      os << "name=\""
        << get_graph_name(g)
        << "\";\n";
    }
  );
}

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::no_property,
  boost::no_property,
  boost::property<boost::graph_name_t, std::string>
>
load_directed_graph_with_graph_name_from_dot(
  const std::string& dot_filename
)
{
  std::ifstream f(dot_filename.c_str());
  auto g = create_empty_directed_graph_with_graph_name();

  //#define TODO_KNOW_HOW_TO_LOAD_A_GRAPH_ITS_NAME
  #ifdef TODO_KNOW_HOW_TO_LOAD_A_GRAPH_ITS_NAME
  boost::dynamic_properties p;
  p.property("name",get_property(g,boost::graph_name)); //AFAIK, this should work
  #else
  boost::dynamic_properties p(
    boost::ignore_other_properties
  );
  #endif
  boost::read_graphviz(f,g,p);
  return g;
}

int main()
{
  const std::string dot_filename{"test.dot"};
  auto g = create_empty_directed_graph_with_graph_name();
  set_graph_name("TestGraph", g);
  save_graph_with_graph_name_to_dot(g, dot_filename);
  const auto h = load_directed_graph_with_graph_name_from_dot(dot_filename);
  assert(get_graph_name(g) == get_graph_name(h));
}
