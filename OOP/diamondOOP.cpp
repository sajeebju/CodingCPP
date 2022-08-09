#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BohemianRhapsody{

  public:
      BohemianRhapsody(string s1){
           cout << "Bohemian Rhapsody initiated\n";
      }
};

class Vocalist : public BohemianRhapsody{
   public:
       Vocalist(string s1) : BohemianRhapsody(s1){
          cout << "Vocalist Freddy\n";
       }
};

class Guitarist : public BohemianRhapsody{

   public:
       Guitarist(string s1) : BohemianRhapsody(s1){

         cout << "Guitarist -------\n";
       }
};

class Listeners : public Vocalist, public Guitarist{
  public:
      Listeners(string s1) : Vocalist(s1), Guitarist(s1){

         cout << "We are the fan of queen\n";

      }

};
int main(){

     Listeners l = Listeners("string print");

return 0;
 }
