#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, s;
    cin >> a;
    s = 0;
    for (int i = 2; i*i <= a; i++) {
	if (a % i == 0) {
	    s = 1;
	    cout << "composite";
	    break;
	}
    }
    if (s == 0) {
	cout << "prime";
    }
}
