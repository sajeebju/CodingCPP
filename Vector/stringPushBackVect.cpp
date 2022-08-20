#include<iostream>
#include<vector>

using namespace std;
int main(){

vector<string> letters;
letters.push_back("abc");
string s = "def";
letters.push_back(move(s));
cout << "vector holds: ";
for(auto&&i : letters ){
    cout << quoted(i) << " ";
    cout << "\nMoved-from string holds " << std::quoted(s) << '\n';
}

return 0;
}
