
all: main clean

main: main.o
	$(CXX) -o $@ $^ 

main.o: main.cpp
	$(CXX) -c $<

clean:
	rm *.o

