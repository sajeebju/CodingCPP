#include<bits/stdc++.h>
using namespace std;

int main(){

char s[100];
cin>>s;

int lower = 0;
int upper = 0;

for(int i = 0; i < strlen(s); i++){
    if(islower(s[i])){
        lower++;
    }
    else if(isupper(s[i])){
        upper++;
    }
}

 char chLower, chUpper;
 if(lower >= upper){
       for(int i =0; i < strlen(s); i++){
    chLower = tolower(s[i]);
    cout << chLower;
 }

 }
 else{

          for(int i = 0; i < strlen(s); i++){
    chUpper = toupper(s[i]);
    cout << chUpper;

 }

 }

return 0;

}
