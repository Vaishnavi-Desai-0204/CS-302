
using namespace std;
unsigned long long int comparisons =0;
 
int bubbleSort(int arr[], int n  )
{
    comparisons =0;
    unsigned long long int swaps =0;
    int temp =0;
     int i, j;
    for (i = 0; i < n-1; i++)    {
     
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++){
            comparisons++;
            if (arr[j] > arr[j+1]){

                    
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swaps++;
                }      
            
        }
    }    
    return swaps;     
}

int c(){
    return comparisons;
}

