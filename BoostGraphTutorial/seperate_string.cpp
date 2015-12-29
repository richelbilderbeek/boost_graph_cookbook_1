#include "seperate_string.h"

#include <cassert>
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
  {
    //Empty for loop
  }
  return v;
}

void seperate_string_test() noexcept
{
 { //Single input, seperator of type char
    const std::vector<std::string> v = seperate_string("a",',');
    assert(v[0]=="a");
  }
  { //Two inputs, seperator of type char
    const std::vector<std::string> v = seperate_string("a,b",',');
    assert(v[0]=="a");
    assert(v[1]=="b");
  }
  { //Five inputs, seperator of type char
    const std::vector<std::string> v = seperate_string("a,bb,ccc,dddd,eeeee",',');
    assert(v[0]=="a");
    assert(v[1]=="bb");
    assert(v[2]=="ccc");
    assert(v[3]=="dddd");
    assert(v[4]=="eeeee");
  }
  { //Three inputs, of which one empty, seperator of type char
    const std::vector<std::string> v = seperate_string("a, ,ccc",',');
    assert(v[0]=="a");
    assert(v[1]==" ");
    assert(v[2]=="ccc");
  }
}
