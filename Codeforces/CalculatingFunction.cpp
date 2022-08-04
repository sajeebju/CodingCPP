#include<iostream>
#define ll long long
using namespace std;

int main(){

 ll n, a;
 cin>>n;

 if(n %2 == 0){
    a = n /2;
 }

 else{
    a = (-1) * ((n+1)/2 );
 }

 cout << a;
 
return 0;
 }
