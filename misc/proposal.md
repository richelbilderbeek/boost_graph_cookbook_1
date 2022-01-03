# Proposal

From [https://nostarch.com/writeforus](https://nostarch.com/writeforus):

> When submitting a proposal, please address the following. If this seems like an overwhelming task, just buzz us to see if we like the idea of your project and we can proceed from there. Really, the primary thing that we're looking for is a clear description of what it is that you want to write and your table of contents:
>
>    Summary of Your Book. Describe your book.
>    Outline. Provide a detailed outline listing at least chapter titles and first level headings.
>    Audience. Who is your target audience and how will your book meet their needs?
>    Competition. List any competing titles. How will your work compete?
>    Market. Discuss the market for your book.
>    You. Who are you? What are your goals in writing this book?
>
> Please also submit any writing samples for this particular project, if available.

## Summary of Your Book. Describe your book.

This book is the first to introduce the reader
to a complex (yet powerful, useful and well known) programming library
in a pedagogic and pragmatic way.

This book, called 'Boost.Graph Cookbook 1: Basics', follows a 'cookbook' style,
that orders its items in chronologically logical fashion,
increasing the complexity gradually,
while showing complete pieces of code.

The library taught is a C++ library to create graphs (i.e. a collection of
vertices and edges).

The current version of the book 
can be downloaded at https://github.com/richelbilderbeek/boost_graph_cookbook_1 .

## Outline. Provide a detailed outline listing at least chapter titles and first level headings.

### General overview

To give a general overview, these are the chapters' titles (see below for
the more detailed overview):

  1. Introduction
  2. Building graphs without properties
  3. Working on graphs without properties
  4. Building graphs with bundled vertices
  5. Working on graphs with bundled vertices
  6. Building graphs with bundled edges and vertices
  7. Working on graphs with bundled edges and vertices
  8. Building graphs with a graph name
  9. Working on graphs with a graph name
  10. Other graph functions
  11. Misc functions
  12. Errors
  13. Appendix

The first chapter introduces the book and answers questions
such as why the book is important, the idea behind it and how to read it.

The main part of the book are chapters 2 to and including 9.
These chapters come in duos: 'building [a type of graph]' 
and 'working on [a type of graph]', where each first chapter explains how
to construct a graph, and each second chapter shows how to do calculations
with such graphs.
The '[a type of graph]' builds up logically in complexity,
starting with a graph without properties [1], then bundled vertices [1],
the adding bundled edges [1], then adding a graph name.

After that follows a chapter with other graph functions,
as well as miscellaneous (non-graph) functions that are used within the book.
A chapter that shows some common compile error follows, 
as well as an appendix with a relevant lookup table.

### Detailed overview

Here I describe each chapter and its sections in detail:

 1. Introduction
   * 1.1 Why this tutorial
   * 1.2 Tutorial style
   * 1.3 Coding style
   * 1.4 License
   * 1.5 Feedback
   * 1.6 Acknowledgements
   * 1.7 Outline

The introduction starts with answering the 'why?' behind the book.
The 'Tutorial style' explain the reader the idea behind the tutorial,
where the 'Coding style' section describes the rationale behind the coding style 
used in the examples.
The section 'License' describes the current license [2]
and the section 'Feedback' directs readers to the current website [2] to give feedback.
After that, the current contributors of the book are acknowledged
and an outline of the book is given.

 2. Building graphs without properties
   * 2.1 Creating an empty (directed) graph
   * 2.2 Creating an empty undirected graph
   * 2.3 Counting the number of vertices
   * 2.4 Counting the number of edges
   * 2.5 Adding a vertex
   * 2.6 Vertex descriptors
   * 2.7 Get the vertex iterators
   * 2.8 Get all vertex descriptors
   * 2.9 Add an edge
   * 2.10 boost::add_edge result
   * 2.11 Getting the edge iterators
   * 2.12 Edge descriptors
   * 2.13 Get all edge descriptors
   * 2.14 Creating a directed graph
   * 2.15 Creating K2, a fully connected undirected graph with two vertices
   * 2.16 Creating K3, a fully connected undirected graph with three vertices
   * 2.17 [triangle] Creating a path graph
   * 2.18 [triangle] Creating a Peterson graph

In this chapter simple graphs are created, starting
with the two types of graphs (i.e. directed and undirected).
The numbers of vertices/nodes and edges/connectors
are counted, so that graphs can be confirmed to be empty.
The next sections describe how to add a vertex and the conceptual
knowledge needed to do so (i.e. understand a vertex descriptor and iterator).
The next sections describe how to add an edge,
as well as the conceptual knowledge needed to do this as well.
Finally, multiple types of simple graphs are created.
Here are the first chapters labelled with a triangle: these
are optional chapters that are useful, yet explained in less detail.

  3. Working on graphs without properties
   * 3.1 Getting the vertices' out degree
   * 3.2 Is there an edge between two vertices?
   * 3.3 [triangle] Get the edge between two vertices
   * 3.4 [triangle][triangle] Create a direct-neighbour subgraph from a vertex descriptor
   * 3.5 [triangle][triangle] Create a direct-neighbour subgraph from a vertex descriptor including inward edges
   * 3.6 [triangle][triangle] Creating all direct-neighbour subgraphs from a graph without properties
   * 3.7 [triangle][triangle] Count the number of connected components in an directed graph
   * 3.8 [triangle][triangle] Count the number of connected components in an undirected graph
   * 3.9 [triangle][triangle] Count the number of levels in an undirected graph
   * 3.10 Saving a graph to a .dot file
   * 3.11 Loading a directed graph from a .dot
   * 3.12 Loading an undirected graph from a .dot file

In this chapter, we do simple graph operations on the simple graphs.
We count how much edges 'go out' of a vertex, as well
as detecting if the vertices are connected.
The optional (i.e. labelled with a triangle) chapters show some more
advanced operations, such as reading the edge between two vertices,
creating direct-neighbour subgraphs, counting the numbers of connected components
as well as the levels in a graph.
The last sections of the chapter are dedicating to saving a graph to file
and loading it in detail.

  4. Building graphs with bundled vertices
   * 4.1 Creating the bundled vertex class
   * 4.2 Create the empty directed graph with bundled vertices
   * 4.3 Create the empty undirected graph with bundled vertices
   * 4.4 Add a bundled vertex
   * 4.5 Getting the bundled vertices' my_vertexes
   * 4.6 Creating a two-state Markov chain with bundled vertices
   * 4.7 Creating K2 with bundled vertices

Chapter 4 builds upon chapter 2 and follows the same structure.
It shows how to uses bundled vertices [1],
allowing a user to create graphs with any type of vertex.
First, a simple vertex class is shown that is used in the rest of the
chapter.
Similar to chapter 2, the book first shows how to create empty graphs 
that use the example vertex class.
After this, it is shown how to add vertices and get the vertex descriptors [1].
Finally, some simple graphs are created.

  5. Working on graphs with bundled vertices
   * 5.1 Has a bundled vertex with a my_bundled_vertex
   * 5.2 Find a bundled vertex with a certain my_bundled_vertex
   * 5.3 Get a bundled vertex its my_bundled_vertex
   * 5.4 Set a bundled vertex its my_vertex
   * 5.5 Setting all bundled vertices' my_vertex objects
   * 5.6 Storing a graph with bundled vertices as a .dot
   * 5.7 Loading a directed graph with bundled vertices from a .dot
   * 5.8 Loading an undirected graph with bundled vertices from a .dot

Chapter 5 builds upon chapter 3 and follows the same structure.
It shows some graph operations on graphs with bundled vertices [1],
such as detecting if a certain vertex is present
as well as where it is.
After finding a vertex, the book shows how to read and write data from/to such a vertex.
Section 5.5 shows how to write to all vertices at the same time.
Finally, the last sections of the chapter are dedicating to saving a graph to file
and loading it in detail.

  6. Building graphs with bundled edges and vertices
   * 6.1 Creating the bundled edge class
   * 6.2 Create an empty directed graph with bundled edges and vertices
   * 6.3 Create an empty undirected graph with bundled edges and vertices
   * 6.4 Add a bundled edge
   * 6.5 Getting the bundled edges my_edges
   * 6.6 Creating a Markov-chain with bundled edges and vertices
   * 6.7 Creating K3 with bundled edges and vertices

Chapter 6 builds upon chapter 4 and follows the same structure.
It shows how to uses bundled edges [1],
allowing a user to create graphs with any type of edge.
First, a simple edge class is shown that is used in the rest of the
chapter.
Similar to chapters 2 and 4, the book first shows how to create empty graphs 
that use the example edge class.
After this, it is shown how to add edges and get the edge descriptors [1].
Finally, some simple graphs are created.

  7. Working on graphs with bundled edges and vertices
   * 7.1 Has a my_bundled_edge
   * 7.2 Find a my_bundled_edge
   * 7.3 Get an edge its my_bundled_edge
   * 7.4 Set an edge its my_bundled_edge
   * 7.5 Storing a graph with bundled edges and vertices as a .dot
   * 7.6 Load a directed graph with bundled edges and vertices from a .dot file
   * 7.7 Load an undirected graph with bundled edges and vertices from a .dot file

Chapter 7 builds upon chapter 5 and follows the same structure.
It shows some graph operations on graphs with bundled edges [1],
such as detecting if a certain edge is present
as well as where it is.
After finding an edge, the book shows how to read and write data from/to such an edge.
Finally, the last sections of the chapter are dedicating to saving a graph to file
and loading it in detail.

  8. Building graphs with a graph name
   * 8.1 Create an empty directed graph with a graph name property
   * 8.2 Create an empty undirected graph with a graph name property
   * 8.3 Get a graph its name property
   * 8.4 Set a graph its name property
   * 8.5 Create a directed graph with a graph name property
   * 8.6 Create an undirected graph with a graph name property

Chapter 8 follows the same structure as chapters 2, 4 and 6.
It shows how to uses graps with a name, which is a simple graph property [1],
allowing a user to create graphs with any type of property.
Similar to earlier chapters, the book shows how to create empty graphs 
with a name.
Subsequently, graphs have their names read/written.
Finally, some simple graphs are created.

  9. Working on graphs with a graph name
   * 9.1 Storing a graph with a graph name property as a .dot file
   * 9.2 Loading a directed graph with a graph name property from a .dot file
   * 9.3 Loading an undirected graph with a graph name property from a .dot file

Chapter 9 shows how to save a graph with a name to file,
as well as loading it, in detail.

  10. Other graph functions
   * 10.1 Encode a std::string to a Graphviz-friendly format
   * 10.2 Decode a std::string from a Graphviz-friendly format
   * 10.3 Check if a std::string is Graphviz-friendly

Chapter 10 shows some general graph functions (used in earlier chapters) in more detail:
when saving/loading graphs, text need to be modified to be saved/loaded
correctly. This chapter shows how to encode and decode raw text,
as well as to detect if text can be saved/loaded correctly.

  11. Misc functions
   * 11.1 Getting a data type as a std::string
   * 11.2 Convert a .dot to .svg
   * 11.3 Check if a file exists

Chapter 11 shows some miscellaneous functions used in earlier chapters in more detail:
converting data to a string, converting a .dot file (i.e. a file that hold a
graph) to an image, as well as checking if a file exists.

  12. Errors
   * 12.1 Formed reference to void
   * 12.2 No matching function for call to clear_out_edges
   * 12.3 No matching function for call to clear_in_edges
   * 12.4 Undefined reference to boost::detail::graph::read_graphviz_new
   * 12.5 Property not found: node_id
   * 12.6 Stream zeroes

Chapter 12 contains and explains the errors that are encountered
in the book, as referred to by earlier chapters.

  13. Appendix
   * 13.1 List of all edge, graph and vertex properties
   * 13.2 Graphviz attributes

Chapter 13 is an appendix of two useful tables.

## Audience. Who is your target audience and how will your book meet their needs?

The audience for this book consists of professional programmers
and university students that need/want to use the Boost.Graph libray.
It allows them to understand the basics of the library,
gives useful code examples and allows them to expand upon it.

## Competition. List any competing titles. How will your work compete?

There is one other book on the Boost.Graph library,
called 'The Boost Graph Library: User Guide and Reference Manual'
by Jeremy G. Siek, Lie-Quan Lee and Andrew Lumsdaine,
ISBN-13: 978-0201729146. That book introduces how to use the Boost.Graph 
library in a different (for beginners: unnatural) order, with only the
8th code snippet that can actually be compiled.

This book gives beginner Boost.Graph users the conceptual
understanding to read that existing one,
as this book builds up in complexity naturally, 
while showing compilable code from the start.

## Market. Discuss the market for your book.

There is no book yet that introduces this C++ library so gradually.
to experienced C++ users. The library, Boost.Graph, however,
is a part of the Boost library, 
which is the most widely used C++ non-standard library.
I think that the Boost.Graph is widely *known* as being part of the Boost library,
yet usually left aside as the current book is too hard to get into.

As can be seen on GitHub, at https://github.com/richelbilderbeek/boost_graph_cookbook_1 ,
the book has received more than 160 stars.
This is without any publicity from a publisher!
To put this into perspective, a published book on the full Boost library 
at https://github.com/apolukhin/Boost-Cookbook has more than 330 stars.

## You. Who are you? What are your goals in writing this book?

I am a C++ developer with approximately 19 years of experience.
I care about code quality, as I care about people.
I know the C++ literature and show this by following its guidelines.

The goal of writing this book is to give my students/colleagues a
better introduction to the Boost.Graph library.

The current version of the book 
can be downloaded at https://github.com/richelbilderbeek/boost_graph_cookbook_1 .

## Footnotes

 * [1] It is irrelevant here to explain what these are
 * [2] This may be changed to allow for publication
