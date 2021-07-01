#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll sum = 0;
	for (ll i = 1; i < k; i++) {
		sum += arr[i] > arr[i-1];
	}
	ll ans = sum;
	for (ll i = k; i < n; i++) {
		sum += arr[i] > arr[i-1];
		sum -= arr[i-k+1] > arr[i-k];
		ans = min(ans, sum);
	}
	cout << ans;
}
