#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int> &arr, int x){
     for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x){
            return i;
        }
     }
     return -1;
}


int main(){
    vector<int> vec;
    for(int i = 1; i <= 100; i++){
        vec.push_back(i);
    }
    int number = 40;
   int index =  linearSearch(vec, number);

   cout << "Found in " << index << " position" << endl;
   return 0;
}