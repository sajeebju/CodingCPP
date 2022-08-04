#include<bits/stdc++.h>
using namespace std;


int main(){

    int k, n,w;
    cin >> k >> n >> w;

    int sum =  w * (1 + w)/2;
    int total_cost = k * sum;
    int borrow = (total_cost - n);

    if(borrow > 0){
        cout << borrow << endl;
    }

    else{
        cout << 0 << endl;
    }

return 0;
}
