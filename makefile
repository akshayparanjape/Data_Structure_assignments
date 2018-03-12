all:
	g++ -c 2012PH10855.cpp
	g++ 2012PH10855.o -o memory_alloc
	
clean:
	rm -rf *o memory_alloc.out
