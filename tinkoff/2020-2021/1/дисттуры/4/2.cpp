#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, summ, nd, nn, nk;
    cin >> a >> b;
    vector <long long> arr(a);
    for (long long i = 0; i < a; i++) {
	cin >> arr[i];
    }
    nd = a + 10;
    nn = 0;
    nk = 0;
    for (long long i = 0; i < a; i++) {
	summ = 0;
	for (long long j = i; j < a; j++) {
	    summ += arr[j];
	    if (summ == b) {
		if (nd >= (j - i + 1)) {
		    nd = j - i + 1;
		    nn = i;
		    nk = j;
		}
	    }
	}
    }
    if (nd != a + 10) {
	cout << nn + 1 << ' ' << nk + 1;
    } else {
	cout << -1;
    }
}