#include<bits/stdc++.h>
using namespace std;

int main(){

 int n = 10;
 vector<vector<int>> normal;

 normal.resize(n);

 for(int i = 0; i <10; i++){

    for(int j = 0; j < 20; j++){

        normal[i].push_back(j);

    }
 }

 for(int i = 0; i <10; i++){
    for(int j = 0; j < 20; j++){
        cout << normal[i][j] << " ";
    }
    cout << '\n';
 }

return 0;
}
