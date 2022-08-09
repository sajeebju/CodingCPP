#include<bits/stdc++.h>
using namespace std;

void printVector(int N){
   vector<int> vect1;
   vector<int> vect2;

   for(int i = 1; i <= N; i++){
    if(i % 3 == 0){
        vect1.push_back(i);
    }
   }
   for(int i = 0; i < N; i++){
    if(i % 5 == 0){
        vect2.push_back(i);
    }
   }
   vect1.insert(vect1.end(), vect2.begin(), vect2.end());
   vector<int>::iterator itr;

   // print vector

   for(auto itr = vect1.begin(); itr != vect1.end(); ++itr){
    cout << *itr << " ";
   }
}

int main(){

 int N = 100000;
 printVector(N);
return 0;
}
