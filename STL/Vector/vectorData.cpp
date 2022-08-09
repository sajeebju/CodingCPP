#include<bits/stdc++.h>
using namespace std;
int main(){

vector<int> vect = {1,2,3,4,5};
int *pos = vect.data();
for(int i = 0;  i<= vect.size(); i++){
    cout << *pos++ << " ";
}
return 0;
}
