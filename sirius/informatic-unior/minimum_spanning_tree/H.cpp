#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<vector<ll>> arr;
	vector<ll> color;
	ll size;
	DSU(ll n) {
		size = n;
		arr.resize(n, vector<ll>(0, 0));
		color.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			arr[i].push_back(i);
			color[i] = i;
		}
	}
	void unite(ll a, ll b) {
		if (arr[color[a]].size() < arr[color[b]].size()) {
			swap(a, b);
		}
		for (auto i : arr[color[b]]) {
			color[i] = color[a];
			arr[color[a]].push_back(i);
		}
	}
	ll get(ll n) {
		return color[n];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	DSU d(n);
	for (ll i = 0; i < n-1; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		d.unite(a, b);
	}
	for (auto i : d.arr[d.get(0)]) {
		cout << i+1 << ' ';
	}
}
