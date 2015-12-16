#ifndef SEPERATE_STRING_H
#define SEPERATE_STRING_H

#include <string>
#include <vector>

std::vector<std::string> seperate_string(
  const std::string& input,
  const char seperator
) noexcept;

void seperate_string_test() noexcept;


#endif // SEPERATE_STRING_H
