#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> arr(n, make_pair(-1, -1));
	for (ll i = 0; i < n * 2; i++) {
		ll x;
		cin >> x;
		x--;
		if (arr[x].first == -1) {
			arr[x].first = i;
		} else {
			arr[x].second = i;
		}
	}
	vector<vector<ll>> go(n);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (arr[i].first <= arr[j].first && arr[j].second <= arr[i].second) {
				go[i].push_back(j);
				go[j].push_back(i);
			}
		}
	}
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		vector<ll> dist(n, INF32);
		queue<ll> q;
		q.push(a);
		dist[a] = 0;
		bool bb = false;
		while (!q.empty()) {
			ll x = q.front();
			q.pop();
			for (auto v : go[x]) {
				if (assign_min(dist[v], dist[x] + 1)) {
					if (v == b) {
						bb = true;
						break;
					}
					q.push(v);
				}
			}
			if (bb) {
				break;
			}
		}
		cout << (dist[b] == INF32 ? -1 : dist[b]) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
