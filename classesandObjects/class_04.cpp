#include<iostream>
using namespace std;

class rectangle{
public:
    int length;
    int breadth;

public:
    rectangle(){
        length = 0;
        breadth = 0;
    }
    rectangle(int l, int b){
        length = l;
        breadth = b;
    }
    void perimeter(){
        cout<<"Perimeter = "<<2*(length + breadth)<<endl;
    }
    void area(){
        cout<<"Area = "<<length*breadth<<endl;
    }
    void display(){
        cout<<"Length = "<<length<<endl<<"Breadth = "<<breadth<<endl;
    }     
};

int main(){
    rectangle rect1(5,5);
    rect1.display();
    rectangle r;
    r.display();

    return 0;
}