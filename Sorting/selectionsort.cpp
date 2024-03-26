#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n){
        for(int i=0;i<=n-2;i++){
            int mini = i;
            for(int j=i;j<=n-1;j++){
                if(arr[j] < arr[mini]){
                    mini = j;
                }       
                   
            }
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;    
        }
}


int main(){
    cout <<"hello enter number of elements \n";
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i<n; i++){
        cin >> arr[i];
    }
    // n = 5;
    // int arr[5] = {1,4,3,6,5};
    selectionsort(arr, n);
    for (int i =0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}