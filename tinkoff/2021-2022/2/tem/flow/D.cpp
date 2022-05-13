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

struct edge {
	ll a, b, f, c, rev;
};

bool dfs(ll v, vector<bool>& used, vector<edge>& e, vector<vector<ll>>& arr, ll f) {
	used[v] = true;
	for (auto i : arr[v]) {
		if (!used[e[i].b]) {
			if (e[i].f != e[i].c && (e[i].b == f || dfs(e[i].b, used, e, arr, f))) {
				e[i].f++;
				e[e[i].rev].f--;
				return true;
			}
		}
	}
	return false;
}

void dfs2(ll v, vector<bool>& used, vector<edge>& e, vector<vector<ll>>& arr, ll f, vector<ll>& ans) {
	if (v == f) {
		ans.push_back(v + 1);
		return;
	}
	for (auto i : arr[v]) {
		if (!used[i] && i % 2 == 0) {
			used[i] = true;
			if (e[i].f == e[i].c) {
				dfs2(e[i].b, used, e, arr, f, ans);
				ans.push_back(v + 1);
				return;
			}
		}
	}
}		

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, s, f;
	cin >> n >> m >> s >> f;
	s--;
	f--;
	vector<vector<ll>> arr(n);
	vector<edge> e;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		ll c = 1;
		e.push_back({a, b, 0, c, 2 * i + 1});
		e.push_back({b, a, 0, 0, 2 * i});
		arr[a].push_back(i * 2);
		arr[b].push_back(i * 2 + 1);
	}
	vector<bool> used(n, false);
	if (!dfs(s, used, e, arr, f)) {
		cout << "NO";
		return 0;
	}
	used.clear();
	used.resize(n, false);
	if (!dfs(s, used, e, arr, f)) {
		cout << "NO";
		return 0;
	}
	used.clear();
	used.resize(e.size(), false);
	vector<ll> ans;
	cout << "YES" << '\n';
	dfs2(s, used, e, arr, f, ans);
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
	ans.clear();
	dfs2(s, used, e, arr, f, ans);
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << ' ';
	}
}