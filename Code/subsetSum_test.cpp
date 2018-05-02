#include<iostream>

using namespace std;

bool subsetSum(int*arr,int n,int sum){
    bool arr2d[n+1][sum+1];
    for(int i = 0;i<=n;i++)arr2d[i][0] = true;
    for(int i = 0;i<=sum;i++)arr2d[0][i] = false;

    for(int i = 1; i <=n; i++){
        for(int j = 1 ;j<=sum;j++){

            if(arr[i-1] > j)arr2d[i][j] = arr2d[i-1][j];
            else {
                arr2d[i][j] = arr2d[i-1][j] || arr2d[i-1][j-arr[i-1]];
            }

        }
    }
    return arr2d[n][sum];
}

int main(){
    int n, sum;
    int*arr;
    cout<<"Enter size of set : ";
    cin>>n;
    arr=new int[n];
    cout<<"Enter Set\n";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter sum value : ";
    cin>>sum;

    if(subsetSum(arr,n,sum))
        cout<<"Subset with given sum found\n";
    else 
        cout<<"Subset with given sum not found\n";
}