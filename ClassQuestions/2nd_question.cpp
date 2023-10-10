// convert string into integer 

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
    string ch ;
    cout<<"Please enter the string";
    cin>>ch;
    cout<<typeid(ch).name()<< endl;
    cout<<stoi(ch);
    cout<<typeid(ch).name()<< endl;
    
}
