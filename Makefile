CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

SRCS = Board.cpp Catan.cpp Edge.cpp Player.cpp Tile.cpp Vertex.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = catan
TEST_SRCS = tests.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_EXEC = tests

all: $(EXEC) $(TEST_EXEC)

$(EXEC): $(OBJS) main.o
	$(CXX) $(CXXFLAGS) $(OBJS) main.o -o $(EXEC)

$(TEST_EXEC): $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(TEST_OBJS) -o $(TEST_EXEC)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) main.o $(EXEC) $(TEST_OBJS) $(TEST_EXEC)

.PHONY: all clean
