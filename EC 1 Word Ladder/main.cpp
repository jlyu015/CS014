#include <iostream>
#include <time.h>
using namespace std;

//collab with Ryan Ly

void Quicksort_midpoint(int numbers[], int i, int k); //this function sorts the given array in the range from i to k using quicksort method. In this function, pivot is the midpoint element (numbers[(i+k)/2]). (implementation of this function is given in section 21.5)
void Quicksort_medianOfThree(int numbers[], int i, int k); //this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the median of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.
void InsertionSort(int numbers[], int numbersSize); //this function sorts the given array using InsertionSort method. (implementation of this method is provided in section 21.3).
void fillArrays(int arr1[], int arr2[],int arr3[]);
int genRandInt(int low, int high);
void swap(int i, int k);
int Partition(int numbers[], int i, int k);
const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds


void swap(int i, int k) {
    int temp = i;
    i = k;
    k = temp;
}

int Partition(int numbers[], int i, int k) {
   int l;
   int h;
   int midpoint;
   int pivot;
   int temp;
   bool done;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];
   
   done = false;
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
      }
      
      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}
int Partition_Median(int numbers[], int i, int k){
     int l = 0;
    int h = 0;
    
    int midpoint = 0;
    int pivot = 0;
    int median = 0;
    
    int temp = 0;
    bool done = false;
    
    /* Pick median element as pivot */
    midpoint = i + (k - i) / 2;
    
    if ((numbers[midpoint] >= numbers[i] && numbers[midpoint] <= numbers[k]) || (numbers[midpoint] >= numbers[k] && numbers[midpoint] <= numbers[i])) {
        
        median = midpoint;
        
    }
    else if ((numbers[i] <= numbers[midpoint] && numbers[i] >= numbers[k]) || (numbers[i] >= numbers[midpoint] && numbers[i] <= numbers[k])) {
        
        median = i;
        
    }
    else if ((numbers[k] <= numbers[i] && numbers[k] >= numbers[midpoint]) || (numbers[k] >= numbers[i] && numbers[k] <= numbers[midpoint])) {
        
        median = k;
        
    }
    
    // pivot is the median value
    pivot = numbers[median];
    
    swap(numbers[midpoint], numbers[k-1]);

    l = i;
    h = k;
    
    while (!done) {
        
        /* Increment l while numbers[l] < pivot */
        while (numbers[l] < pivot) {
            ++l;
        }
        
        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers[h]) {
            --h;
        }
        
        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            
            ++l;
            --h;
        }
    }
    
    return h;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
 int j;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort_midpoint(numbers, i, j);
   Quicksort_midpoint(numbers, j + 1, k);
}
void Quicksort_medianOfThree(int numbers[NUMBERS_SIZE], int i, int k) {

    int pivotIndex = 0;
    
    //Base case
    // If 1 or zero elements are in the boundary, then you have reached the last partition of certain side. Start working back up the recursive calls.
    // also since its only 1 or zero elements it's already sorted don't need to continue recursion.
    if (i >= k) {
        return;
    }
    
    // get the median of the partition
    pivotIndex = Partition_Median(numbers, i, k);
    
    // recursively sort the left hand side
    Quicksort_medianOfThree(numbers, i, pivotIndex);
    // afterwards sort the right hand side
    Quicksort_medianOfThree(numbers, pivotIndex + 1, k);
    
    return;

}
void InsertionSort(int numbers[], int numbersSize) {
    int i, key, j;
    for(i = 1; i < numbersSize; i++) {
        key = numbers[i];
        j = i - 1;
        while(j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);

    clock_t Start = clock();
    Quicksort_medianOfThree(arr1, 0, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Time Elapsed for quicksort_medianOfThree: " << elapsedTime << endl;

    Start = clock();
    Quicksort_midpoint(arr2, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Time Elapsed for quicksort_midpoint: " << elapsedTime << endl;
    for(unsigned i = 0; i < 10; i++) {

    }

    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Time Elapsed for Insertion Sort: " << elapsedTime << endl;

    return 0;
}
