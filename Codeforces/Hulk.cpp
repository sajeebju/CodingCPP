#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>> n;
    if(n== 1){
        cout << "I hate it";
    }
    if( n == 2){
        cout << "I hate that I love it";
    }
    if(n > 2){
        if(n % 2 != 0){
                for(int i = 0; i < ((n-1)/2); i++ ){
                     cout << "I hate that I love that ";
                }
                cout << "I hate it";

        }
        else{
                for(int i = 0; i < ((n) / 2) - 1; i++){
                    cout << "I hate that I love that ";

                }
                cout << "I hate that I love it";
        }
    }
return 0;
 }
