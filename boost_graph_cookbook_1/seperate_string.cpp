#include "seperate_string.h"

#include <sstream>

std::vector<std::string> seperate_string(
  const std::string& input,
  const char seperator
) noexcept
{
  std::istringstream is(input);
  std::vector<std::string> v;
  for (
    std::string sub;
    std::getline(is, sub, seperator);
    v.emplace_back(sub))
  {} //!OCLINT Indeed, an empty for loop
  return v;
}

