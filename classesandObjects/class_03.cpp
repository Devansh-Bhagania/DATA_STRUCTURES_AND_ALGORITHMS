#include<iostream>
using namespace std;

struct student{
    public:
    string noodles;
    string cookies;
    string chips;

    friend class student2;
};

class student2{
    public:
    void display(student &obj){
        cout<<"Noodles : "<<obj.noodles<<endl;
        cout<<"Cookies : "<<obj.cookies<<endl;
        cout<<"Chips : "<<obj.chips<<endl;
    }
};

int main(){
    student deepak;
    student2 devansh;
    deepak.noodles = "Maggie";
    deepak.cookies = "Oreo";
    deepak.chips = "Lays";
    devansh.display(deepak);
    return 0;
}