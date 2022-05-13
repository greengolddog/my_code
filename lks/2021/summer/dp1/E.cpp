#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n, 0), b(n, 0), c(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<ll> arr(1 << n, 0), pred(1 << n, 0);
	arr[0] = k;
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < n; j++) {
			if (!(i >> j & 1)) {
				arr[i | (1 << j)] = arr[i] + c[j];
			}
		}
	}
	vector<bool> dp(1 << n, false);
	dp[0] = true;
	ll mk = 0, ans = 0;
	for (ll i = 0; i < (1 << n); i++) {
		if (dp[i]) {
			ll cnt = 0;
			for (ll j = 0; j < n; j++) {
				if (!(i >> j & 1)) {
					if (arr[i] >= a[j] && arr[i] <= b[j]) {
						dp[i | (1 << j)] = true;
						pred[i | (1 << j)] = i;
					}
				} else {
					cnt++;
				}
			}
			if (cnt > mk) {
				mk = cnt;
				ans = i;
			}
		}
	}
	cout << mk << '\n';
	vector<ll> an;
	ll now = ans;
	while (now != 0) {
		for (ll i = 0; i < n; i++) {
			if ((now >> i & 1) != (pred[now] >> i & 1)) {
				an.push_back(i);
			}
		}
		now = pred[now];
	}
	reverse(an.begin(), an.end());
	for (auto i : an) {
		cout << i + 1 << ' ';
	}
}
