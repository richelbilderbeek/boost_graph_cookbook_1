#include "graphviz_encode.h"

#include "graphviz_encode.impl"

#include <boost/test/unit_test.hpp>

#include "graphviz_decode.h"

BOOST_AUTO_TEST_CASE(graphviz_encode_thorough)
{
  //Graphviz encoding
  {
    for (const auto s:
      {
        "A", "ABCDEFGHIJKLMN",
        "A B", " A B ", "  A  B  ", //Spaces
        "A\"B", "\"A\"B\"", "\"\"A\"\"B\"\"", //Quotes
        "A\\B", "\\A\\B\\", "\\\\A\\\\B\\\\", //Backslash
        "A,B", ",A,B,", ",,A,,B,," //Comma
      }
    )
    {
      const auto t = graphviz_encode(s);
      const auto u = graphviz_decode(t);
      BOOST_CHECK(s == u);
    }
  }
  
}
