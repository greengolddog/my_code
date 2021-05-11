#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

void rec(vector<vector<ll>>& arr, ll x, ll y, ll n, ll m) {
	if (arr[x][y] == 0) {
		for (ll i = 1; i < n - x; i++) {
			if (arr[x+i][y] != -1) {
				arr[x+i][y] = -1;
				rec(arr, x+i, y, n, m);
			}
		}
		for (ll i = 1; i < m - y; i++) {
			if (arr[x][y+i] != -1) {
				arr[x][y+i] = -1;
				rec(arr, x, y+i, n, m);
			}
		}
		for (ll i = 1; i < min(m - y, n - x); i++) {
			if (arr[x+i][y+i] != -1) {
				arr[x+i][y+i] = -1;
				rec(arr, x+i, y+i, n, m);
			}
		}
	}
	if (arr[x][y] == -1) {
		for (ll i = 1; i < n - x; i++) {
			if (arr[x+i][y] != -1) {
				arr[x+i][y]--;
				rec(arr, x+i, y, n, m);
			}
		}
		for (ll i = 1; i < m - y; i++) {
			if (arr[x][y+i] != -1) {
				arr[x][y+i]--;
				rec(arr, x, y+i, n, m);
			}
		}
		for (ll i = 1; i < min(m - y, n - x); i++) {
			if (arr[x+i][y+i] != -1) {
				arr[x+i][y+i]--;
				rec(arr, x+i, y+i, n, m);
			}
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("queen1.in", "r", stdin);
	freopen("queen1.out", "w", stdout);
    	ll m, n;
    	cin >> m >> n;
    	vector<vector<ll>> arr(n, vector<ll>(m, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			arr[i][j] = i+j+min(i, j);
		}
	}
	rec(arr, 0, 0, n, m);
	cout << arr[n-1][m-1] + 2;
}
