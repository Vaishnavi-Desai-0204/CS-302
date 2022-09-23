#include "BankQueue.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "BankQueue.cpp"
#include "PriorityQueue.cpp"
#include <fstream>

void loadData(PriorityQueue<Event> &eventListPQueue);
Event processArrival(bool &tellerAvailable ,PriorityQueue<Event> &eventListPQueue ,BankQueue<Event> &bankQueue);
int processDeparture(bool &tellerAvailable ,PriorityQueue<Event> &eventListPQueue ,BankQueue<Event> &bankQueue);

int main(){
    BankQueue<Event> bankQueue;
    PriorityQueue<Event> eventListPQueue;
    bool tellerAvailabe = true;
    unsigned int eventsCount = 0;
    unsigned int totalArrivalTime = 0;
    unsigned int totalDepartureTime = 0;
    unsigned int totalProcessingTime = 0;
    double averageWaitingTime;
    cout << "Simulation Begins" << endl;

    loadData(eventListPQueue);
    
    while (!eventListPQueue.is_empty()){
        Event newEvent = eventListPQueue.peek_front();
        unsigned int currentTime = newEvent.getArrivalTime();

        if (newEvent.getEventType() == 'A'){
            Event customer ;
            customer =processArrival(tellerAvailabe,eventListPQueue,bankQueue);
            eventsCount++;
            cout << "Processing an arrival event at time:\t"<<customer.getArrivalTime()<<endl;
            totalArrivalTime += customer.getArrivalTime();
            totalProcessingTime+= customer.getTransactionTime();

        }
        else{
            int c ;
            c =processDeparture(tellerAvailabe,eventListPQueue,bankQueue);
            totalDepartureTime += c;
        }
        

    }
    
   averageWaitingTime = (double)(totalDepartureTime - totalProcessingTime - totalArrivalTime) / eventsCount;
  
   cout << "Simulation Ends" << endl << endl;
   cout << "Final Statistics:" << endl << endl;
   cout << "\tTotal number of people processed: " << eventsCount << endl;
   cout << "\tAverage amount of time spent waiting: " << averageWaitingTime << endl;
   
}


void loadData(PriorityQueue<Event> &eventListPQueue){
   string filename = "test.txt";
   ifstream fin;
   fin.open("test.txt");

   if (fin.fail())
   {
       cout << filename << " file cannot be opened!" << endl;
       cout << endl;
       //system("pause");
       //exit(EXIT_FAILURE);
   }

   bool tellerAvailable = true;
  
   int a, t;
   while (fin >> a >> t)
   {
       Event newArrivalEvent(a, t);
       eventListPQueue.enqueue(newArrivalEvent);
   }
   fin.close(); 
}

Event processArrival(bool &tellerAvailable ,PriorityQueue<Event> &eventListPQueue ,BankQueue<Event> &bankQueue){
    Event newEvent = eventListPQueue.peek_front();
    eventListPQueue.dequeue();
    unsigned int currentTime = newEvent.getArrivalTime();
    if (bankQueue.is_empty() && tellerAvailable){
                unsigned int departureTime = currentTime + newEvent.getTransactionTime();
                Event newDepartureEvent(departureTime, 0, 'D');
                eventListPQueue.enqueue(newDepartureEvent);
                tellerAvailable = false;
            }
        else{
                bankQueue.enqueue(newEvent);
            }
    return newEvent;
}

int processDeparture(bool &tellerAvailable ,PriorityQueue<Event> &eventListPQueue ,BankQueue<Event> &bankQueue){
        
         Event newEvent = eventListPQueue.peek_front();

       unsigned int currentTime = newEvent.getArrivalTime();
        eventListPQueue.dequeue();

           if (!bankQueue.is_empty())
           {
               Event customer = bankQueue.peek_front();
               bankQueue.dequeue();
               int departureTime = currentTime + customer.getTransactionTime();              
               Event newDepartureEvent(departureTime, 0, 'D');
               eventListPQueue.enqueue(newDepartureEvent);
           }
           else
           {
               tellerAvailable = true;
           }
           cout << "Processing an arrival event at time:\t"<<currentTime<<endl;
           return currentTime;
}