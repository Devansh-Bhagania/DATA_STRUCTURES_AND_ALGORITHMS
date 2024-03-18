#include <iostream>
using namespace std;


int firstocc(int arr[],int size, int key){
        int start = 0;
        int end = size-1;

        int ans = -1;
        
        int mid = start+(end-start)/2;

        while(start <=end){
            if(arr[mid] == key){
                ans = mid;
                end = mid-1;
            }

            if(arr[mid] <key){
                start = mid+1;
            }else{
                end = mid-1; 
            }

            mid = start+(end-start)/2;
        }
        return ans;
}


int lastocc(int arr[],int size, int key){
        int start = 0;
        int end = size-1;

        int ans = -1;
        
        int mid = start+(end-start)/2;

        while(start <=end){
            if(arr[mid] == key){
                ans = mid;
                start = mid+1;
            }

            if(arr[mid] <key){
                start = mid+1;
            }else{
                end = mid-1; 
            }

            mid = start+(end-start)/2;
        }
        return ans;
}

int main(){
    int even[7] = {2,4,6,8,8,12,18};
    int odd[5]= {3,8,11,14,16};

    int evenindex = firstocc(even, 7 ,8) ;
    int lastindex = lastocc(even, 7,8) ;

    cout <<"the index of the element is"<<evenindex<<endl;
    cout <<"the last index of the element is"<<lastindex<<endl;
    return 0;
}


// ----------------------------

// first step is to find the mid element of the array
// then compare the mid element with the key
// if the mid element is equal to the key then return the index of the mid element
// if the mid element is less than the key then start = mid+1
// if the mid element is greater than the key then end = mid-1
// repeat the process until start is less than or equal to end
// if the element is not found then return -1
// ```



//optimised version of the binary search algorithm
//```cpp
//if the mid of the index if greater than int max value
//so the mid value is taken as above to avoid overflow