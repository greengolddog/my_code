#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll f = 0;

struct s {
	ll a, b, c, d;
	s(ll a, ll b, ll c, ll d): a(a), b(b), c(c), d(d) {}
	bool p(vector<ll>& arr) {
		ll ia = arr[a-1], ib = arr[b-1], ic = arr[c-1], id = arr[d-1];
		return (ia < ib) != (ic < id);
	}
};

void gen(ll n, vector<ll>& arr, vector<ll>& used, ll p, vector<s>& t) {
	if (p == n) {
		ll ans = 1;
		vector<ll> num(n, 0);
		for (ll i = 0; i < n; i++) {
			num[arr[i]-1] = i;
		}
		for (auto& i : t) {
			ans = ans & i.p(num);
		}
		if (ans) {
			f = 1;
			for (auto i : arr) {
			       cout << i << ' ';
		      	}
		}		
		return;
	}
	for (ll i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = 1;
			arr[p] = i;
			gen(n, arr, used, p+1, t);
			if (f) {
				return;
			}
			used[i] = 0;
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0), used(n+1, 0);
	vector<s> t;
	for (ll i = 0; i < m; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		t.push_back(s(a, b, c, d));
	}
	gen(n, arr, used, 0, t);
	if (!f) {
		cout << 0;
	}
}
