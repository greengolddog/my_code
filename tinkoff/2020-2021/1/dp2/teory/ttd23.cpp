#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n;
    vector<ll> arr2(n + 1);
    for (ll i = 1; i < (n + 1); i++) {
	cin >> arr2[i];
    }
    cin >> m;
    vector<ll> arr3(m + 1);
    for (ll i = 1; i < (m + 1); i++) {
	cin >> arr3[i];
    }
    vector<vector<ll>> arr(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i < (n + 1); i++) {
	for (ll j = 1; j < (m + 1); j++) {
	    if (arr2[i] == arr3[j]) {
		arr[i][j] = max(arr[i-1][j-1]+1, max(arr[i-1][j], arr[i][j-1]));
	    } else {
		arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
	    }
	}
    }
    cout << arr[n][m];
}
