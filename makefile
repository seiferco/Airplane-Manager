exeFile = main
CC = g++

$(exeFile): main.cpp airport.o flight.o manager.o
	$(CC) main.cpp airport.o flight.o manager.o -o $(exeFile)

airport.o: airport.cpp airport.h
	$(CC) -c airport.cpp

flight.o: flight.cpp flight.h
	$(CC) -c flight.cpp

manager.o: manager.cpp manager.h
	$(CC) -c manager.cpp

clean:
	rm -f *.o $(exeFile)

valgrind:
	valgrind --leak-check=full ./$(exeFile)