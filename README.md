# Boost.Graph tutorial

This GitHub offers examples to use Boost.Graph that are

 * simple
 * short
 * complete
 * tested to compile

Boost.Graph is a C++ library that is part of [www.boost.org](Boost).

 * [create a graph without edge or node labels](create_simplest_graph.md)
 * [create a graph with int vertex labels](create_graph_with_int_vertex_labels.md)
 * [create a graph with std::string vertex labels](create_graph_with_string_vertex_labels.md)
 * [extract int vertex labels](extract_int_vertex_labels.md)
 * [extract std::string vertex labels](extract_string_vertex_labels.md)
 * [is_self_loop: does an edge start and end at the same vertex?](is_self_loop.md)

## FAQ

### Why did you start this tutorial?

I think that Boost.Graph is designed very well. Drawback is IMHO that there are only few and even fewer complete examples using Boost.Graph. The book [1] is IMHO not the most helpful.

### What do you think of the book `Boost Graph Library: User Guide and Reference Manual`?

I think the authors took great care that the code snippets written in the book were correct:
all snippets are numbered, and I assume they are tested to compile. 

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

## References 
[1] Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
