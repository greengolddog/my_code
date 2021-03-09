#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, s;
    cin >> a;
    s = 0;
    for (int i = 1; i*i <= a; i++) {
	if (a % i == 0) {
	    if (i * i == a) {
		s += 1;
	    } else {
		s += 2;
	    }
	}
    }
    cout << s;
}
