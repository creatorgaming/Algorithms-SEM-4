#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
#define size 100
#define range 1000
void print(int[]);
void mergeSort(int[],int,int);
void merge(int[],int,int,int);

int main(){
	int arr[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		int k = 1 + rand()%(range+1);
		arr[i] = k;
	}
	mergeSort(arr,0,size-1);
	print(arr);
	return 0;
}

void mergeSort(int arr[],int first, int last){
	if(first >= last)
		return;

	int mid = ( first + last ) / 2;
	mergeSort(arr,first,mid);
	mergeSort(arr,mid+1,last);
	merge(arr,first,mid,last);
}

void merge(int arr[], int first,int mid,int last){
	int len = last - first + 1;
	int *temp = new int[len];
	int i = first, j = mid + 1, k = 0;

	while (i <= mid && j <= last) {
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= last) {
		temp[k++] = arr[j++];
	}

	for(i = first, j = 0; j < len; j++, i++){
		arr[i] = temp[j];
	}
	delete[] temp;
}

void print(int arr[]){
	cout << endl;
	int len = 0;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " || ";
		if(len == 24){
			len = 0;
			cout << endl;
		}
		len++;
	}
	std::cout << '\n';
}
