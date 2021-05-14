#!/bin/bash
#
# Create the PDF 'boost_graph_cookbook_1.pdf'
#
# It does so by converting the TeX to PDF, 
# as well as stitching some other PDFs to it
#
# Usage:
#
#   ./create.sh
#
cd boost_graph_cookbook_1
pdflatex boost_graph_cookbook_1.tex
bibtex boost_graph_cookbook_1 >/dev/null
pdflatex boost_graph_cookbook_1.tex >/dev/null
pdflatex boost_graph_cookbook_1.tex
mv boost_graph_cookbook_1.pdf ../boost_graph_cookbook_1_v3_3.pdf
