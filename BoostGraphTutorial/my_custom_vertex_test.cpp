#include "my_custom_vertex.h"
//#include "my_custom_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include <sstream>
#include <boost/lexical_cast.hpp>
#include "file_to_vector.h"
#include "seperate_string.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"

BOOST_AUTO_TEST_CASE(my_custom_vertex_thorough)
{
  //Conversion to string
  {
    const my_custom_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    const std::string t{s.str()};
    BOOST_CHECK(t.find(' ') == std::string::npos);
    BOOST_CHECK(std::count(std::begin(t),std::end(t),',') == 3);
  }
  //Conversion to stream and back
  {
    const my_custom_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    my_custom_vertex out;
    s >> out;
    BOOST_CHECK(in == out);
  }
  //Conversion of two my_custom_vertex-es to stream and back
  {
    const my_custom_vertex a("A B","c d",1.0,2.0);
    const my_custom_vertex b("C","d",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_custom_vertex c;
    my_custom_vertex d;
    s >> c >> d;
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == d);
  }
  
}

