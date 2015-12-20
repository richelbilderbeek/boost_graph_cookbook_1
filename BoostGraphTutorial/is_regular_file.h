#ifndef IS_REGULAR_FILE_H
#define IS_REGULAR_FILE_H

#include <string>

///Determines if a filename is a regular file
///Adapted from http://www.richelbilderbeek.nl/CppIsRegularFile.htm
bool is_regular_file(const std::string& filename) noexcept;

#endif // IS_REGULAR_FILE_H
