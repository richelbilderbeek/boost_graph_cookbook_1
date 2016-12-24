# Contributing

Awesome! As I am aware, that there are some corners in the manual that are unfinished. 

You can:

 * Fix an existing Issue
 * Add an Issue
 * Submit a Pull Request
 * Send me an email

Also typo's and writing suggestions are welcome.

## Branching policy

 * The `master` branch should always build successfully
 * Developers work on the `develop` branch

## Submitting code

Submitted code should follow these quality guidelines:

 * All tests pass cleanly/silently
 * Code coverage above 95%
 * OCLint must be clean

These are all checked by Travis CI when submitting
a Pull Request. 

## Coding standard

The Stroustrup/GNU style, e.g.:

 * Two spaces, no tabs
 * snake_case in variable, function and class names
 * member variables have the `m_` prefix
 * static member variables have the `sm_` prefix

```
void do_it()
{
  int some_thing;
  if (1 == 2) 
  {

  }
  else
  {

  }
}

class my_class
{
  void do_something();
  int m_some_variable;
  static int sm_count;
};
```
Then just follow OCLint

## File management

When writing code, please follow the coding standards and patterns used 
in this project. 

For example, take the function `f`:

 * `f` will be defined in `f.impl`. This file will be shown in the LyX document
 * If `f` is a template function, `f` its definition will be reachable from `f.h`, by `#include "f.impl"`
 * If `f` is a non-template function, `f` its definition will be reachable from `f.cpp`, by `#include "f.impl"`
 * The function `f` will be tested in `f_test.cpp` using Boost.Test
