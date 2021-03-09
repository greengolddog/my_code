#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y;
    cin >> n >> m;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < m; i++) {
	cin >> x >> y;
	arr[x-1]++;
	arr[y-1]++;
    }
    for (ll i = 0; i < n; i++) {
	cout << arr[i] << ' ';
    }
}
