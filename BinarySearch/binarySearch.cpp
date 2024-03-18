#include <iostream>
using namespace std;


int binarySearch(int arr[],int size, int key){
        int start = 0;
        int end = size-1;

        int mid = (end+start)/2;

        while(start <=end){
            if(arr[mid] == key){
                return mid;
            }

            if(arr[mid] <key){
                start = mid+1;
            }else{
                end = mid-1; 
            }

            mid = (end+start)/2;
        }
        return -1;
}


int main(){
    int even[6] = {2,4,6,8,12,18};
    int odd[5]= {3,8,11,14,16};

    int evenindex = binarySearch(odd, 6 ,8) ;

    cout <<"the index of the element is"<<evenindex<<endl;
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