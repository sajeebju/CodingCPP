#include <iostream>    
using namespace std;

bool isCitizen(int x){
    if(x == 0){
        return false;
    }
    return true;

}

struct Person
{
	bool citizenship;
	int age;
};
int main(void) {
	struct Person p;
	p.citizenship = isCitizen(0);
	p.age = 27;
	cout << "Person citizenship: " << p.citizenship << endl;
	cout << "Person age: " << p.age << endl;

	return 0;
}