#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class MyClass {       
  public:             
    int RollNo;        
    string Name;  
    string University;
};

int main() {
  MyClass myObj;  

  
  myObj.RollNo = 259; 
  myObj.Name = "Devansh";
  myObj.University="Chitkara";

 
  cout << myObj.RollNo << "\n";
  cout << myObj.Name<< "\n";
  cout << myObj.University << "\n";
  return 0;
}