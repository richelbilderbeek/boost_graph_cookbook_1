#ifndef CONVERT_DOT_TO_SVG_H
#define CONVERT_DOT_TO_SVG_H

#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
#include <string>

void convert_dot_to_svg(
  const std::string& dot_filename,
  const std::string& svg_filename
);
#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

#endif // CONVERT_DOT_TO_SVG_H
