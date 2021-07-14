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
	ll n;
	cin >> n;
	if (n == 0) {
		cout << 
	matrix m(3, 3, 1000000007);
	m.arr[0][0] = 1;
	m.arr[0][1] = 1;
	m.arr[1][0] = 1;
	m.arr[2] = vector<ll>(3, 1);
	m = m ^ n;
	matrix s(3, 1, 1000000007);
	s.arr[0][0] = 1;
	s.arr[1][0] = 1;
	s.arr[2][0] = 2;
	s = m * s;
	cout << s.arr[1][0] << ' ' << s.arr[1][0]
}
