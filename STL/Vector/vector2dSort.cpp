#include<bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &v1, const vector<int> &v2){
   return (v1[0] < v2[1]);
}

void printOriginalVector(vector<vector<int>> & vec){
    cout << "Original vector is:\n";
    for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec[i].size(); ++j){
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}

void printSortedVector(vector<vector<int>> & vec){
   sort(vec.begin(), vec.end(), compare);

   cout << "Sorted Vector is :\n";
   for(int i = 0; i < vec.size(); ++i){
        for(int j = 0; j < vec[i].size(); ++j){
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}


int main(){

 vector<vector<int>> vec = {{1,2,3}, {8,7,6}, {11, 22, 33}};
 printOriginalVector(vec);
 printSortedVector(vec);

return 0;
}
