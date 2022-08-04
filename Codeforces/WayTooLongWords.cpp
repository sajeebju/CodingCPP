#include<iostream>
#include<cstring>
using namespace std;

int main(){
 int n;
 cin>> n;

 char word[n][101];
 for(int i = 0; i < n; i++){
     cin >> word[i];
 }

 for(int i = 0; i < n; i++){
     if( strlen(word[i]) > n){
    cout << word[i][0] <<  strlen(word[i]) - 2 << word[i][strlen(word[i]) - 1] << endl;
 }
 else{
    cout << word[i] <<endl;
 }
 }
return 0;
 }
