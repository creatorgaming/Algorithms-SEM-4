#include "iostream"
#include <stdlib.h>
#include "time.h"
using namespace std;
#define size 10
#define newSize 2*size - 1
#define range 100

void makeMinArray(int*);
void printArray(int*);

void heapSort(int*,int);
void maxHeapify(int*,int,int);

int main() {
  srand(time(NULL));
  int *a = new int[newSize];
  for (int i = newSize; i >= size; i--){
    int k = 1 + rand()%(range);
    a[i] = k;
  }
  std::cout << "Original Array..." << '\n';
  printArray(a);
  makeMinArray(a);
  std::cout << "Modified Array..." << '\n';
  printArray(a);
  heapSort(a,newSize);
  std::cout << "Sorted Array..." << '\n';
  printArray(a);

  return 0;
}

void makeMinArray(int *a){
  for (int i = newSize; i >= 0; i = i - 2){
    if(a[i] < a[i-1])
      a[i/2] = a[i];
    else
      a[i/2] = a[i-1];
  }
}

void heapSort(int *arr, int n){
    for(int i = (n/2) - 1; i >= 0; i--){
        maxHeapify(arr,n,i);
    }
    for(int i = n-1; i >= 0; i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

void maxHeapify(int *a, int n, int k){
    int l = 2*k + 1;
    int r = 2*k + 2;
    int large = k;

    if(l<n && a[l]>a[large])large=l;
    if(r<n && a[r]>a[large])large=r;

    if(large != k){
        swap(a[k],a[large]);
        maxHeapify(a,n,large);
    }
}

void printArray(int *a){
  for(int i = 0; i <= newSize; i++){
    std::cout << "["<< i << "] -> " << a[i] << '\n';
  }
  std::cout << "" << '\n';
}
