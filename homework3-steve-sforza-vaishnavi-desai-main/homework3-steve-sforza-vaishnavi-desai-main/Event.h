#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
   char eventType;
    int arrivalTime;
    int transactionTime;

public:
   Event();
   Event( int arrTime,  int transTime);
   Event( int arrTime,  int transTime, char type);
  
    int getArrivalTime() const;
    int getTransactionTime() const;
   char getEventType() const ;
   bool operator>(const Event& Item);
};
#endif