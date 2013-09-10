main :
	g++ -o lab1 PolStr.o main.cpp newton.cpp
main-debug :
	g++ -g -O1 -o lab1 main.cpp newton.cpp PolStr.o
