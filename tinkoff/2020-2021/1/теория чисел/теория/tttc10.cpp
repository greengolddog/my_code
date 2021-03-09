#include <iostream>
#include <algorithm>
using namespace std;

int power_mod(int a, int b, int c) {
    if (b == 0) {
	return 1 % c;
    }
    if (b % 2 == 1) {
	return power_mod(a, b-1, c) * a % c;
    }
    int res = power_mod(a, b/2, c);
    return res * res % c;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << power_mod(a, b, c);
}
