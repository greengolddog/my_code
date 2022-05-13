#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mex(vector<ll> arr) {
	if (arr.size() == 0) {
		return 0;
	}
	sort(arr.begin(), arr.end());
	if (arr[0] > 0) {
		return 0;
	}
	for (ll i = 0; i < arr.size() - 1; i++) {
		if (arr[i] + 1 < arr[i + 1]) {
			return arr[i] + 1;
		}
	}
	return arr.back() + 1;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("karlsson.in", "r", stdin);
	freopen("karlsson.out", "w", stdout);
	ll a, b, c;
	cin >> a >> b >> c;
	const ll sz = 5001;
	vector<ll> arr(sz, 0);
	for (ll i = 2; i < sz; i++) {
		vector<ll> m;
		for (ll j = (i + 1) / 2; j < i; j++) {
			m.push_back(arr[j]);
		}
		arr[i] = mex(m);
	}
	if (arr[a] ^ arr[b] ^ arr[c]) {
		cout << "YES" << endl;
		for (ll i = (a + 1) / 2; i < a; i++) {
			if ((arr[i] ^ arr[b] ^ arr[c]) == 0) {
				cout << i << ' ' << b << ' ' << c << endl;
				return 0;
			}
		}
		for (ll i = (c + 1) / 2; i < c; i++) {
			if ((arr[a] ^ arr[b] ^ arr[i]) == 0) {
				cout << a << ' ' << b << ' ' << i << endl;
				return 0;
			}
		}
		for (ll i = (b + 1) / 2; i < b; i++) {
			if ((arr[a] ^ arr[i] ^ arr[c]) == 0) {
				cout << a << ' ' << i << ' ' << c << endl;
				return 0;
			}
		}
	} else {
		cout << "NO";
	}
}
