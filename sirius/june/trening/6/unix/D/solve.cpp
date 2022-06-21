#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 25;

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

ll rec(ll n, vector<vector<ll>>& dist, vector<ll>& now, bool b) {
	if (now.size() == n) {
		if (!b) {
			return INF32;
		}
		ll ans = 0;
		vector<pair<ll, ll>> arr;
		for (ll i = 0; i < n; i++) {
			arr.push_back(make_pair(now[i], i));
		}
		sort(arr.begin(), arr.end());
		for (ll i = 1; i < n; i++) {
			ll md = INF32;
			for (ll j = 0; j < n; j++) {
				if (arr[i].first == now[j] + 1) {
					assign_min(md, dist[arr[i].second][j] * now[j]);
				}
			}
			ans += md;
		}
		return ans;
	}
	now.push_back(1);
	if (b) {
		now.back()++;
	}
	ll ans = INF32;
	for (; now.back() < n; now.back()++) {
		assign_min(ans, rec(n, dist, now, b || (now.back() == 1)));
	}
	now.pop_back();
	return ans;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	vector<vector<ll>> dist(n, vector<ll>(n, INF32));
	for (ll i = 0; i < m; i++) {
		ll a, b, l;
		cin >> a >> b >> l;
		a--;
		b--;
		assign_min(dist[a][b], l);
		assign_min(dist[b][a], l);
	}
	vector<ll> now;
	cout << rec(n, dist, now, false) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
