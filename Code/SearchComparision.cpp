#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
#define size 1000
#define range 1000
void linearSearch(int[]);
void binarySearch(int[]);
void print(int[]);
void bubbleSorting(int[]);

int main(){
	int arr[size];
	int arr1[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		int k = 1 + rand()%(range+1);
		arr[i] = k;
		arr1[i] = k;
	}
	std::cout << "\nSize : " << size << '\n';
	linearSearch(arr);
	bubbleSorting(arr1);
	//print(arr1);
	binarySearch(arr1);
	return 0;
}

void linearSearch(int arr[]){
	int comparison = 0;
	for(int i = 0; i < size; i++){
		int eleSearch = arr[i];
		for(int j = 0; j < size; j++){
			if(++comparison && eleSearch == arr[j]){
				break;
			}
		}
	}
	cout << "Comparison For Linear Search:- " << comparison << endl;
}

void binarySearch(int arr[]){
	int comparison = 0;
	for(int i = 0; i < size; i++){

		int start = 0;
		int end = size - 1;
		int mid = end + start / 2;
		int ele = arr[i];

		while(start <= end && arr[mid] != ele){
			++comparison;
			if(ele > arr[mid])
				start = mid + 1;
			else
				end = mid - 1;
			mid = (end + start) / 2;
		}
	}

	cout << "Comparison For Binary Search:- " << comparison << endl;
}

void bubbleSorting(int arr[]){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}


void print(int arr[]){
	cout << endl;
	int len = 0;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " | ";
		if(len == 24){
			len = 0;
			cout << endl;
		}
		len++;
	}
}
