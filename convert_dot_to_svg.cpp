#include "convert_dot_to_svg.h"

#include <cassert>
#include <sstream>

#include "fileio.h"
#include "has_dot.h"
#include "is_valid_dot_file.h"

void convert_dot_to_svg(
  const std::string& dot_filename,
  const std::string& svg_filename
)
{
  assert(has_dot());
  assert(is_valid_dot_file(dot_filename));
  std::stringstream cmd;
  cmd << "dot -Tsvg " << dot_filename << " -o " << svg_filename;
  std::system(cmd.str().c_str());
  assert(ribi::FileIo().IsRegularFile(svg_filename));
}
