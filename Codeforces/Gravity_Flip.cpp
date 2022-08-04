#include<bits/stdc++.h>
using namespace std;

int main(){
 int n, m[100];
 cin >> n;

 for(int i = 0; i < n; i++){
    cin >> m[i];
 }
sort(m, m + n);

for(int i = 0; i < n; i++){
    cout << m[i] << " ";

}
return 0;
}
