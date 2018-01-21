#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
#define size 1000
#define range 1000
void print(int[]);
void bubbleSort(int[]);
void selectionSort(int[]);
void insertionSort(int[]);

int main(){
	int arr[size];
	int arr1[size];
	int arr2[size];
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		int k = 1 + rand()%(range+1);
		arr[i] = k;
		arr1[i] = k;
		arr2[i] = k;
	}
	std::cout << "\nSize : " << size;
	bubbleSort(arr);
	selectionSort(arr1);
	insertionSort(arr2);
	//print(arr);
	return 0;
}

void bubbleSort(int arr[]){
	int comparision = 0;
	bool sorted = false;
	for(int i = 0; !sorted && i < size - 1; i++){
		sorted = true;
		for(int j = 0; j < size - i; j++){
			if(++comparision && arr[j] > arr[j+1]){
				sorted = false;
				swap(arr[j],arr[j+1]);
			}
		}
	}
	cout << "\nComparision in Bubble sort    : " << comparision << endl;
}

void selectionSort(int arr[]){
	int comparision = 0;
	int pos = 0, k;
	for(int j = 0; j < size - 1; j++){
			pos = j;
			k = j+1;
			while (k < size) {
				if(++comparision && arr[k] < arr[pos]){
					pos = k;
				}
				k++;
			}
			swap(arr[pos],arr[j]);
	}
	cout << "Comparision in Selection sort : " << comparision << endl;
}

void insertionSort(int arr[]){
	int comparision = 0;
	int k = 0;
	for(int j = 0; j < size; j++){
			int temp = arr[j];
			k = j - 1;
			while (++comparision &&	k >= 0 && arr[k] > temp) {
				arr[k+1] = arr[k];
				k--;
			}
			arr[k+1] = temp;
	}
	cout << "Comparision in Insertion Sort : " << comparision << endl;
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
