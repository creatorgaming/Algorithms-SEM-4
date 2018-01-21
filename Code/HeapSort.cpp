#include "iostream"
#include <time.h>
#include <stdlib.h>
using namespace std;
#define size 10
#define range 1000
void heapSort(int*,int);
void maxHeapify(int*,int,int);
void display(int*,int);

int main(){
	int *arr = new int[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		int k = 1 + rand()%(range + 1);
		arr[i] = k;
	}
	cout << "EARLIER \n\n";
	display(arr,size);
	heapSort(arr,size);
	cout << "\n\n";
	display(arr,size);
	return 0;
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

void display(int *arr,int s){
	int i = 0;
	while(i < s){
		cout << "| " << arr[i] << " | " << " ";
		i++;
	}
}