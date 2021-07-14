#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

ll mex(vector<ll> arr) {
	if (arr.size() == 0) {
		return 0;
	}
	sort(arr.begin(), arr.end());
	if (arr[0] > 0) {
		return 0;
	}
	for (ll i = 0; i < arr.size()-1; i++) {
		if (arr[i]+1 < arr[i+1]) {
			return arr[i]+1;
		}
	}
	return arr[arr.size()-1]+1;
}

void rec(vector<ll>& arr, ll x, vector<vector<ll>>& gr, vector<vector<ll>>& gr2, vector<ll>& ans) {
	vector<ll> m;
	for (ll i = 0; i < gr2[x].size(); i++) {
		m.push_back(ans[gr2[x][i]]);
	}
	ans[x] = mex(m);
	for (ll i = 0; i < gr[x].size(); i++) {
		arr[gr[x][i]]--;
		if (arr[gr[x][i]] == 0) {
			rec(arr, gr[x][i], gr, gr2, ans);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll m, n;
    	cin >> n >> m;
    	vector<ll> arr(n, 0), arr2(n, 0), gran(n, 0);
	vector<vector<ll>> gr(n, vector<ll>(0, 0)), gr2(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a]++;
		arr2[a]++;
		gr2[a].push_back(b);
		gr[b].push_back(a);
	}
    	ll m2, n2;
    	cin >> n2 >> m2;
    	vector<ll> arr1(n, 0), arr22(n, 0), gran2(n, 0);
	vector<vector<ll>> gr1(n, vector<ll>(0, 0)), gr22(n, vector<ll>(0, 0));
	for (ll i = 0; i < m2; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr1[a]++;
		arr22[a]++;
		gr22[a].push_back(b);
		gr1[b].push_back(a);
	}
	for (ll i = 0; i < n; i++) {
		if (arr2[i] == 0) {
			rec(arr, i, gr, gr2, gran);
		}
	}
	for (ll i = 0; i < n2; i++) {
		if (arr22[i] == 0) {
			rec(arr1, i, gr1, gr22, gran2);
		}
	}
	ll q;
	cin >> q;
	for (ll _ = 0; _ < q; _++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << (gran[a] == gran2[b] ? "second" : "first") << '\n';
	}
}
