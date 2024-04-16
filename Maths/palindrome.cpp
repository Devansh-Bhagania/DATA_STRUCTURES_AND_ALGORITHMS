#include<iostream>
using namespace std;


int main(){
    int x=-784;
 int digit = 0;
        int rev =0;
        while(x!=0){
            digit = x%10;
            rev = (rev*10)+digit;
           
            x /=10;
        }
        if(x == rev){
            cout<<rev;
            return rev;
        }else{
            cout<<rev;
            return rev;
        }
   
}



// class Solution {
// public:
//     bool isPalindrome(int x) {
       
// };