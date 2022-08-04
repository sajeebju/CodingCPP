#include<bits/stdc++.h>
using namespace std;

int main(){

 char str[100];
 cin>> str;

 int flag = 1;

 for(int i = 1; i < strlen(str); i++){

        if(str[i] == str[i-1]){

            flag++;

            if(flag == 7){

                cout << "YES";
                return 0;
            }

        }

        else{
            flag = 1;

        }
 }

 cout << "NO" ;
return 0;
}
