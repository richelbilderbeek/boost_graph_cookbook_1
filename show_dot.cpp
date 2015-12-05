#include "show_dot.h"

#include <sstream>

void show_dot(const std::string& filename)
{
  std::stringstream cmd;
  cmd << "kgraphviewer " << filename;
  std::system(cmd.str().c_str());
}

