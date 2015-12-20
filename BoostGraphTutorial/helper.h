#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

class helper
{
public:
  helper();


  ///Replace underscores by spaces
  std::string deunderscorify(const std::string& s) const noexcept;

  ///Convert a file to a std::vector<std::string>
  ///of its content
  std::vector<std::string> file_to_vector(
    const std::string& filename
  ) const noexcept;

  ///Replace spaces by underscores
  std::string underscorify(const std::string& s) const noexcept;

private:
  void test() noexcept;
};

#endif // HELPER_H
