#/bin/bash
mousepad \
  boost_graph_cookbook_1/boost_graph_cookbook_1.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_1.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_2.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_3.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_4.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_5.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_6.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_chapter_7.tex \
  boost_graph_cookbook_1/boost_graph_cookbook_1_lyx.txt

./create_pdf.sh

FILE=boost_graph_cookbook_1/boost_graph_cookbook_1.pdf
if test -f "$FILE"; then
  evince "$FILE"
fi



