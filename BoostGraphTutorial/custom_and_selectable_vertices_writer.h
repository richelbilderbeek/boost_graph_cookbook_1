#ifndef CUSTOM_AND_SELECTABLE_VERTICES_WRITER_H
#define CUSTOM_AND_SELECTABLE_VERTICES_WRITER_H

#include <ostream>

///A vertex writer that stores a custom
///vertex type map as a Graphviz 'label', and an
///is_selected_map as the Graphviz 'regular'
///property
template <
  typename my_custom_vertex_map,
  typename is_selected_map
>
class custom_and_selectable_vertices_writer {
public:
  custom_and_selectable_vertices_writer(
    my_custom_vertex_map any_my_custom_vertex_map,
    is_selected_map any_is_selected_map
  ) : m_my_custom_vertex_map{any_my_custom_vertex_map},
      m_is_selected_map{any_is_selected_map}
  {

  }
  template <class vertex_descriptor>
  void operator()(
    std::ostream& out,
    const vertex_descriptor& vd
  ) const noexcept {
    out << "[label=\"" << m_my_custom_vertex_map[vd]
      << "\", regular=\"" << m_is_selected_map[vd]
      << "\"]"
    ;
  }
private:
  my_custom_vertex_map m_my_custom_vertex_map;
  is_selected_map m_is_selected_map;
};

#endif // CUSTOM_AND_SELECTABLE_VERTICES_WRITER_H
