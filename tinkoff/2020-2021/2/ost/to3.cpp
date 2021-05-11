#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
typedef double db;

using namespace std;

struct town {
	ll x;
	ll y;
	town(ll x = 0, ll y = 0): x(x), y(y) {}
	db dist(town t) {
		return sqrt((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y));
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("unionday.in", "r", stdin);
	freopen("unionday.out", "w", stdout);
	ll n;
	cin >> n;
	vector<town> arr(n, town());
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	vector<ll> used(n, 0);
	vector<db> cost(n + 1, 100000000);
	cost[0] = 0;
	db ans = 0;
	while(true) {
		ll now = n;
		for (ll i = 0; i < n; i++) {
			if (!used[i]) {
				if (cost[i] < cost[now]) {
					now = i;
				}
			}
		}
		if (now == n) {
			break;
		}
		used[now] = 1;
		ans += cost[now];
		for (ll i = 0; i < n; i++) {
			cost[i] = min(cost[i], arr[now].dist(arr[i]));
		}
	}
	cout << setprecision(20) << ans;
}
