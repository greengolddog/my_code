#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include "game.h"
typedef int ll;

using namespace std;

vector<set<ll>> go_from, go_to;
vector<vector<bool>> go_from_k;
vector<bool> used;
vector<ll> be;
ll N, K;
bool b = false;

void init(int n, int k) {
	N = n;
	K = k;
	go_from_k.resize(n, vector<bool>(k, false));
	used.resize(n, false);
	go_from.resize(n);
	go_to.resize(n);
	for (ll i = 1; i < k; i++) {
		go_from[i].insert(i - 1);
		for (ll j = 0; j < i; j++) {
			go_from_k[i][j] = true;;
		}
	}
	for (ll i = 0; i < k - 1; i++) {
		go_to[i].insert(i + 1);
	}
}

void dfs(ll v, ll x) {
	if (go_from_k[v][x]) {
		return;
	}
	used[v] = true;
	be.push_back(v);
	if (v == x) {
		b = true;
		return;
	}
	go_from_k[v][x] = true;
	for (auto i : go_to[v]) {
		if (!used[i]) {
			dfs(i, x);
		}
	}
}

int add_teleporter(int u, int v) {
	go_from[v].insert(u);
	go_to[u].insert(v);
	for (ll i = 0; i < K; i++) {
		if (!go_from_k[u][i]) {
			continue;
		}
		dfs(v, i);
		for (auto v : be) {
			used[v] = false;
		}
		be.clear();
	}
	if (u < K) {
		dfs(v, u);
		for (auto v : be) {
			used[v] = false;
		}
		be.clear();
	}
	return b;
}

//int main() {
//	ll n, m, k;
//	cin >> n >> m >> k;
//	init(n, k);
//	for (ll i = 0; i < m; i++) {
//		ll a, b;
//		cin >> a >> b;
//		cout << add_teleporter(a, b) << '\n';
//	}
//}
