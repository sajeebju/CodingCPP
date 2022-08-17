#include<bits/stdc++.h>
using namespace std;

template<typename T>
void print_queue(T& q){
  while(!q.empty()){
    cout << q.top() << " ";
    q.pop();
  }
  cout << "\n";
}

int main(){
 priority_queue<int> q;
 for(int elm : {1,8,5,6,3,4,0,9,72}){q.push(elm);}
 print_queue(q);

return 0;
}
