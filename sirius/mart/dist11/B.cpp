#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000, MOD = 998'244'353;

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
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> dp(n, 0), rdp(n, 0);
	dp[0] = 1;
	rdp[0] = 1;
	for (ll i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			dp[i] += dp[i - 1];
		}
		if (arr[i] >= -arr[i - 1]) {
			dp[i] += rdp[i - 1];
		}
		if (-arr[i] >= arr[i - 1]) {
			rdp[i] += dp[i - 1];
		}
		if (-arr[i] >= -arr[i - 1]) {
			rdp[i] += rdp[i - 1];
		}
		dp[i] %= MOD;
		rdp[i] %= MOD;
	}
	cout << (dp.back() + rdp.back()) % MOD;
}
