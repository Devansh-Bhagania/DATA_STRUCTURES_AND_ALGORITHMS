#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int size,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size&&arr[largest]<arr[left]){
		largest=left;
	}
	if(right<size&&arr[right]>arr[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,size,largest);
	}
}



// Heap sort ==========================================

void heapsort(int arr[], int n){
    int size = n;

    while(size>1){
        swap(arr[size] ,arr[1])
        size--;

        heapify(arr,size,1);
    }
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=(n/2)-1;i>=0;i--){
		heapify(arr,n,i);
	}


	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	heapsort(arr,n);
		for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}