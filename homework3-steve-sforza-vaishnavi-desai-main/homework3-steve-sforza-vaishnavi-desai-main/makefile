Bank: driver.o Event.o BankQueue.o PriorityQueue.o
	g++ driver.o Event.o BankQueue.o PriorityQueue.o -o Bank

driver.o: driver.cpp BankQueue.h PriorityQueue.h Event.h
	g++ -c driver.cpp BankQueue.cpp PriorityQueue.cpp Event.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

BankQueue.o: BankQueue.cpp BankQueue.h QueueInterface.h
	g++ -c BankQueue.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h QueueInterface.h
	g++ -c PriorityQueue.cpp

clean:
	rm *.o Bank