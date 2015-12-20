#include "copy_file.h"

#include <cassert>
#include <stdexcept>
#include <fstream>

#include "is_regular_file.h"

void copy_file(
  const std::string& filename_from,
  const std::string& filename_to,
  const copy_file_mode copy_mode
)
{
  assert(is_regular_file(filename_from) && "Cannot copy a non-existing file");
  if (copy_mode == copy_file_mode::prevent_overwrite && is_regular_file(filename_to))
  {
    throw std::logic_error("Copying to an existing file is not allowed");
  }
  if (is_regular_file(filename_to))
  {
    std::remove(filename_to.c_str());
    assert(!is_regular_file(filename_to));
  }
  std::ifstream in{filename_from.c_str()};
  std::ofstream out{filename_to.c_str()};
  out << in.rdbuf();
  out.close();
  in.close();
}
