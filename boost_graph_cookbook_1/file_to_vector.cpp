#include "file_to_vector.h"

#include <algorithm>
#include <cassert>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "is_regular_file.h"

std::vector<std::string> file_to_vector(
  const std::string& filename
)
{
  if (!is_regular_file(filename))
  {
    std::stringstream msg;
    msg << __func__ << ": file '"
      << filename << "' not found"
    ;
    throw std::invalid_argument(msg.str());
  }
  std::vector<std::string> v;
  std::ifstream in{filename};
  assert(in.is_open());
  for (int i=0; !in.eof(); ++i)
  {
    std::string s;
    std::getline(in,s);
    v.emplace_back(s); //Might throw std::bad_alloc
  }

  //Remove empty line at back of vector
  if (!v.empty() && v.back().empty()) v.pop_back();
  assert(!v.back().empty());
  return v;
}
