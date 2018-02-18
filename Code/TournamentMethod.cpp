#include "iostream"
#include <stdlib.h>
#include "time.h"
using namespace std;
#define size 10
#define newSize 2*size - 1
#define range 100

void makeMinArray(int*);
void printArray(int*);
void printArrayMain(int*);
void printTree(int*);

void heapSort(int*,int);
void minHeapify(int*,int,int);
int calMinimum(int*);

int main() {
  srand(time(NULL));
  int *a = new int[newSize];
  for (int i = newSize; i >= size; i--){
    int k = 1 + rand()%(range);
    a[i] = k;
  }
  std::cout << "Original Array..." << '\n';
  printArrayMain(a);
  makeMinArray(a);
  // std::cout << "Modified Array..." << '\n';
  // printArray(a);
  heapSort(a,newSize);
  // std::cout << "Heap..." << '\n';
  // printArray(a);
  int secondMinimum = calMinimum(a);
  cout << "\nSecond minimum element of the array is : " << secondMinimum;
  return 0;
}

void printTree(int*){
  
}

int calMinimum(int *a){
  int i = 3;
  while(a[i] == a[0] && a[i+1] == a[0]){
    i = i + 2;
  }
  
  if(a[i] < a[i+1]){
    return a[i];
  }else{
    return a[i+1];
  }
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
        minHeapify(arr,n,i);
    }
}

void minHeapify(int *a, int n, int k){
    int l = 2*k + 1;
    int r = 2*k + 2;
    int small = k;

    if(l<n && a[l]<a[small])small=l;
    if(r<n && a[r]<a[small])small=r;

    if(small != k){
        swap(a[k],a[small]);
        minHeapify(a,n,small);
    }
}

void printArray(int *a){
  for(int i = 0; i <= newSize; i++){
    std::cout << "["<< i << "] -> " << a[i] << '\n';
  }
  std::cout << "" << '\n';
}

void printArrayMain(int *a){
  for(int i = newSize; i >= size; i--){
    std::cout << "["<< i << "] -> " << a[i] << '\n';
  }
  std::cout << "" << '\n';
}
