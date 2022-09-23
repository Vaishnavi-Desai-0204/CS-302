
int selectcomparisons =0;

int selectionSort(int arr[], int n)
{
    selectcomparisons =0;
    int i, j, smallIndex;
    int temp;
    int swaps=0;
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        smallIndex = i;
        for (j = i+1; j < n; j++){
            selectcomparisons++;
            if (arr[j] < arr[smallIndex]){
                
                smallIndex = j;
                
            }
        }

         if ( smallIndex != i){
            // swapping the found minimum element with the first element
            temp = arr[i];
            arr[i] = arr[smallIndex];
            arr[smallIndex] = temp;
            swaps++;
         }
            
        
    }
    return swaps;
}


int getc(){
    return selectcomparisons;
}
