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
	sort(arr.begin(), arr.end());
	ll mid = (n-1)/2;
	ll last = n;
	for (ll i = mid+1; i < n; i++) {
		if ((arr[i]-arr[mid])*(i-mid) <= k) {
			k -= (arr[i]-arr[mid])*(i-mid);
			arr[mid] = arr[i];
		} else {
			last = i;
			break;
		}
	}
	cout << arr[mid]+(k/(last-mid));
}
