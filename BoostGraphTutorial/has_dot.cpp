#include "has_dot.h"

#include <iostream>
#include <sstream>

bool has_dot() noexcept
{
  std::stringstream cmd;
  cmd << "type dot > /dev/null";
  const auto error = std::system(cmd.str().c_str());
  const bool has_dot{error == 0};
  if (!has_dot) {
    std::cout << "Tip: type 'sudo apt-get install graphviz' in the command line\n";
  }
  return has_dot;
}
