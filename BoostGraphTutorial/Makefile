CXX      = g++
CXXFLAGS = -std=c++11
CPPFLAGS = -I/usr/local/boost/include
LDFLAGS  = -L/usr/local/boost/lib -lboost_graph
TARGET   = a.out
SRCS     = $(wildcard *.cpp)
OBJS     = $(SRCS:.cpp=.o)
DEPS     = $(SRCS:.cpp=.d)

.PHONY: all clean

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $< -MMD -MF $*.d

all: clean $(TARGET)

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f $(TARGET)

-include $(DEPS)
