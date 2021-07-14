#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct matrix {
	vector<vector<ll>> arr;
	ll n, m, mod;
	matrix(vector<vector<ll>>& arr, ll p): arr(arr), mod(p) {
		n = arr.size();
		m = (n > 0 ? arr[0].size() : 0);
	}
	matrix(ll n, ll m, ll p, istream& inp): n(n), m(m), mod(p) {
		arr.resize(n, vector<ll>(m, 0));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				inp >> arr[i][j];
			}
		}
	}
	matrix(ll n, ll m, ll p): n(n), m(m), mod(p) {
		arr.resize(n, vector<ll>(m, 0));
	}
	matrix operator* (matrix m2) {
		matrix ans(n, m2.m, mod);
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m2.m; j++) {
				for (ll k = 0; k < m; k++) {
					ans.arr[i][j] += arr[i][k]*m2.arr[k][j];
					ans.arr[i][j] = ans.arr[i][j]%mod;
				}
			}
		}
		return ans;
	}
	matrix operator^ (ll p) {
		matrix a = *this;
		matrix ans = a;
		p--;
		while (p > 0) {
			if (p & 1) {
				ans = ans * a;
			}
			a = a*a;
			p = p/2;
		}
		return ans;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("mpow.in", "r", stdin);
	freopen("mpow.out", "w", stdout);
	lr n, m, p;
	cin >> n >> m >> p;
	if (m == 0) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				cout << (i == j ? 1 : 0) << ' ';
			}
			cout << '\n';
		}
		return 0;
	}
	matrix ma(n, n, p, cin);
	ma = ma ^ m;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cout << ma.arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
