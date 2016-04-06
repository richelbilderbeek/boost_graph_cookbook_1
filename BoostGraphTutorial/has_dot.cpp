#include "has_dot.h"



#include <iostream>
#include <sstream>

#include "is_regular_file.h"
#include "copy_file.h"
#include "file_to_vector.h"

bool has_dot() noexcept
{
  std::stringstream cmd;
  cmd << "type dot > /dev/null";
  const auto error = std::system(cmd.str().c_str());
  const bool has_dot{error == 0};
  if (!has_dot) {
    std::cout << "Tip: type 'sudo apt-get install graphviz' in the command line" << std::endl;
  }
  return has_dot;
}
