#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, n, i, z;
    cin >> n;
    i = 2;
    a = 1;
    b = 1;
    while (i < n) {
	i++;
	b += a;
	a = b - a;
    }
    cout << b;
}
