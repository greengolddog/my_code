#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	b = a;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> b(n), p(n - 1), u(n - 1), sb, sp, su, col(n - 1, 0);
	for (ll i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (ll j = 0; j < n - 1; j++) {
		cin >> p[j];
	}
	for (ll k = 0; k < n - 1; k++) {
		cin >> u[k];
	}
	sb = b;
	sp = p;
	su = u;
	ll ans = 0;
	for (ll i = 0; i < n - 1; i++) {
		ll x = min(p[i], b[i]);
		col[i] = x;
		p[i] -= x;
		b[i] -= x;
		x = min(p[i], u[i]);
		ans += x;
		p[i] -= x;
		u[i] -= x;
		if (p[i] > b[i + 1]) {
			cout << "NO" << '\n';
			return;
		}
		b[i + 1] -= p[i];
		p[i] = 0;
	}
	for (ll i = n - 2; i >= 0; i--) {
		ll x = min(b[i + 1], su[i] - u[i]);
		ans -= x;
		b[i + 1] -= x;
		u[i] += x;
		x = min(b[i + 1], col[i]);
		b[i + 1] -= x;
		b[i] += x;
	}
	cout << "YES" << '\n';
	cout << ans << '\n';
	p = sp;
	for (ll i = 0; i < n - 1; i++) {
		cout << sb[i] - b[i] << ' ' << su[i] - u[i] << ' ';
		p[i] -= sb[i] - b[i];
		p[i] -= su[i] - u[i];
		cout << p[i] << '\n';
		b[i + 1] += p[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
