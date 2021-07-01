#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void DFS(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& parent) {
	parent[v] = p;
	for (auto i : arr[v]) {
		if (i != p) {
			DFS(i, v, arr, parent);
		}
	}
}

bool is_correct(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& parent, ll size, ll& last, vector<ll>& o) {
	if (parent[v] != p) {
		return false;
	}
	ll now_last = last;
	last += size;
	for (ll i = 0; i < size; i++) {
		if (!is_correct(o[now_last+i], v, arr, parent, arr[o[now_last+i]].size()-1, last, o)) {
			return false;
		}
	}
	return true;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < n-1; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> o(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> o[i];
		o[i]--;
	}
	vector<ll> parent(n, -1);
	DFS(0, 0, arr, parent);
	ll last = 1;
	cout << (is_correct(0, o[0], arr, parent, arr[0].size(), last, o) ? "Yes" : "No");
}
