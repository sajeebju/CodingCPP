#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
 vector<vector<int>> normal;
 for(ll i = 0; i <10; i++){
    normal.push_back({});
    for(ll j = 0; j <20; j++){
        vector<int> &temp = normal[i];
        temp.push_back(j);
    }
 }

 for(ll i = 0; i <10; i++){
    for(ll j = 0; j <20; j++){
        cout << normal[i][j] << " ";
    }
    cout << "\n";
 }

return 0;
}


