#include <bits/stdc++.h>
using namespace std;
long long C(long long a, long long b) {
    if ((b < 1) or (a < 1)) {
	return 1;
    } else {
	return C(a - 1, b - 1) + C(a, b - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long o, n, m, t, cm, cd, d, c;
    cout << C(3, 3) << endl;
    cin >> n >> m >> t;
    o = 0;
    c = 4;
    for (long long i = max(t - m, c); i < min(n + 1, t); i++) {
	o += C(n, i) * C(m, t - i);
    }
    cout << o;
}