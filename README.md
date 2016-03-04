# A well-connected C++11 Boost.Graph tutorial

[![gplv3](http://www.gnu.org/graphics/gplv3-88x31.png)](http://www.gnu.org/licenses/gpl.html)[![cc-by-sa](http://i.creativecommons.org/l/by-sa/4.0/88x31.png)](http://creativecommons.org/licenses/by-sa/4.0/)

A well-connected C++11 Boost.Graph tutorial is a C++ tutorial about Boost.Graph.

Downloads:

 * Stable: [PDF](boost_graph_tutorial.pdf) (v1.9)
 * Unstable: [PDF](BoostGraphTutorial/boost_graph_tutorial.pdf) (v1.10)

![Title graph](BoostGraphTutorial/title_graph.png)

This tutorial offers examples to use Boost.Graph that are:

 * Orders concepts chronologically
 * Increases complexity gradually
 * Shows complete pieces of code

Boost.Graph is a C++ library that is part of [Boost](http://www.boost.org).

## I want to contribute!

Awesome! As I am aware, that there are some corners in the manual that are unfinished. 

You can:

 * Fix an existing Issue
 * Add an Issue
 * Submit a Pull Request
 * Send me an email

Also typo's and writing suggestions are welcome.

When writing code, please follow the coding standards and patterns used 
in this project. 

For example, take the function `f`:

 * `f` will be defined in `f.impl`. This file will be shown in the LyX document
 * If `f` is a template function, `f` its definition will be reachable from `f.h`, by `#include "f.impl"`
 * If `f` is a non-template function, `f` its definition will be reachable from `f.cpp`, by `#include "f.impl"`
 * The function `f_demo` will demonstrate the use of `f`. This file will be shown in the LyX document
 * The function `void f_demo() noexcept` will be defined in `f_demo.impl`. 
 * The function `f_test` will test `f` and also call the function `f_demo`
 * The function `void f_test() noexcept` will be declared in `f.h`
 * The function `void f_test() noexcept` will be defined in `f.cpp`
 * The function `f_test` will be called in the `main` function

## Other resources

  * Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001
  * The Boost.Graph website, [http://www.boost.org/doc/libs/release/libs/graph/doc](http://www.boost.org/doc/libs/release/libs/graph/doc)

## Older downloads

 * [PDF](boost_graph_tutorial_v1_8.pdf) (v1.8)
 * [PDF](boost_graph_tutorial_v1_7.pdf) (v1.7)
 * [PDF](boost_graph_tutorial_v1_6.pdf) (v1.6)
 * [PDF](boost_graph_tutorial_v1_5.pdf) (v1.5)
 * [PDF](boost_graph_tutorial_v1_4.pdf) (v1.4)
 * [PDF](boost_graph_tutorial_v1_3.pdf) (v1.3)
 * [PDF](boost_graph_tutorial_v1_2.pdf) (v1.2)
 * [PDF](boost_graph_tutorial_v1_1.pdf) (v1.1)
 * [PDF](boost_graph_tutorial_v1_0.pdf) (v1.0)
