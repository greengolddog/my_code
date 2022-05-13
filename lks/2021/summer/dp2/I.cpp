#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll s;
	cin >> s;
	ll n = 0;
	vector<ll> arr;
	ll x;
	while (cin >> x) {
		arr.push_back(x);
		n++;
	}
	vector<bool> dp(s + 1, false);
	dp[0] = true;
	vector<ll> pred(s + 1, -1);
	for (ll i = 0; i < n; i++) {
		for (ll j = s; j >= arr[i]; j--) {
			if (!dp[j] && dp[j - arr[i]]) {
				dp[j] = true;
				pred[j] = j - arr[i];
			}
		}
	}
	ll now = s;
	while (!dp[now]) {
		now--;
	}
	cout << now << '\n';
	while (now != 0) {
		cout << now - pred[now] << ' ';
		now = pred[now];
	}
}
