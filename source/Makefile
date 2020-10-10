all: all.out 
all.out : WomenPlayers.o rating.o womendb.o test-1.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
test-1.o : test-1.cpp womendb.h  rating.h WomenPlayers.h 
	g++ $< -c
womendb.o : womendb.cpp  womendb.h  rating.h WomenPlayers.h 
	g++ $< -c
rating.o : rating.cpp rating.h womendb.h
	g++ $< -c    
WomenPlayers.o : WomenPlayers.cpp WomenPlayers.h
	g++ $< -c
clean:
	rm -rf *.o *.out
