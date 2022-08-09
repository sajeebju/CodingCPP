#include<bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &v1, const vector<int> &v2){
  return  v1[0] > v2[1];
}

void printVector2d(vector<vector<int>> & vec){
 sort(vec.begin(), vec.end(), compare);
 for(int i = 0; i < vec.size(); i++){
    for(int j = 0; j < vec[i].size(); j++){
        cout << vec[i][j] <<  " ";
    }
    cout << "\n";
 }

}

signed main(){
vector<vector<int>> vec = {{9, 1}, {54, 32}, {5, 2}};
printVector2d(vec);
return 0;
}
