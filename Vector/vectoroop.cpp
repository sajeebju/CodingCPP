#include<bits/stdc++.h>
using namespace std;

class Solution{

public:
template<typename T>

void func(T& v1, T& v2, int n1, int n2){

  vector<int>:: iterator itr;
  itr = find(v1.begin(), v1.end(), n1);
  if(itr != v1.end()){
    cout << "Index of " << n1 << " in the vector is " << itr - v1.begin() << endl;
  }
  else{
    cout << n1 << " not found in the vector" << endl;
  }

  vector<int> :: iterator it;

  it = find(v2.begin(), v2.end(), n2);

  if(it != v2.end()){
    cout << "Index of " << n2 << " in the vector is " << it - v2.begin() << endl;
  }
  else{
     cout << n2 << " not found in the vector" << endl;
  }
}

};

int main(){


Solution s;

vector<int> v1;
vector<int> v2;


 for(int i = 0; i <= 1000; i++){
    if(i % 3 == 0){
        v1.push_back(i);
    }
  }

  for(int i = 0; i <= 1000; i++){
    if(i % 5 == 0){
        v1.push_back(i);
    }
  }

  int n1 = 99;
  int n2 = 555;

  s.func(v1, v2, n1, n2);

return 0;
}
