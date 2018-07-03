#include "copy_file.h"

#include <cassert>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "is_regular_file.h"

void copy_file(const std::string& filename_from, const std::string& filename_to,
  const copy_file_mode copy_mode)
{
  if (!is_regular_file(filename_from)) {
    std::stringstream msg;
    msg << __func__ << ": "
        << "cannot copy a non-existing file, "
        << "filename supplied was '" << filename_from << "'";
    throw std::invalid_argument(msg.str());
  }
  if (copy_mode == copy_file_mode::prevent_overwrite
    && is_regular_file(filename_to)) {
    std::stringstream msg;
    msg << __func__ << ": "
        << "Copying to existing file '" << filename_to << "'is not allowed, "
        << "use copy_file_mode::allow_overwrite if you really want to";
    throw std::invalid_argument(msg.str());
  }
  if (is_regular_file(filename_to)) {
    std::remove(filename_to.c_str());
    assert(!is_regular_file(filename_to));
  }
  std::ifstream in{ filename_from };
  std::ofstream out{ filename_to };
  out << in.rdbuf();
  out.close();
  in.close();
}
