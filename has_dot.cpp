#include "has_dot.h"

#include <cassert>
#include <sstream>

#include "fileio.h"

bool has_dot() noexcept
{
  const std::string filename{"tmp_has_dot.txt"};
  std::stringstream cmd;
  cmd << "dot -? > " << filename;
  std::system(cmd.str().c_str());
  assert(ribi::FileIo().IsRegularFile(filename));
  const auto v = ribi::FileIo().FileToVector(filename);
  return v.size() > 1;
}
