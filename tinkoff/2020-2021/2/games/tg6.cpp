#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("sweets.in", "r", stdin);
	freopen("sweets.out", "w", stdout);
    	ll n, k;
    	cin >> n >> k;
    	vector<vector<ll>> arr(n + 1, vector<ll>(k + 1, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= k; j++) {
			for (ll l = min(i, j); l > 0; l--) {
				if (arr[i - l][l] == 0) {
					arr[i][j] = l;
				}
			}
		}
	}
	cout << arr[n][k];
}
