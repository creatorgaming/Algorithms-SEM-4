#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void heapSort(int*,int);
void maxHeapify(int*,int,int);

int main(){
    srand(time(NULL));
    int goOn = 1,n;
    while(goOn){
        cout<<"Enter Size of Array\n";
        cin>>n;
        int*arr = new int[n];
        for(int  i = 0;i<n;i++)arr[i] = 1+rand()%1000;
        for(int  i = 0;i<n;i++)cout<<arr[i]<<" || ";
        cout<<"\n";
        heapSort(arr,n);
        for(int  i = 0;i<n;i++)cout<<arr[i]<<" || ";
    }
}

void heapSort(int*arr,int n){
    for(int i = (n/2)-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    for(int i = n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

void maxHeapify(int*a,int n,int k){
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