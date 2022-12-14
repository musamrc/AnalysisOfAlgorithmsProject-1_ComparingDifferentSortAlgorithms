//Musa Meriç

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    printf("%d ", array[i]);
}
*/
//O(n^2) time complexity in average and worst case , O(n) time complexity in best case
int insertionSort(int arr[], int n,int element)
{
    int i, key, j;	
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        //printf("%d\n",i);
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//O(n*Log n) in all the 3 cases (worst, average and best)
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r);
    }
}


//O(n*logn) time complexity for average and best case , O(n^2) time complexity for worst case
void quickSort(int A[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p, r);
        quickSort(A,p, q-1);
        quickSort(A,q+1, r);
    }
}

int partition(int A[],int p, int r){
    int tmp;
    int x = A[r];
    int i = p-1;
    int j;
    for(j=p; j<=r-1; j++)
    {
        if(A[j]<=x)
        {
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp;
    return i+1;
}

//O(n*k)time complexity for all cases
void partialSelection(int arr[],int k,int n){
	int i,j;
	for(i=0;i<=k;i++){
		int minValue = arr[i];
		int minPosition = i;
		for(j=i+1;j<n;j++){
			if(arr[j] < minValue){
				minValue = arr[j];
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}			
		}
	}
}

//O(n*log(n)) time complexity for all cases Partial Heap Sort
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  int largest;
  if (size == 1)
  {

  }
  else
  {
    largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    int i ;
    for (i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int n)
{
    // Get the last element
    int lastElement = arr[n - 1];
 
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    n = n - 1;
 
    // heapify the root node
    heapify(arr, n, 0);
}
//End of Partial Heap Sort Part 

//Quick Select Part
int partitionQ(int array[], int l, int r, int index)
{
    // pick `pIndex` as a pivot from the array
    int pivot = array[index];
 
    // Move pivot to end
    swap(&array[index], &array[r]);
 
    // elements less than the pivot will be pushed to the left of `pIndex`;
    // elements more than the pivot will be pushed to the right of `pIndex`;
    // equal elements can go either way
    index = l;
    int i;
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (i = l; i < r; i++)
    {
        if (array[i] <= pivot)
        {
            swap(&array[i], &array[index]);
            index++;
        }
    }
 
    // move pivot to its final place
    swap(&array[index],&array[r]);
 
    // return `pIndex` (index of the pivot element)
    return index;
}
 
// Returns the k'th smallest element in the list within `left…right`
// (i.e., left <= k <= right). The search space within the array is
// changing for each round – but the list is still the same size.
// Thus, `k` does not need to be updated with each round.
int quickselect(int array[], int l, int r, int k)
{
    // If the array contains only one element, return that element
    if (l == r) {
        return array[l];
    }
 
    // select `pIndex` between left and right
    int pIndex = l  % (r - l + 1);
 
    pIndex = partitionQ(array, l, r, pIndex);
 
    // The pivot is in its final sorted position
    if (k == pIndex) {
        return array[k];
    }
 
    // if `k` is less than the pivot index
    else if (k < pIndex) {
        return quickselect(array, l, pIndex - 1, k);
    }
 
    // if `k` is more than the pivot index
    else {
        return quickselect(array, pIndex + 1, r, k);
    }
}

int MedianOfThreePartition(int array[],int p, int r) {
	int total;
    int x=array[p],y=array[(r-p)/2+p],z=array[r-1],i=p-1,j=r;
    if (y>x && y<z || y>z && y<x ) x=y;
    else if (z>x && z<y || z>y && z<x ) x=z;
    while (1) {
        do  {j--;total++;} while (array[j] > x);
        do  {i++;total++;} while (array[i] < x);
        if  (i < j) swap(&array[i],&array[j]);
        else return j+1;
    }
}
     
int main()
{
	int a;
	int i =0;
	int wantedIndexValue = 10565;
	int arr[20000];
	
	//Creating random numbers for array
	//for(i=1;i<=20000;i++){
	//  arr[i-1] = rand();
	//}
	

	//Increasing order Inputs
	//for(i=1;i<=20000;i++){
	//	arr[i-1] = i;
	//}

	//Decreasing order Inputs
	for(i=1;i<=20000;i++){
		arr[20000-i] = i;
	}
	
	
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of input : %d\n",n);
    int temp[n];
    
    clock_t timeOfCopy;
    timeOfCopy = clock();
    for(a=0;a<1000;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}}
    timeOfCopy = clock() - timeOfCopy;
    double time_taken_by_array_copy= ((double)timeOfCopy)/CLOCKS_PER_SEC/1000;
    printf("took %f  to copy an array \n\n", time_taken_by_array_copy);

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!INSERTION SORT PART!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!INSERTION SORT PART!!!!!!!!!!!!!!!!!!!!
	//Starting clock and calling Insertion Sort
	//Creating copies of arr[]
	clock_t insertionsorttime;
    insertionsorttime = clock();
       	for(a=0;a<1;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}
		insertionSort(temp, n,wantedIndexValue);
	}
	printf("Number of input : %d\n",n);
    printf("%dth element is %d. (Find by insertion sort)\n",wantedIndexValue,temp[wantedIndexValue]);
    //Stop the clock
    insertionsorttime = clock() - insertionsorttime;
    double time_taken_insertion = (((double)insertionsorttime)/CLOCKS_PER_SEC-(time_taken_by_array_copy*1))/1; // in seconds 
	printf("took %f  to execute Insertion Sort \n\n", time_taken_insertion);
    
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!MERGE SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!MERGE SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
    //Creating a copy of arr[]
	//Starting clock and calling MergeSort
	clock_t mergetime;
    mergetime = clock();
    for(a=0;a<10;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}
		mergeSort(temp, 0, n-1);
	}
	printf("Number of input : %d\n",n);
    printf("%dth element is %d. (Find by merge sort)\n",wantedIndexValue,temp[wantedIndexValue]);
    //Stop the clock
    mergetime = clock() - mergetime;
    double time_taken_merge = ((((double)mergetime)/CLOCKS_PER_SEC)-(time_taken_by_array_copy*10))/10; // in seconds  
    printf("took %f seconds to execute Merge Sort \n\n", time_taken_merge);

   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QUICK SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QUICK SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
	//Starting clock and calling QuickSort
	clock_t quicktime;
    quicktime = clock();
    for(a=0;a<1;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}
		quickSort(temp,0,(n-1));
	}
	printf("Number of input : %d\n",n);
    printf("%dth element is %d. (Find by quick sort)\n",wantedIndexValue,temp[wantedIndexValue]);
    //Stop the clock
    quicktime = clock() - quicktime;
    double time_taken_quick = ((((double)quicktime)/CLOCKS_PER_SEC)-(time_taken_by_array_copy*1))/1; // in seconds  
    printf("took %f seconds to execute Quick Sort \n\n", time_taken_quick);
    
    
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PARTIAL SELECTION SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PARTIAL SELECTION SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
    int partialsorttemparr[n];
    for(i=0;i<n;i++){
    	partialsorttemparr[i]=arr[i];
	}

	//Starting clock and calling Partial Selection Sort
	clock_t partialsorttime;
    partialsorttime = clock();
    
    printf("Number of input : %d\n",n);
    for(a=0;a<10;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}
	      partialSelection(temp,wantedIndexValue,n);
	}
    printf("%dth element is %d. (Find by partial selection sort)\n",wantedIndexValue,temp[wantedIndexValue]);
    //Stop the clock
    partialsorttime = clock() - partialsorttime;
    double time_taken_partialsort = ((((double)partialsorttime)/CLOCKS_PER_SEC)-(time_taken_by_array_copy*10))/10; // in seconds  
    printf("took %f seconds to execute Partial Sort Selection\n\n", time_taken_partialsort);
    
   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PARTIAL HEAP SORT PART!!!!!!!!!!!!!!!!!!!!!!!!
	//Starting clock and calling Partial Selection Sort
	clock_t partialheapsorttime;
    partialheapsorttime = clock();
    int partialheaptemparr[n];
    for(i=0;i<n;i++){
    	insert(partialheaptemparr,arr[i]);
	}
	int j = n;
	for(i=(n-wantedIndexValue-1);i>0;i--){
    deleteRoot(partialheaptemparr,j);
    j--;
    }
    //Stop the clock
    partialheapsorttime = clock() - partialheapsorttime;
    double time_taken_partialheapsort = ((double)partialheapsorttime)/CLOCKS_PER_SEC; // in seconds 
    printf("Number of input : %d\n",n);
	printf("Root element is %d after %d times root removal. (Find by partial heap sort)\n",partialheaptemparr[0],(n-wantedIndexValue)); 
    printf("took %f seconds to execute Partial Heap Sort Selection\n\n", time_taken_partialheapsort);

   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!QUICK SELECT PART!!!!!!!!!!!!!!!!!!!!!!!!
	//Starting clock and calling Partial Selection Sort
	clock_t quickselecttime;
    quickselecttime = clock();
    for(a=0;a<10;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}
		quickselect(temp,0,(n-1),wantedIndexValue);
	}
	printf("Number of input : %d\n",n);
    printf("%dth smallest element is %d. (Find by Quick Select)\n",wantedIndexValue,temp[wantedIndexValue]);
	//Stop the clock
    quickselecttime = clock() - quickselecttime;
    double time_taken_quickselect = ((((double)quickselecttime)/CLOCKS_PER_SEC)-(time_taken_by_array_copy*10))/10; // in seconds  
    printf("took %f seconds to execute Quick Select Algorithm\n\n", time_taken_quickselect);
    
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!MEDIAN OF THREE PART!!!!!!!!!!!!!!!!!!!!!!!!
	//Starting clock and calling Partial Selection Sort
	clock_t medianofthreeselecttime;
	medianofthreeselecttime = clock();
   	for(a=0;a<100;a++)
   	{
   		for(i=0;i<n;i++){
    			temp[i]=arr[i];
				}
		MedianOfThreePartition(temp, 0, n);
	}
	printf("Number of input : %d\n",n);
    printf("%dth smallest element is %d. (Find by Median of Three Select Algortihm)\n",wantedIndexValue,temp[wantedIndexValue]);
	//Stop the clock
	medianofthreeselecttime = clock() - medianofthreeselecttime;
    double time_taken_medianofthreeselect = ((((double)medianofthreeselecttime)/CLOCKS_PER_SEC)-(time_taken_by_array_copy*100))/100; // in seconds  
    printf("took %f seconds to execute Quick Select Algorithm\n\n", time_taken_medianofthreeselect);
    
    return 0;
}
