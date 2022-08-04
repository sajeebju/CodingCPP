#include<bits/stdc++.h>
using namespace std;

int main(){

 int lim, bob, count = 0;

 cin >> lim >> bob;

 if(lim > bob){

    count = 0;
 }

 else{

    while(lim<= bob){

        lim = lim*3;
        bob = bob*2;

        count++;
    }
}
cout << count << endl;
return 0;
}
