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
	matrix(ll n, ll m, ll um = 0, ll p = 1000000007): n(n), m(m), mod(p) {
		arr.resize(n, vector<ll>(m, um));
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
	n--;
	if (n == 0) {
		cout << 9;
		return 0;
	}
	matrix ans(10, 1, 1);
	ans.arr[0][0] = 0;
	matrix m(10, 10);
	m.arr[0][0] = 1;
	m.arr[0][1] = 1;
	for (ll i = 1; i < 9; i++) {
		m.arr[i][i-1] = 1;
		m.arr[i][i] = 1;
		m.arr[i][i+1] = 1;
	}
	m.arr[9][8] = 1;
	m.arr[9][9] = 1;
	m = m^n;
	m = m*ans;
	ll a = 0;
	for (ll i = 0; i < 10; i++) {
		a += m.arr[i][0];
	}
	cout << a%1000000007;
}
