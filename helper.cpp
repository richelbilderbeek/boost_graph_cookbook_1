#include "helper.h"

#include <algorithm>
#include <boost/algorithm/string/replace.hpp>

helper::helper()
{
  #ifndef NDEBUG
  test();
  #endif
}

std::string helper::underscorify(const std::string& s) const noexcept
{
  return boost::algorithm::replace_all_copy(s," ","_");
}

std::string helper::deunderscorify(const std::string& s) const noexcept
{
  return boost::algorithm::replace_all_copy(s,"_"," ");
}

void helper::test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  //underscorify
  {
    assert(helper().underscorify("A B") == "A_B");
  }
  //deunderscorify
  {
    assert(helper().deunderscorify("A_B") == "A B");
  }
}
