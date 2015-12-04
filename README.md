# Boost.Graph tutorial

A [Boost.Graph tutorial (PDF)](boost_graph_tutorial.pdf).

This tutorial offers examples to use Boost.Graph that are

 * simple
 * short
 * complete
 * tested to compile
 * in a chronological order.

Boost.Graph is a C++ library that is part of [www.boost.org](Boost).

## FAQ

### Why did you start this tutorial?

I think that Boost.Graph is designed very well. Drawback is IMHO that there are only few and even fewer complete examples using Boost.Graph. The book [1] is IMHO not the most helpful.

### What do you think of the book `Boost Graph Library: User Guide and Reference Manual`?

I think the authors took great care that the code snippets written in the book were correct:
all snippets are numbered, and I'd bet they are tested to compile. 

Expect to find heavy templated code. My students cringe when they read even the first code snippet!

I would assume that the book would start with creating a simple graph in `main`, then reading its vertices and
edges, etc. The first code snippet that has a `main` is at page 15 (first page is 4) and is approximately the 10th 
code snippet. 

Instead of a code snippet with `main`, the first code snippet `is_self_loop` (at page 6)
describes how to test an edge for starting and ending at the same node, 
which has only templated arguments. 
I have had no idea how to call that code for a long long time!

Also the first code snippet in which a graph is build up,
called `build_router_network` (page 9) does not return a graph (and
thus has a known data type), it modifies an existing templated graph
of unknown data type.
I have had no idea how to call that code for a long long time!

The code that was in the book is uploaded at [informIT](http://www.informit.com/store/boost-graph-library-user-guide-and-reference-manual-9780201729146) as a `.sit` (StuffIt) file, which is badly supported on Linux. Why not just post an open compression file format?

## References 
[1] Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
