main :
	g++ -o lab1 PolStr.o main.cpp 
main-debug :
	g++ -g -O1 -o lab1 main.cpp PolStr.o
