#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, p;
	cin >> n >> m >> p;
	vector<vector<pair<ll, ll>>> arr_p(p*2, vector<pair<ll, ll>>(0, {0, 0})), arr_m(p*2, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < n; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		arr_p[c].push_back({a, b});
		arr_m[d].push_back({a, b});
	}
	ll sum1 = 0, sum2 = 0, ans = 0;
	multiset<pair<ll, pair<ll, ll>>> s1, s2;
	for (ll i = 0; i < 2*p; i++) {
		for (auto j : arr_p[i]) {
			if (j.second >= j.first) {
				sum2 += j.second;
			} else {
				ll v = j.first-j.second;
				s1.insert({v, {j.first, j.second}});
				sum1 += j.first;
				s2.insert(*s1.begin());
				sum2 += s1.begin()->second.second;
				sum1 -= s1.begin()->second.first;
				s1.erase(s1.begin());
				if (s1.size() < m) {
					s1.insert(*s2.rbegin());
					sum1 += (*s2.rbegin()).second.first;
					sum2 -= (*s2.rbegin()).second.second;
					s2.erase(s2.find(*s2.rbegin()));
				}
			}
		}
		for (auto j : arr_m[i]) {
			if (j.second >= j.first) {
				sum2 -= j.second;
			} else {
				ll v = j.first-j.second;
				if (s1.find({v, {j.first, j.second}}) == s1.end()) {
					s2.erase(s2.find({v, {j.first, j.second}}));
					sum2 -= j.second;
				} else {
					s1.erase(s1.find({v, {j.first, j.second}}));
					sum1 -= j.first;
					if (s2.size() > 0) {
						s1.insert(*s2.rbegin());
						sum1 += (*s2.rbegin()).second.first;
						sum2 -= (*s2.rbegin()).second.second;
						s2.erase(s2.find(*s2.rbegin()));
					}
				}
			}
		}
		ans += sum1+sum2;
	}
	cout << ans;
}
