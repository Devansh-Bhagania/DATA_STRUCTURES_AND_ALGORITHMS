#include <iostream>
using namespace std;

class Number
{
private:
    int num;
public:
    Number(int n = 0) : num(n) {

    }

    int display() {
         return num;
          }

    Number operator+(Number& n)
    {
        Number temp;
        temp.num = num + n.num;
        return temp;
    }

    Number operator*(Number& n)
    {
        Number temp;
        temp.num = num * n.num;
        return temp;
    }
};


int main() {
    Number n1(50), n2(78);

    Number n3 = n1 * n2;
    cout << n3.display() << endl;

    return 0;
}