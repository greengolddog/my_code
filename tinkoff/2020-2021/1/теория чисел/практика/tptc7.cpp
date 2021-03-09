#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    double s, mini, f, u, sum_now;
    int a;
    cin >> f >> a;
    s = 0;
    mini = 1000000001;
    for (int i = 2; i <= a; i++) {
	if (a % i == 0) {
	    while (a % i == 0) {
		a = a / i;
		s += 1;
	    }
	    u = i;
	    sum_now = 0;
	    while (u <= f) {
		sum_now += floor(f / u);
		u = u*i;
	    }
	    mini = min(mini, floor(sum_now / s));
	    s = 0;
	}
    }
    if (mini < 1000000001) {
	cout << mini;
    } else {
	cout << 0;
    }
}
