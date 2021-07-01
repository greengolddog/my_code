#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n*m, 0);
	for (ll i = 0; i < n*m; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cout << arr[i*m+j] << ' ';
		}
		cout << '\n';
	}
}
