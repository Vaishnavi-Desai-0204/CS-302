#include <bits/stdc++.h>
 unsigned long long int mergecomparisons =0;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    unsigned long long int swaps = 0;
 
    int i = left; /* i is index for left subarray*/
    int j = mid;  /* j is index for right subarray*/
    int k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
 
           
            swaps = swaps + (mid - i);
        }
        mergecomparisons++;
    }
 
    /* Copy the remaining elements of left subarray
     (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
     (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return swaps;
}
 
/* An recursive function that sorts the input
   array and returns the number of inversions in the
   array. */
int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, swaps = 0;
    if (right > left)
    {
        mid = (right + left)/2;
 
        /* swaps will be nothing but Inversion counts -sum of inversions in
           left-part, right-part and number of inversions
           in merging */
        swaps  = mergeSort(arr, temp, left, mid);
        swaps += mergeSort(arr, temp, mid+1, right);
 
        /*Merge the two parts*/
        swaps += merge(arr, temp, left, mid+1, right);
    }
 
    return swaps;
}
 
 int getcomparisons (){
     return mergecomparisons;
 }
