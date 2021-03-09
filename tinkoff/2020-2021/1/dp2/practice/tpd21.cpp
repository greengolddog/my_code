#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b, c, sum;
    cin >> n >> a >> b >> c;
    vector<ll> arr(n);
    sum = 1;
    arr[0] = 1;
    for (ll i = 1; i < n; i++) {
	if ((i - a) >= 0) {
	    arr[i] = arr[i - a];
	}
	if ((i - b) >= 0) {
	    arr[i] = max(arr[i], arr[i - b]);
	}
	if ((i - c) >= 0) {
	    arr[i] = max(arr[i], arr[i - c]);
	}
	if (arr[i] == 1) {
	    sum++;
	}
    }
    cout << sum;
}
