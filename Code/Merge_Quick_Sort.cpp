#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
#define size 1000
#define range 1000

void print(int[]);

//Functions for merge Sort
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int comparision_m = 0;

//Functions for quick Sort
void quickSort(int[],int,int);
int partition(int[],int,int);
void quickSort_2(int[],int,int);
int partition_2(int[],int,int,int);
int extendLargeRegion(int[],int,int,int);
int extendSmallRegion(int[],int,int,int);
int comparision = 0;


int main(){
	int arr[size];
  int arr1[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		int k = 1 + rand()%(range+1);
		arr[i] = k;
    arr1[i] = k;
	}
	cout << "\nSize : " << size << '\n';
	mergeSort(arr,0,size-1);
	//print(arr);
	cout << "Comparision in Merge Sort : " << comparision_m << endl;

  //quickSort(arr1,0,size-1);
	quickSort_2(arr1,0,size-1);
	//print(arr1);
	cout << "Comparision in Quick Sort : " << comparision << endl;
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
		if(++comparision_m && arr[i] < arr[j])
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

void quickSort_2(int arr[],int first, int last){
	if(first < last){
		int pivotElement = arr[first];
		int splitPoint = partition_2(arr,pivotElement,first,last);
		arr[splitPoint] = pivotElement;
		quickSort_2(arr,first,splitPoint - 1);
		quickSort_2(arr,splitPoint + 1,last);
	}
}


int partition_2(int arr[],int pivot,int first, int last){
	int low,high;
	low = first, high = last;
	while (low < high) {
		int highVac = extendLargeRegion(arr, pivot, low, high);
		int lowVac = extendSmallRegion(arr, pivot, low+1, highVac);
		low = lowVac;
		high = highVac - 1;
	}
	return low;
}

int extendLargeRegion(int arr[], int pivot, int lowVac, int high){
	int highVac, curr;
	highVac = lowVac;
	curr = high;
	while (curr > lowVac) {
		if(arr[curr] < pivot && ++comparision){
			arr[lowVac] = arr[curr];
			highVac = curr;
			break;
		}
		curr--;
	}
	return highVac;
}

int extendSmallRegion(int arr[], int pivot, int low, int highVac){
	int lowVac, curr;
	lowVac = highVac;
	curr = low;
	while (curr < highVac) {
		if(arr[curr] >= pivot && ++comparision){
			arr[highVac] = arr[curr];
			lowVac = curr;
			break;
		}
		curr++;
	}
	return lowVac;
}

//Old Quick Sort
/*
void quickSort(int arr[],int first, int last){
	if(first < last){
		int par = partition(arr,first,last);
		quickSort(arr,first,par - 1);
		quickSort(arr,par + 1,last);
	}
}

int partition(int arr[], int first,int last){
	int pivot = arr[last];
	int i = first - 1;
	for(int j = first; j <= last - 1; j++){
		if(arr[j] < pivot){
			swap(arr[++i],arr[j]);
		}
	}
	swap(arr[last],arr[i+1]);
	return (i + 1);
}
*/


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
