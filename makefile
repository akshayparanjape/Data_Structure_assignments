all : 
	g++ -c 2012PH10855.cpp 
	g++ 2012PH10855.o -o hello

clean:
	rm -rf *o hello
	


