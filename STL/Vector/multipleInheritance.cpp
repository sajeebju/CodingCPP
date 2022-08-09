#include<iostream>
using namespace std;

class A{

  public:
      A(){

        cout << "As constructor is called\n";
      }
};

class B{

  public:
      B(){
       cout << "Bs constructor is called\n";
      }
};

class C : public B, public A{

  public:
      C(){

        cout << "Cs construtcor is called\n";
      }
};

int main(){

  C c;
  return 0;
}
