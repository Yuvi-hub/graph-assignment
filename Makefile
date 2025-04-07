CXX = g++

CXXFLAGS = -std=c++11 -Wall -g

EXEC = graph_program

Main: Graph.o Algorithm.o Main.o
	$(CXX) $(CXXFLAGS) Graph.o Algorithm.o Main.o -o graph_program
	./graph_program

test: Graph.o Algorithm.o Test.o
	$(CXX) $(CXXFLAGS) Graph.o Algorithm.o Test.o -o test
	./test

Algorithm.o: Algorithm.cpp
	$(CXX) $(CXXFLAGS) -c Algorithm.cpp -o Algorithm.o

Graph.o: Graph.cpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Test.o: Test.cpp
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

clean:
	rm -f Algorithm.o Graph.o Main.o Test.o graph_program test

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./graph_program

.PHONY: all Main clean run test valgrind
