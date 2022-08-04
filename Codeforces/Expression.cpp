#include<bits/stdc++.h>
using namespace std;

int main(){

int arr[3];

for(int i = 0; i < 3; i++){
    cin >> arr[i];

}

int s1 = arr[0] + arr[1]*arr[2];
int s2 = (arr[0] + arr[1]) * arr[2];

int s3 = arr[0] * (arr[1] + arr[2]);
int s4 = arr[0] * arr[1] + arr[2];

int s5 = arr[0] * arr[1] * arr[2];
int s6 = arr[0] + arr[1] + arr[2];


int finalArr[6] = {s1, s2, s3, s4, s5, s6};
int n = sizeof(finalArr) / sizeof(finalArr[0]);
cout << *max_element(finalArr , finalArr + n);

return 0;
}
