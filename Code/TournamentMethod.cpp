#include "iostream"
#include <stdlib.h>
using namespace std;
#define size 10
#define range 100

void makeMinArray(int*);
void printArray(int*);

int main() {
  srand(time(NULL));
  int *a = new int[2*size - 1];
  for (int i = (2*size) - 1; i >= size - 1; i--){
    int k = 1 + rand()%(range + 1);
    a[i] = k;
  }
  std::cout << "Original Array..." << '\n';
  printArray(a);
  makeMinArray(a);
  std::cout << "Modified Array..." << '\n';
  printArray(a);

  return 0;
}

void makeMinArray(int *a){
  for (int i = (2*size) - 1; i >= size - 1; i = i - 2){
    if(a[i] < a[i-1])
      a[i/2 - 1] = a[i];
    else
      a[i/2 - 1] = a[i];
  }
}

void printArray(int *a){
  for(int i = 0; i <= 2*size - 1; i++){
    std::cout << "["<< i << "] -> " << a[i] << '\n';
  }
  std::cout << "" << '\n';
}
