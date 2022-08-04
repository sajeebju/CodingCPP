#include<iostream>
#include<cmath>
using namespace std;

int main(){

  int x;
  cin>>x;
  
  double res;
 if(x == 1 || x==2 || x ==3 || x == 4 || x == 5){

    res = 1;
 }

 else{
    res = ceil((float) x / 5);
 }

 cout << res;
return 0;
}
