#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int> vec){

    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    int range = max - min + 1;

    vector<int> count(range), output(vec.size());

    for(int i = 0; i < vec.size(); i++){
        count[vec[i] - min]++;

    }

    for(int i = 0; i < vec.size(); i++){
        count[i] += count[i - 1];
    }

    for(int i = vec.size() - 1; i >= 0; i--){
        output[count[vec[i] - min] - 1 ] = vec[i];
        count[vec[i] - min]--;
    }
    for(int i = 0; i < vec.size(); i++){
        vec[i] = output[i];
    }
}

void printVec(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}

int main(){
   vector<int> vec= {0, -10, 5, -4, -6, 2, 1, 4, 10};
   countSort(vec);
   printVec(vec);

    return 0;
}