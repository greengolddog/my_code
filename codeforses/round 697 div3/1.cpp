#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
    	ll n, m, c = 0, om = 0, u1 = 0, u2 = 0;
    	cin >> n >> m;
    	vector<ll> arr1(n + 1, 0);
    	vector<ll> arr2(n + 1, 0);
	vector<ll> arr(1, 0);
    	for (long long i = 1; i <= n; i++) {
	    cin >> c;
	    arr.push_back(c);
    	}
    	for (long long i = 1; i <= n; i++) {
	    cin >> c;
	    if (c == 1) {
		arr1.push_back(arr[i]);
	    } else {
		arr2.push_back(arr[i]);
	    }
    	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	while ((om < m) and ((u1 > 0) or (u2 > 0))) {
	    if ((om + arr1[u1]) < m) {
		c += 2;
		if ((arr1[u1] + arr1[u1 - 1]) <= arr2[u2]) {
		    om += arr2[u2];
		    u2--;
		} else {
		    om += arr1[u1] + arr1[u1-1];
		    u1 -= 2;
		}
	    } else {
		om = m;
		c++;
	    }
	}
	if (om < m) {
	    cout << -1 << endl;
	} else {
	    cout << c << endl;
	}
    }
}
