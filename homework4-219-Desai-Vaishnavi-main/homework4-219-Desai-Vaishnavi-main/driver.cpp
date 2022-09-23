#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
using namespace std::chrono;

#include "bubblesort.cpp"
#include "selectionsort.cpp"
#include "mergesort.cpp"

void randomarray(int length ,int arr[]){
  for(int j = 0 ; j < length ; j++){
        arr[j] = rand()%1000000;
    }
}
void bubble(int length , string myfilename){
  std::ofstream myfile;
  int avgunsorted =0;
  int avgsorted =0;    
  unsigned long long int sorted[10];
  unsigned long long int swap[10];
  unsigned long long int comparison[10];
  int array[length];
    
  myfile.open(myfilename); 
  myfile << "UNSORTED," << "SWAPS," << "COMPARISONS" <<endl;
  unsigned long long int swaps=0;
  for (int t= 0 ; t <10 ; t++){
    unsigned long long int comparisons =0;
    randomarray(length,array);

    auto start = high_resolution_clock::now();
    swaps =bubbleSort(array ,length);
    auto stop = high_resolution_clock::now();
    comparisons = c();
    auto duration = duration_cast<microseconds>(stop - start);
    avgunsorted+=duration.count();
    myfile << duration.count() << ","<< swaps << "," << comparisons ;
    myfile <<endl;
    
    auto s = high_resolution_clock::now();
    swap[t] =bubbleSort(array ,length);
    auto st = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(st - s);
    sorted[t] = dur.count();
    comparison[t] = c();
 }
 
 myfile << "AVERAGE,UNSORTED," << avgunsorted/10<<endl;
 myfile << "SORTED,SWAPS,COMAPARISONS" <<endl;
 for (int k= 0 ; k <10 ; k++){
   myfile << sorted[k] <<"," << swap[k] << "," << comparison[k]<<endl;
   avgsorted+= sorted[k];
  }
 myfile << "AVERAGE,SORTED," << avgsorted/10 <<endl;
 myfile.close();
}

void selection (int length , string myfilename){
  std::ofstream myfile;
  int avgunsorted =0;
  int avgsorted =0;    
  int sorted[10];
  unsigned long long int swap[10];
  unsigned long long int comparison[10];
  int array[length];
  myfile.open(myfilename); 
  
  myfile << "UNSORTED," << "SWAPS," << "COMPARISONS" <<endl;
  unsigned long long int swaps=0;
  for (int t= 0 ; t <10 ; t++){
    int comparisons =0;
    randomarray(length,array);

    auto start = high_resolution_clock::now();
    swaps =selectionSort(array ,length);
    auto stop = high_resolution_clock::now();
    comparisons = getc();
    auto duration = duration_cast<microseconds>(stop - start);
    avgunsorted+=duration.count();
    myfile << duration.count() << ","<< swaps <<","<<comparisons;
    myfile <<endl;
    
    auto s = high_resolution_clock::now();
    swap[t] =selectionSort(array ,length);
    auto st = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(st - s);
    sorted[t] = dur.count();
    comparison[t] = getc();
 }
 
  myfile << "AVERAGE,UNSORTED," << avgunsorted/10<<endl;
  myfile << "SORTED,SWAPS,COMAPARISONS" <<endl;
  for (int k= 0 ; k <10 ; k++){
    myfile << sorted[k] <<"," << swap[k] << "," << comparison[k]<<endl;
    avgsorted+= sorted[k];
  }
 myfile << "AVERAGE,SORTED," << avgsorted/10 <<endl;
 myfile.close();
}


void merge(int length , string myfilename){
  std::ofstream myfile;     
  int temp[length];
  int sorted3[10];
  unsigned long long int swap3[10];  
  unsigned long long int comparison[10];
  int array3[length];
  int avgunsorted =0;
  int avgsorted =0;    
  myfile.open(myfilename); 
  myfile << "UNSORTED," << "SWAPS," << "COMPARISONS" <<endl;
  unsigned long long int swaps3=0;
  unsigned long long int comparisons =0;
  for (int t= 0 ; t <10 ; t++){
 
    randomarray(length,array3);
    auto start3 = high_resolution_clock::now();
    swaps3 =mergeSort(array3,temp ,0 , length-1 );
    auto stop3 = high_resolution_clock::now();
    comparisons = getcomparisons();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    avgunsorted+=duration3.count();
    myfile << duration3.count() << ","<< swaps3 <<","<<comparisons;
    myfile <<endl;
    
    auto s3 = high_resolution_clock::now();
    swap3[t] =mergeSort(array3 ,temp,0 , length-1 );
    auto st3 = high_resolution_clock::now();
    auto dur3 = duration_cast<microseconds>(st3 - s3); 
    sorted3[t] = dur3.count();
    comparison[t] = getcomparisons();
  }
  myfile << "AVERAGE,UNSORTED," << avgunsorted/10 <<endl;
  myfile << "SORTED,SWAPS,COMAPARISONS" <<endl;
  for (int k= 0 ; k <10 ; k++){
     myfile << sorted3[k] <<"," << swap3[k] << "," << comparison[k]<<endl;
     avgsorted+= sorted3[k];
  }
 myfile << "AVERAGE,SORTED," << avgsorted/10<<endl;
 myfile.close();
}


int main(){
  bubble(1000 , "bubble1000.csv");

  selection(1000 , "selection1000.csv"); 

  merge(1000 , "merge1000.csv"); 


  bubble(10000 , "bubble10000.csv");

  selection(10000 , "selection10000.csv"); 

  merge(10000 , "merge10000.csv"); 



  bubble(100000 , "bubble100000.csv");

  selection(100000 , "selection100000.csv"); 

  merge(100000 , "merge100000.csv"); 

}

