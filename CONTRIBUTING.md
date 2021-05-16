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
 * Code follows the file organisation (see `File organisation`) of this project

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

### A function `f`

When writing code, please follow the coding standards and patterns used 
in this project. 

For example, take the function `f`:

 * `f` will be defined in `f.impl`. This file will be shown in the LyX document
 * If `f` is a template function, 
   `f` its definition will be reachable from `f.h`, by `#include "f.impl"`
 * If `f` is a non-template function, 
   `f` its definition will be reachable from `f.cpp`, by `#include "f.impl"`
 * The function `f` will be tested in `f_test.cpp` using Boost.Test
 * The function `f` in combination with GraphViz functionality,
   will be tested in `f_test_graphviz.cpp` using Boost.Test

### The many `.pri` files

Source files are split up in multiple dimensions.

Selection                               |Filename
----------------------------------------|---------------------------------------------------------------------------
All                                     |`boost_graph_cookbook_1.pri`
No GraphViz                             |`boost_graph_cookbook_1_no_graphviz.pri`
Bundled edges and vertices              |`boost_graph_cookbook_1_bundled_edges_and_vertices.pri`
Bundled vertices                        |`boost_graph_cookbook_1_bundled_vertices.pri`
Custom and selectable edges and vertices|`boost_graph_cookbook_1_custom_and_selectable_edges_and_vertices.pri`
Custom and selectable vertices          |`boost_graph_cookbook_1_custom_and_selectable_vertices.pri`
Custom edges and vertices               |`boost_graph_cookbook_1_custom_edges_and_vertices.pri`
Custom vertices                         |`boost_graph_cookbook_1_custom_vertices.pri`
Helper functions                        |`boost_graph_cookbook_1_helper.pri`
Named and selectable vertices           |`boost_graph_cookbook_1_named_and_selectable_vertices.pri`
Named edges and vertices                |`boost_graph_cookbook_1_named_edges_and_vertices.pri`
Named graph                             |`boost_graph_cookbook_1_named_graph.pri`
Named vertices                          |`boost_graph_cookbook_1_named_vertices.pri`


