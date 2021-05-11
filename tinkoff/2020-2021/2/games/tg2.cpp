#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

void rec(vector<ll>& arr, ll x, vector<vector<ll>>& gr) {
	if (arr[x] == 0) {
		for (ll i = 0; i < gr[x].size(); i++) {
			if (arr[gr[x][i]] != -1) {
				arr[gr[x][i]] = -1;
				rec(arr, gr[x][i], gr);
			}
		}
	}
	if (arr[x] == -1) {
		for (ll i = 0; i < gr[x].size(); i++) {
			if (arr[gr[x][i]] != -1) {
				arr[gr[x][i]]--;
				rec(arr, gr[x][i], gr);
			}
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("retro.in", "r", stdin);
	freopen("retro.out", "w", stdout);
    	ll m, n;
	while (cin >> n) {
    		cin >> m;
    		vector<ll> arr(n, 0), arr2(n, 0);
		vector<vector<ll>> gr(n, vector<ll>(0, 0));
		for (ll i = 0; i < m; i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			arr[a]++;
			arr2[a]++;
			gr[b].push_back(a);
		}
		for (ll i = 0; i < n; i++) {
			if (arr2[i] == 0) {
				arr[i] = 0;
				rec(arr, i, gr);
			}
		}
		for (ll i = 0; i < n; i++) {
			cout << ((arr[i] == -1) ? "FIRST" : ((arr[i] == 0) ? "SECOND" : "DRAW")) << "\n";
		}
		cout << "\n";
	}
}
