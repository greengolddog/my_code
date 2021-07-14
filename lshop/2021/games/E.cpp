#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll now = n, p = 0, op = 0;
	while (now > 1) {
		p++;
		op++;
		now = now/2;
	}
	p = p % 2;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (arr.size() > 1) {
		vector<ll> new_arr;
		if (op % 2 == 0) {
			if (p == 1) {
				for (ll i = 0; i < arr.size(); i += 2) {
					new_arr.push_back(min(arr[i], arr[i+1]));
				}
			} else {
				for (ll i = 0; i < arr.size(); i += 2) {
					new_arr.push_back(max(arr[i], arr[i+1]));
				}
			}
		} else {
			if (p == 1) {
				for (ll i = 0; i < arr.size(); i += 2) {
					new_arr.push_back(max(arr[i], arr[i+1]));
				}
			} else {
				for (ll i = 0; i < arr.size(); i += 2) {
					new_arr.push_back(min(arr[i], arr[i+1]));
				}
			}
		}
		p = 1-p;
		arr = new_arr;
	}
	cout << arr[0]*(op % 2 == 0 ? 1 : -1);
}
