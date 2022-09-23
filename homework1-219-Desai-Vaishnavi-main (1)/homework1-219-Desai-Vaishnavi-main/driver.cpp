#include <string>
#include <iostream>
using namespace std;
#define MAX 200

#include "LinkedList.h"

int getMenuChoice();
void printTasks(LinkedList<string> &list);
void addTask(LinkedList<string> &list);
void deleteTask(LinkedList<string> &list);
void completeTasks(LinkedList<string> &list);


int main(){  
    LinkedList<string> newList;
    int option;
    do{
        option = getMenuChoice();
        switch(option){
            case 1: addTask(newList);
                    break;
            case 2: printTasks(newList);
                    deleteTask(newList);
                    break;
            case 3: completeTasks(newList);
                    break;
            case 4: printTasks(newList);
                    break;
            case 0: break;
        }
    }while(option!=0);
    
return 0;
}

int getMenuChoice(){
    int op;
    cout<<"TODO LIST"<<endl;
    cout<<"1.Add Task"<<endl;
    cout<<"2.Complete Task"<<endl;
    cout<<"3.Complete List"<<endl;
    cout<<"4.Diplay Tasks"<<endl;
    cout<<"0.Exit"<<endl;

    cin >> op;
    return op;

}

void printTasks(LinkedList<string> &list){
    vector<string> listVector = list.toVector();  
      for (int i = 0; i < (int)listVector.size(); i++){       
           cout << i+1<<listVector.at(i) <<endl;   
        }
    
}

void addTask(LinkedList<string> &list){
    int pos=0;
    cout<<"What is the priority of your new task?"<<endl;
    cin>>pos;
         
    while(pos>list.getCurrentSize()+1){
        
        cout<<"Choose a priority 1 through "<<list.getCurrentSize()+1<<endl;
        cin>>pos;
    }
    
       if(pos>=1 && pos<=list.getCurrentSize()+1){
            string task;
            cout<<"What is your new task?";
            cin>>task;
            list.add(pos,task);
        }
}

void deleteTask(LinkedList<string> &list){
    int size=list.getCurrentSize();
    int pos=0;
    do{
        cout<<"Which task have you completed?"<<endl;
        cin >> pos;
        
        if(pos>size){
            cout<<"Invalid choice"<<endl;
        }
    }while(pos>size);
    list.remove(pos);
}

void completeTasks(LinkedList<string> &list){
    list.clear();
}
