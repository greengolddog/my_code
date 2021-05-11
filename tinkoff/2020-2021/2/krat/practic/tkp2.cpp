#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

struct city {
	ll zero;
	ll one;
	ll two;
	city(ll zero, ll one, ll two): zero(zero), one(one), two(two) {}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll n;
    	cin >> n;
    	vector<ll> cost(n, 0);
    	for (ll i = 0; i < n; i++) {
		cin >> cost[i];
	}
	ll m;
	cin >> m;
	vector<pair<ll, ll>> roads;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		roads.push_back({a, b});
		roads.push_back({b, a});
	}
	vector<city> ans(n, city(-1, -1, -1));
	ans[0] = city(0, cost[0], cost[0]*2);
	for (ll i = 0; i < n; i++) {
		for (auto j : roads) {
			if (ans[j.second].zero == -1) {
				if (ans[j.first].zero != -1) {
					ans[j.second].zero = ans[j.first].one;
					ans[j.second].one = min(ans[j.first].one + cost[j.second], ans[j.first].two);
					ans[j.second].two = ans[j.second].one + cost[j.second];
				}
			} else {
				if (ans[j.first].zero != -1) {
					ans[j.second].zero = min(ans[j.second].zero, ans[j.first].one);
					ans[j.second].one = min(ans[j.second].one, min(ans[j.first].one + cost[j.second], ans[j.first].two));
					ans[j.second].two = ans[j.second].one + cost[j.second];
				}
			}
		}
	}
	cout << ans[n - 1].zero;
}
