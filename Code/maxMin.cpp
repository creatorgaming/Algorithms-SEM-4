#include<iostream>
#include<cstdlib>
using namespace std;

void maxMin(int*,int);

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
        maxMin(arr,n);
        cout<<"\nEnter Another Array (y/n): ";
        char ch;
        cin>>ch;
        if(ch != 'y')goOn = 0;
        else goOn = 1;
    }
}

void maxMin(int*arr,int n){
  int max,min,mx,mi,k;
  if(n%2!=0){
    max = arr[0];
    min = arr[0];
    k = 1;
  }
  else{
    if(arr[0]>arr[1]){
      max = arr[0];
      min = arr[1];
    }else {
      max = arr[1];
      min = arr[0];
    }
    k = 2;
  }
  for(int i = k;i<n;i=i+2){
    if(arr[i]>arr[i+1]){
      mx = arr[i];
      mi = arr[i+1];
    }else {
      mx = arr[i+1];
      mi = arr[i];
    }
    if(mx>max)max = mx;
    if(mi<min)min = mi;
  }
  cout<<"Maximum Element is : "<<max<<"\n";
  cout<<"Minimum Element is : "<<min<<"\n";
}
