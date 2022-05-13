#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

mt19937_64 rnd(time(0));

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	ll n = s.size();
	ll k;
	cin >> k;
	unordered_map<string, ll> m;
	if (n <= 20) {
		ll cc = 0;
		for (ll i = 0; i < (1 << n); i++) {
			ll cnt = 0;
			for (ll j = 0; j < n; j++) {
				cnt += (i >> j) & 1;
			}
			if (cnt == k) {
				string as;
				for (ll j = 0; j < n; j++) {
					if ((i >> j) & 1) {
						as.push_back(s[j]);
					}
				}
				m[as]++;
				cc++;
			}
		}
		for (auto[a, b] : m) {
			if (b >= (cc + 1) / 2) {
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	if (k == 1) {
		ll cc = 0;
		for (ll i = 0; i < n; i++) {
			string as;
			as.push_back(s[i]);
			m[as]++;
			cc++;
		}
		for (auto[a, b] : m) {
			if (b >= (cc + 1) / 2) {
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	if (k == 2) {
		ll cc = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = i + 1; j < n; j++) {
				string as;
				as.push_back(s[i]);
				as.push_back(s[j]);
				m[as]++;
				cc++;
			}
		}
		for (auto[a, b] : m) {
			if (b >= (cc + 1) / 2) {
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	ll N = 150'000'000 / n;
	for (ll i = 0; i < N; i++) {
		string as;
		ll last = 0;
		for (ll j = 0; j < k; j++) {
			ll num = rnd() % (n - last - (k - j - 1)) + last;
			last = num + 1;
			as.push_back(s[num]);
		}
		m[as]++;
	}
	for (auto[a, b] : m) {
		if (b >= (N + 1) / 2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
