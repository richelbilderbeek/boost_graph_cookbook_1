#include "helper.h"

#include <algorithm>
#include <cassert>

#include <fstream>
#include <stdexcept>
#include "is_regular_file.h"

helper::helper()
{
}

std::vector<std::string> helper::file_to_vector(
  const std::string& filename
) const noexcept
{
  assert(is_regular_file(filename));
  std::vector<std::string> v;
  std::ifstream in{filename.c_str()};
  assert(in.is_open());
  //Without this test in release mode,
  //the program might run indefinitely when the file does not exists
  if (!in.is_open())
  {
    const std::string s{"ERROR: file does not exist: " + filename};
    throw std::logic_error{s.c_str()};
  }
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
