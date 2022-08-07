#include<iostream>
#include<string.h>
using namespace std;

class Person{
    int id;
    char name[100];

    public:
    void set_p(int, char[]);
    void display_p();

};

void Person::set_p(int id, char n[]){

    this->id = id;
    strcpy(this->name , n);
}

void Person::display_p(){

    cout << "Id : " << id << endl;
    cout << "Name : " << name << endl;
}

class Student: private Person{

    char course[50];
    int fee;

    public:
    void set_s(int, char[], char[], int);
    void display_s();
};

void Student::set_s(int id, char n[], char c[], int f){
  set_p(id, n);
  strcpy(this->course, c);
  this->fee = f;

}

void Student::display_s(){
    display_p();
    cout << "Course : " << course << endl;
    cout << "Fee : " << fee << endl;
}

int main(){
  
  Student s;
  s.set_s(10000, "Ahasan", "Exploration Geophysics", 2000);
  s.display_s();

    return 0;
}