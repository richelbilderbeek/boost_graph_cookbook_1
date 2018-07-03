#include "convert_svg_to_png.h"

#include "is_regular_file.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>

void convert_svg_to_png(
  const std::string& svg_filename, const std::string& png_filename)
{
  if (!is_regular_file(svg_filename)) {
    std::stringstream msg;
    msg << __func__ << ": "
        << "input SVG file with name '" << svg_filename << "' not found";
    throw std::invalid_argument(msg.str());
  }
  std::stringstream s;
  s << "convert " << svg_filename << " " << png_filename;
  const int error{ std::system(s.str().c_str()) };
  if (error) {
    std::stringstream msg;
    msg << __func__ << ": command '" << s.str() << "' resulting in error "
        << error;
    throw std::runtime_error(msg.str());
  }
  if (!is_regular_file(png_filename)) {
    std::stringstream msg;
    msg << __func__ << ": command '" << s.str() << "' did not results in "
        << "a PNG file with filename '" << png_filename << "'";
    throw std::runtime_error(msg.str());
  }
}
