#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect1{ 10, 20, 30 };
    vector<int> vect2(vect1.begin(), vect1.end());
    vector<int> vect3(vect2.begin(), vect2.end());

    for (int x : vect3)
        cout << x << " ";

    return 0;
}
