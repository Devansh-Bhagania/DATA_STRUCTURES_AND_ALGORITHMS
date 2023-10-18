#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Mydata {       
  public:             
    int RollNo;        
    string Name;  
    string University;
};

void print(Mydata student){
    cout<<student.RollNo<<endl;
    cout<< student.Name<<endl;
    cout<<student.University<<endl;
    
}

int main() {
  Mydata student;  

  
  student.RollNo = 259; 
  student.Name = "Devansh Bhagania";
  student.University="Chitkara";
    print(student);
 
  
  return 0;
}
