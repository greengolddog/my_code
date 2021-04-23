#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, r, l, s1, s2, s3, summ, sn, c, i, j;
    cin >> n;
    vector<ll> arr(n);
    summ = 0;
    for (i = 0; i < n; i++) {
	cin >> arr[i];
	summ += arr[i];
    }
    s1 = 0;
    s2 = arr[0];
    s3 = summ - arr[0];
    c = 0;
    for (i = 0; i < (n - 2); i++) {
	s1 += arr[i];
	s2 = 0;
        s3 = summ - s1;
	for (j = i + 1; j < (n - 1); j++) {
	    sn = 0;
	    s2 += arr[j];
	    s3 -= arr[j];
	    if (s1 > 0) {
		sn += 1;
	    }
	    if (s2 > 0) {
		sn += 1;
	    }
	    if (s3 > 0) {
		sn += 1;
	    }
	    if (sn >= 2) {
		c = 1;
		break;
	    }
	}
	if (c == 1) {
	    break;
	}
    }
    if (c == 0) {
	cout << 0;
    } else {
	cout << i + 1 << ' ' << j - i << ' ' << n - j - 1;
    }
}