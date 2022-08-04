#include<iostream>
using namespace std;

int main(){
 int n = 1000000000;
 int k;
 int r;
 cin >> n >> k;
 for(int i = 0; i < k; i++){
    r = (n%10);
    if(r != 0){
        n = n - 1;
    }
    else{
        n = n / 10;
    }
 }
cout << n;
return 0;
 }
