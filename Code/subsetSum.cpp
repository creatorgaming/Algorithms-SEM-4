#include<iostream>

using namespace std;

void subset(int*arr,int n,int sum){

}

int main(){
    int n, sum;
    int *array;
    cout << "Enter size of set: ";
    cin >> n;
    array = new int[n];
    cout << "Enter set: \n";
    for(int i = 0;i<n;i++){
        cout << "Element:" << i+1 << " -> ";
        cin>>arr[i];
    }
    cout<<"Enter sum: ";
    cin>>sum;
    subset(array,n,sum);
    return 0;
}