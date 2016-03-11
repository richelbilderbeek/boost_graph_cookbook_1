#include "convert_svg_to_png.h"

#include <cassert>
#include <sstream>
#include "is_regular_file.h"

void convert_svg_to_png(
  const std::string& svg_filename,
  const std::string& png_filename
) noexcept
{
  assert(is_regular_file(svg_filename));
  std::stringstream s;
  s << "convert " << svg_filename << " " << png_filename;
  const int error {
    std::system(s.str().c_str())
  };
  assert(!error);
  assert(is_regular_file(png_filename));
}
