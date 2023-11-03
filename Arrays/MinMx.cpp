#include<iostream>
using namespace std;
#include<limits.h>

int getMax (int arr[], int n){

    int max = INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int getMin (int arr[], int n){

    int min = INT_MAX;

    for(int i=0; i<n; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    cout<<"Enter the size of the array: \n";
    int size;
    cin>>size;



    int arr[100];
    cout<<"Enter the elements of the array: \n";
    for(int i=0; i<size;i++){
        cin>>arr[i];
    }

    cout << "The maximum value of this array is" << getMax(arr,size) << endl;
    cout << "The minimum value of this array is" << getMin(arr,size) << endl;
    
    return 0;
}
