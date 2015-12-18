#ifndef SAVE_GRAPH_WITH_GRAPH_NAME_TO_DOT_H
#define SAVE_GRAPH_WITH_GRAPH_NAME_TO_DOT_H

#if __cplusplus >= 201402L //C++14
#include "save_graph_with_graph_name_to_dot_cpp14.impl"
#else
#include "save_graph_with_graph_name_to_dot_cpp11.impl"
#endif

void save_graph_with_graph_name_to_dot_test() noexcept;

#endif // SAVE_GRAPH_WITH_GRAPH_NAME_TO_DOT_H
