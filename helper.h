#ifndef HELPER_H
#define HELPER_H

#include <string>

class helper
{
public:
  helper();

  //Replace spaces by underscored
  std::string underscorify(const std::string& s) const noexcept;

  //Replace underscores by spaces
  std::string deunderscorify(const std::string& s) const noexcept;

private:
  void test() noexcept;
};

#endif // HELPER_H
