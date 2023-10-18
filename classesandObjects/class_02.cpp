#include<iostream>
using namespace std;

class student{
public:
    string name;
    int rollNumber;
    string course;
    string university;
};

void print(student Deepanshu){
    cout<<"Name : "<<Deepanshu.name<<endl;
    cout<<"Course : "<<Deepanshu.course<<endl;
    cout<<"Roll Number : "<<Deepanshu.rollNumber<<endl;
    cout<<"University : "<<Deepanshu.university<<endl;
}
 
int main(){

    student Deepanshu;
    Deepanshu.course = "Computer Science";
    Deepanshu.name = "Deepanshu Jindal";
    Deepanshu.rollNumber = 255;
    Deepanshu.university = "Chitkara University";
    print(Deepanshu);

    return 0;
}