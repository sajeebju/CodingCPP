 #include <bits/stdc++.h>
using namespace std;

int main(){
    
   char s[1000];
   cin >> s;
    char first = toupper(s[0]);

    vector<char> last;

    for(int i = 1; i < strlen(s); i++){
        last.push_back(s[i]);
    }

    last.insert(last.begin(), first);
    for(auto x : last){

        cout << x;
    }
return 0;
 }
