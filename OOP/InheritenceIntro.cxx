#include<iostream>
using namespace std;

class Person{
    int id;
    char name[100];

 public:
 void set_p(){

   cout << "Enter id number : " << endl;
   cin >> id;
   fflush(stdin);
   cout << "Enter name : " << endl;
   cin.get(name, 100);
   
 }

 void display_p(){
    cout << endl << "Name : " << name << endl;
    cout << "ID : " << id << endl;
 }

};

class Student : public Person{
  
  char course[50];
  int fee;

  public:
  void set_s(){
    
    set_p();
    cout << "Enter the course name : " << endl;
    fflush(stdin);
    cin.getline(course, 50);
    cout << "Enter course fee : " << endl;
    cin >> fee;
  }

  void display_s(){

     display_p();
     cout << "Course : " << course << endl;
     cout << "Fee : " << fee << endl;
  }
};

int main(){
Student s;
s.set_s();
s.display_s();

    return 0;
}