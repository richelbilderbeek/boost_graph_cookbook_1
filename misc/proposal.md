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
to a complex (yet powerful, useful and heavily used) programming library
in a pedagogic and pragmatic way.

This book, called 'Boost.Graph Cookbook 1: Basics', follows a 'cookbook' style,
that orders its items in chronologically logical fashion,
increasing the complexity gradually,
while showing complete pieces of code.

The library taught is a C++ library to create graphs (i.e. a collection of
vertices and edges).

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
   * 2.10 boost::add\_edge result
   * 2.11 Getting the edge iterators
   * 2.12x Edge descriptors
   * 2.13x Get all edge descriptors
   * 2.14x Creating a directed graph
   * 2.5x Function to create such a graph
   * 2.6x Creating such a graph
   * 2.7x The .dot file produced
   * 2.8x The .svg file produced
   * 2.9x Creating $K_{2$, a fully connected undirected graph with two vertices
   * 2.0x Function to create such a graph
   * 2.1x Creating such a graph
   * 2.2x The .dot file produced
   * 2.3x The .svg file produced
   * 2.4x $\triangle$ Creating $K_{3$, a fully connected undirected graph with three vertices
   * 2.5x Graph
   * 2.6x Function to create such a graph
   * 2.7x Creating such a graph
   * 2.8x The .dot file produced
   * 2.9x The .svg file produced
   * 2.0x $\triangle$ Creating a path graph
   * 2.1x Graph
   * 2.2x Function to create such a graph
   * 2.3x Creating such a graph
   * 2.4x The .dot file produced
   * 2.5x The .svg file produced
   * 2.6x $\triangle$ Creating a Peterson graph
   * 2.7x Graph
   * 2.8x Function to create such a graph
   * 2.9x Creating such a graph
   * 2.0x The .dot file produced
   * 2.1x The .svg file produced

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

   * 3.x Getting the vertices' out degree
   * 3.x $\triangle$ Is there an edge between two vertices?
   * 3.x $\triangle$ Get the edge between two vertices
   * 3.x $\triangle$$\triangle$ Create a direct-neighbour subgraph from a vertex descriptor
   * 3.x $\triangle$$\triangle$ Create a direct-neighbour subgraph from a vertex descriptor including inward edges
   * 3.x $\triangle$$\triangle$ Creating all direct-neighbour subgraphs from a graph without properties
   * 3.x $\triangle$$\triangle$ Count the number of connected components in an directed graph
   * 3.x $\triangle$$\triangle$ Count the number of connected components in an undirected graph
   * 3.x $\triangle$$\triangle$ Count the number of levels in an undirected graph
   * 3.x Saving a graph to a .dot file
   * 3.x Loading a directed graph from a .dot
   * 3.x Loading an undirected graph from a .dot file
   * 7.x Has a my\_bundled\_edge
   * 7.x Find a my\_bundled\_edge
   * 7.x Get an edge its my\_bundled\_edge
   * 7.x Set an edge its my\_bundled\_edge
   * 7.x Storing a graph with bundled edges and vertices as a .dot
   * 7.x Load a directed graph with bundled edges and vertices from a .dot file
   * 7.x Load an undirected graph with bundled edges and vertices from a .dot file
   * 12.x Formed reference to void
   * 12.x No matching function for call to clear\_out\_edges
   * 12.x No matching function for call to clear\_in\_edges
   * 12.x Undefined reference to boost::detail::graph::read\_graphviz\_new
   * 12.x Property not found: node\_id
   * 12.x Stream zeroes
   * 8.x Create an empty directed graph with a graph name property
   * 8.x Create an empty undirected graph with a graph name property
   * 8.x Get a graph its name property
   * 8.x Set a graph its name property
   * 8.x Create a directed graph with a graph name property
   * 8.x Create an undirected graph with a graph name property
   * 5.x Has a bundled vertex with a my\_bundled\_vertex
   * 5.x Find a bundled vertex with a certain my\_bundled\_vertex
   * 5.x Get a bundled vertex its my\_bundled\_vertex
   * 5.x Set a bundled vertex its my\_vertex
   * 5.x Setting all bundled vertices' my\_vertex objects
   * 5.x Storing a graph with bundled vertices as a .dot
   * 5.x Loading a directed graph with bundled vertices from a .dot
   * 5.x Loading an undirected graph with bundled vertices from a .dot
   * 9.x Storing a graph with a graph name property as a .dot file
   * 9.x Loading a directed graph with a graph name property from a .dot file
   * 9.x Loading an undirected graph with a graph name property from a .dot file
   * 6.x Creating the bundled edge class
   * 6.x Create an empty directed graph with bundled edges and vertices
   * 6.x Create an empty undirected graph with bundled edges and vertices
   * 6.x Add a bundled edge
   * 6.x Getting the bundled edges my\_edges
   * 6.x Creating a Markov-chain with bundled edges and vertices
   * 6.x Creating $K_{3$  with bundled edges and vertices
   * 13.x List of all edge, graph and vertex properties
   * 13.x Graphviz attributes
   * 11.x Getting a data type as a std::string
   * 11.x Convert a .dot to .svg
   * 11.x Check if a file exists
   * 4.x Creating the bundled vertex class
   * 4.x Create the empty directed graph with bundled vertices
   * 4.x Create the empty undirected graph with bundled vertices
   * 4.x Add a bundled vertex
   * 4.x Getting the bundled vertices' my\_vertexes
   * 4.x Creating a two-state Markov chain with bundled vertices
   * 4.x Creating $K_{2$ with bundled vertices
   * 10.x Encode a std::string to a Graphviz-friendly format
   * 10.x Decode a std::string from a Graphviz-friendly format
   * 10.x Check if a std::string is Graphviz-friendly

## Audience. Who is your target audience and how will your book meet their needs?

## Competition. List any competing titles. How will your work compete?

## Market. Discuss the market for your book.

## You. Who are you? What are your goals in writing this book?

## Footnotes

 * [1] It is irrelevant here to explain what these are
 * [2] This may be changed to allow for publication
