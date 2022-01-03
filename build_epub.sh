#!/bin/bash
cd boost_graph_cookbook_1
lyx --export pdflatex boost_graph_cookbook_1.lyx
pandoc boost_graph_cookbook_1.tex -o boost_graph_cookbook_1.epub
epubcheck boost_graph_cookbook_1.epub
cd ..