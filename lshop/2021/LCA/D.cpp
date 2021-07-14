#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct rectangle {
	ll x1, y1, x2, y2;
	rectangle(ll x1 = 0, ll y1 = 0, ll x2 = 0, ll y2 = 0): x1(x1), y1(y1), x2(x2), y2(y2) {}
	ll operator~() {
		return (x2-x1)*(y2-y1);
	}
	rectangle operator*(rectangle& r) {
		return rectangle(max(x1, r.x1), max(y1, r.y1), min(x2, r.x2), min(y2, r.y2));
	}
};

struct Sparse_Table {
	vector<vector<rectangle>> bin;
	vector<ll> pow, t;
	ll max_pow = 30, size;
	Sparse_Table(vector<rectangle> arr) {
		size = arr.size();
		pow.push_back(1);
		for (ll i = 1; i < max_pow; i++) {
			pow.push_back(pow.back()*2);
		}
		t.resize(size+1, 0);
		for (ll i = 1; i <= size; i++) {
			if (pow[t[i-1]+1] == i) {
				t[i] = t[i-1]+1;
			} else {
				t[i] = t[i-1];
			}
		}
		bin.resize(max_pow, vector<rectangle>(size, 0));
		for (ll i = 0; i < size; i++) {
			bin[0][i] = arr[i];
		}
		for (ll s = 1; s < max_pow; s++) {
			for (ll i = 0; i <= (size-pow[s]); i++) {
				bin[s][i] = bin[s-1][i] * bin[s-1][i+pow[s-1]];
			}
		}
	}
	rectangle get(ll l, ll r) {
		return bin[t[r-l]][l] * bin[t[r-l]][r-pow[t[r-l]]];
	}
	Sparse_Table operator+ (Sparse_Table& t) {
		Sparse_Table ans(vector<rectangle>(size, rectangle()));
		for (ll s = 0; s < max_pow; s++) {
			for (ll i = 0; i <= (size-pow[s]); i++) {
				ans.bin[s][i] = bin[s][i] * t.bin[s][i];
			}
		}
	}
};

struct Sparse_Table_2D {
	vector<vector<Sparse_Table>> bin;
	vector<ll> pow, t;
	ll max_pow = 30, size;
	Sparse_Table_2D(vector<Sparse_Table>& arr) {
		size = arr.size();
		pow.push_back(1);
		for (ll i = 1; i < max_pow; i++) {
			pow.push_back(pow.back()*2);
		}
		t.resize(size+1, 0);
		for (ll i = 1; i <= size; i++) {
			if (pow[t[i-1]+1] == i) {
				t[i] = t[i-1]+1;
			} else {
				t[i] = t[i-1];
			}
		}
		bin.resize(max_pow, vector<Sparse_Table>(size, 0));
		for (ll i = 0; i < size; i++) {
			bin[0][i] = arr[i];
		}
		for (ll s = 1; s < max_pow; s++) {
			for (ll i = 0; i <= (size-pow[s]); i++) {
				bin[s][i] = bin[s-1][i] + bin[s-1][i+pow[s-1]];
			}
		}
	}
	rectangle get(ll l, ll r, ll lv, ll rv) {
		return bin[t[r-l]][l].get(lv, rv) * bin[t[r-l]][r-pow[t[r-l]]].get(lv, rv);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll mod = 1000000007;
	ll n, m;
	cin >> n >> m;
	vector<rectangle> arr(m, 0);
	vector<Sparse_Table> all;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[j].x1 >> arr[j].y1 >> arr[j].x2 >> arr[j].y2;
		}
		all.push_back(Sparse_Table(arr));
	}
	Sparse_Table_2D next(all);
	ll q;
	cin >> q;
	ll A, B;
	vector<ll> v(q*5, 0);
	cin >> A >> B >> v[0];
	for (ll i = 1; i < q*5; i++) {
		v[i] = (A*v[i-1]+B)%mod;
	}
	ll ans = 0;
	for (ll i = 1; i <= q; i++) {
		ll r1 = v[4*i-3]%n, r2 = v[4*i-1]%n, c1 = v[4*i-2]%m, c2 = v[4*i]%m;
		ans += ~next.get(min(r1, r2), max(r1, r2), min(c1, c2), max(c1, c2));
		ans = ans%mod;
	}
	cout << ans;
}
