#include "iostream"
#include "math.h"
#include "stdlib.h"
#include "time.h"
using namespace std;
#define size 10
#define range 100
#define range2 10
#define noOfDigits 3
void extract(int[]);
void display(int[],int);
void countingSort(int[],int[]);

int main() {
  int a[size];
  srand(time(NULL));
  for(int i = 0; i < size; i++){
    int ele = 1 + rand()%range;
    a[i] = ele;
  }
  cout << "INITIAL ARRAY";
  display(a,size);
  extract(a);
  return 0;
}

void extract(int a[]){
  int *digits = new int[size];
  for(int i = 1; i <= noOfDigits; i++){
    for(int j = 0; j < size; j++){
      int power = pow(10,i);
      int temp = a[j] % power;
      if(i >= 2){
        int power2 = pow(10,i-1);
        temp = temp / power2;
      }
      digits[j] = temp;
    }
    countingSort(digits,a);
    display(a,size);
  }
}


void countingSort(int digits[],int a[]){
  int c[range2] = {0};
  int b[size+1] = {0};
  for(int i = 0; i < size; i++){
    c[digits[i]]++;
  }
  for(int i = 1; i < range2; i++){
    c[i] = c[i] + c[i-1];
  }
  for(int j = size - 1; j >= 0; j--){
    b[c[digits[j]] - 1] = a[j];
    c[digits[j]]--;
  }

  for(int l = 0; l < size; l++){
    a[l] = b[l];
  }
  //display(b,size);
}


void display(int a[], int s){
  int i = 0;
  cout << '\n';
  while (i < size) {
    cout << "["<<i<<"] : " << a[i] << '\n';
    i++;
  }
}
