#include<bits/stdc++.h>
using namespace std;

int main(){

 char s[100];
 char t[100];
 char r[100];

 cin >> s >> t ;

 int i = 0;
 int j;
 int len = 0;

 while(s[i] != '\0'){
    i++;
    len++;
 }


  for(j = 0, i = len-1; i >= 0; i--, j++){

    r[j] = s[i];
  }

  r[j] = '\0';


 if(strcmp(t, r) == 0){

    cout << "YES" << endl;
 }

 else {

    cout << "NO" << endl;
 }

return 0;
}