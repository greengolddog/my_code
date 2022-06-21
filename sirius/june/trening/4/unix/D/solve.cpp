#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<bool> b(31, false);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 31; j++) {
			if ((arr[i] >> j) & 1) {
				b[j] = true;
			}
		}
	}
	vector<ll> ans;
	for (ll i = 0; i < 31; i++) {
		if (b[i]) {
			ans.push_back(1 << i);
		}
	}
	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	for (auto i : arr) {
		bool b = false;
		ll x = 0;
		while (i > 0) {
			if (i % 2 == 1) {
				if (b) {
					cout << '+';
				}
				b = true;
				cout << (1 << x);
			}
			x++;
			i /= 2;
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
