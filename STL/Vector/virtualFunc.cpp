#include<bits/stdc++.h>
using namespace std;

class base{


 virtual void func1(){

    cout << "func1"<< endl;
 }

};

class derived : public base{

   void func1(){

     cout << "func1" << endl;
   }


};


int main(){

 derived d;
 d.func1();

return 0;
}
