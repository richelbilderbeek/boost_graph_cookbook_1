#ifndef COPY_FILE_H
#define COPY_FILE_H

#include <string>

enum class copy_file_mode { allow_overwrite, prevent_overwrite };

///Copy a file
///Will throw if copy mode is to prevent overwrite and there
///is such a file present
void copy_file(
  const std::string& filename_from,
  const std::string& filename_to,
  const copy_file_mode copy_mode
);

#endif // COPY_FILE_H
