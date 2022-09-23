// Event class implementation
#include "Event.h"

Event::Event()
{
   arrivalTime = 0;
   transactionTime = 0;
   eventType = ' ';
}

Event::Event( int arrTime,  int transTime)
{
   arrivalTime = arrTime;
   transactionTime = transTime;
   eventType = 'A';
}

Event::Event( int arrTime,  int transTime, char type)
{
   arrivalTime = arrTime;
   transactionTime = transTime;
   eventType = type;
}

 int Event::getArrivalTime() const
{
   return arrivalTime;
}

 int Event::getTransactionTime() const
{
   return transactionTime;
}

char Event::getEventType() const
{
   return eventType;
}

bool Event::operator>(const Event& Item){
		return (arrivalTime > Item.arrivalTime);
}