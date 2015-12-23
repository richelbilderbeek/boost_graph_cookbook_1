#include "graphviz_encode.h"

#include "graphviz_encode.impl"

#include <cassert>
#include "graphviz_decode.h"

void graphviz_encode_test() noexcept
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
      assert(s == u);
    }
  }
  std::cout << __func__ << ": OK" << '\n';
}
