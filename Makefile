SOURCEOBJS = PolStr.o main.cpp newton.cpp diho.cpp combined.cpp chord.cpp
main :
	g++ -o lab1 $(SOURCEOBJS)
main-debug :
	g++ -g -O1 -o lab1 $(SOURCEOBJS)
