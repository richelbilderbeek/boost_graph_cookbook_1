#ifndef GET_TYPE_NAME_H
#define GET_TYPE_NAME_H

#include <string>
#include <typeinfo>
#include <cstdlib>
#include <cxxabi.h>


//From http://stackoverflow.com/questions/1055452/c-get-name-of-type-in-template
//Thanks to m-dudley ( http://stackoverflow.com/users/111327/m-dudley )
template<typename T>
std::string get_type_name()
{
  std::string tname = typeid(T).name();
  int status = -1;
  char * const demangled_name{
    abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status)
  };
  if(status == 0) {
      tname = demangled_name;
      std::free(demangled_name);
  }
  return tname;
}

void get_type_name_test() noexcept;

#endif // GET_TYPE_NAME_H
