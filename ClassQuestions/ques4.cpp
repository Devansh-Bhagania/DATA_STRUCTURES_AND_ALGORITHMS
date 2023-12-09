#include<iostream>

using namespace std;

class numbe
{
    private:

    int a;

    public:

    numbe()
    {
        a=10;
    }

    numbe(int c)
    {
        a=c;
    }

    void display()
    {
        cout<<"num ="<<a<<endl;
    }
    numbe operator * (numbe b)
    {
        numbe c3;
        c3.a= a * b.a;
        return c3;

    } 


};

int main()
{
    numbe a(2),b(3),c;
    c=a*b;
    c.display();

}