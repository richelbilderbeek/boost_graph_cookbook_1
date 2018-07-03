#ifndef FILE_TO_VECTOR_H
#define FILE_TO_VECTOR_H

#include <string>
#include <vector>

/// Convert a file to a std::vector<std::string>
/// of its content
std::vector<std::string> file_to_vector(const std::string& filename);

#endif // FILE_TO_VECTOR_H
