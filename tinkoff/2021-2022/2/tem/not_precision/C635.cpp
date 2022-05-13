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

mt19937 rnd(3);

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	shuffle(arr.begin(), arr.end(), rnd);
	for (ll i = 0; i < k; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
}
