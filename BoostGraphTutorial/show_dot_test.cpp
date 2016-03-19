#include "show_dot.h"

#include <stdexcept>
#include <sstream>

void show_dot(const std::string& filename)
{
  std::stringstream cmd;
  cmd << "kgraphviewer " << filename;
  const int error {
    std::system(cmd.str().c_str())
  };
  if (error)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot find 'kgraphviewer'";
    throw std::runtime_error(msg.str());
  }
}

