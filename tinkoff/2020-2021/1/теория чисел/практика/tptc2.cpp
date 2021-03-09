#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, max;
    cin >> n;
    max = n;
    for (int i = 2; i * i <= n; i += 1) {
	if (n % i == 0) {
	    max = i;
	    break;
	}
    }
    cout << n / max << ' ' << n / max * (max - 1);
}