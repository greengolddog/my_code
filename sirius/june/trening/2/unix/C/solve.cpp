#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, N = 5000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve() {
	ll n1, n2, k;
	cin >> n1 >> n2 >> k;
	vector<pair<ll, ll>> p1(n1), p2(n2);
	for (ll i = 0; i < n1; i++) {
		cin >> p1[i].first >> p1[i].second;
	}
	for (ll i = 0; i < n2; i++) {
		cin >> p2[i].first >> p2[i].second;
	}
	vector<vector<ll>> dp1(N, vector<ll>(N, 0)), dp2(N, vector<ll>(N, -INF64));
	vector<ll> po1(N + 1, 0), po2(N + 1, 0);
	for (ll i = 0; i < n1; i++) {
		for (ll j = p1[i].first + 1; j <= p1[i].second; j++) {
			po1[j] = i + 1;
		}
	}
	for (ll i = 0; i < n2; i++) {
		for (ll j = p2[i].first + 1; j <= p2[i].second; j++) {
			po2[j] = i + 1;
		}
	}
	for (ll i = 1; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			assign_max(dp1[i][j], dp1[i - 1][j] + ((po1[i] != po1[i - 1]) && (po1[i] != 0)));
		}
		for (ll j = 0; j < N; j++) {
			assign_max(dp2[i][j], dp2[i - 1][j] + ((po2[i] != po2[i - 1]) && (po2[i] != 0)));
		}
		if (i >= k + 1) {
			for (ll j = 0; j < N; j++) {
				if (j != po1[i] || j == 0) {
					assign_max(dp1[i][po2[i - k]], dp2[i - k][j] + (po1[i] != 0));
				}
			}
			for (ll j = 0; j < N; j++) {
				if (j != po2[i] || j == 0) {
					assign_max(dp2[i][po1[i - k]], dp1[i - k][j] + (po2[i] != 0));
				}
			}
		}
	}
	ll ans = 0;
	for (ll j = 0; j < N; j++) {
		for (ll i = 0; i < N; i++) {
			assign_max(ans, dp2[j][i]);
		}
		for (ll i = 0; i < N; i++) {
			assign_max(ans, dp1[j][i]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
