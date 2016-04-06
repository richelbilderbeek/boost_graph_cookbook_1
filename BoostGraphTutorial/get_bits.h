#ifndef GET_BITS_H
#define GET_BITS_H

#include <vector>

///Get the indices of the value that have a 1 bit
/// get_bits(0) == { }
/// get_bits(1) == { 0 }
/// get_bits(2) == { 1 }
/// get_bits(3) == { 0, 1 }
/// get_bits(4) == { 2 }
/// get_bits(5) == { 0, 2 }
/// get_bits(6) == { 1, 2 }
/// get_bits(7) == { 0, 1, 2 }
std::vector<int> get_bits(const int value);

#endif // GET_BITS_H
