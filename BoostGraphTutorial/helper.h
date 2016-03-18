#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

class helper
{
public:
  helper();

  ///Convert a file to a std::vector<std::string>
  ///of its content
  std::vector<std::string> file_to_vector(
    const std::string& filename
  ) const noexcept;

  ///Decode string to was encoded to be useable by Graphiv,
  ///Use graphviz_encode to encode the original string
  std::string graphviz_decode(std::string s) const noexcept;

  ///Encode string to be useable by Graphiv,
  ///Use graphviz_decode to recover the original string
  std::string graphviz_encode(std::string s) const noexcept;
};

#endif // HELPER_H
