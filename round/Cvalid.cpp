#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	if (1 > t || t > 100'000) {
		return 1;
	}
	ll sum = 0;
	for (ll i = 0; i < t; i++) {
		ll n;
		cin >> n;
		sum += n;
		if (n > 100'000 || n < 1) {
			return 1;
		}
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			if (1 > arr[i] || arr[i] > 1'000'000'000) {
				return 1;
			}
		}
	}
	if (sum > 100'000) {
		return 1;
	}
}
