#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, ans = 0;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			if (i % 2 == 0) {
				ans += arr[i];
			}
		}
		vector<ll> arr1, arr2;
		for (ll i = 1; i < n; i += 2) {
			arr1.push_back(arr[i]-arr[i-1]);
		}
		for (ll i = 2; i < n; i += 2) {
			arr2.push_back(arr[i-1]-arr[i]);
		}
		ll ans1 = 0, ans2 = 0, now1 = 0, now2 = 0;
		for (auto i : arr1) {
			now1 += i;
			ans1 = max(now1, ans1);
			if (now1 < 0) {
				now1 = 0;
			}
		}
		for (auto i : arr2) {
			now2 += i;
			ans2 = max(now2, ans2);
			if (now2 < 0) {
				now2 = 0;
			}
		}
		cout << max(ans+ans1, ans+ans2) << '\n';
	}
}
