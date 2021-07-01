#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n+1, 1);
	for (ll i = 1; i <= n; i++) {
		arr[i] = arr[i-1]*2;
		if (i-k >= 0) {
			arr[i] -= arr[i-k];
		}
		cout << arr[i] << '\n';
	}
	cout << arr[n];
}
