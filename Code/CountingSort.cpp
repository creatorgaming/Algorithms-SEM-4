#include "iostream"
#include "stdlib.h"
using namespace std;
#define size 5
#define range 10
void countingSort(int[],int[]);
void print(int[]);

int main() {
  int a[size];
  int b[size + 1] = {0};
  srand(time(NULL));
  for(int i = 0; i < size; i++){
    int ele = 1 + rand()%range;
    a[i] = ele;
  }
  //print(a);
  countingSort(a,b);
  print(b);
  return 0;
}

void countingSort(int a[],int b[]){
  int c[range+1] = {0};
  for(int i = 0; i < size; i++){
    c[a[i]]++;
  }
  for(int i = 2; i <= range; i++){
    c[i] = c[i] + c[i-1];
  }
  for(int j = size - 1; j >= 0; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }
}

void print(int a[]){
  cout << '\n';
  int i = 0;
  while (i < size) {
    cout << "["<<i<<"] : " << a[i] << '\n';
    i++;
  }
}
