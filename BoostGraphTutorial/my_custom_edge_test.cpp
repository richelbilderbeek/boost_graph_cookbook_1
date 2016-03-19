#include "my_custom_edge.h"
//#include "my_custom_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include <sstream>
#include <boost/test/unit_test.hpp>

#include <boost/lexical_cast.hpp>

#include "helper.h"
#include "seperate_string.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"

BOOST_AUTO_TEST_CASE(my_custom_edge_thorough)
{
  {
    const my_custom_edge a("A B","c d",1.0,2.0);
    const my_custom_edge b{a};
    BOOST_CHECK(a == b);
  }
  //Conversion to string
  {
    const my_custom_edge in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    const std::string t{s.str()};
    BOOST_CHECK(t.find(' ') == std::string::npos);
    BOOST_CHECK(std::count(std::begin(t),std::end(t),',') == 3);
  }
  //Conversion to stream and back
  {
    const my_custom_edge in("AB","cd",1.0,2.0);
    std::stringstream s;
    s << in;
    my_custom_edge out;
    s >> out;
    BOOST_CHECK(in == out);
  }
  //Conversion of two my_custom_edges to stream and back
  {
    const my_custom_edge a("AB","cd",1.0,2.0);
    const my_custom_edge b("C D","d e",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_custom_edge c;
    my_custom_edge d;
    s >> c >> d;
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == d);
  }
  
}
