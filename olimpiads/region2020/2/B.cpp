#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll nd, ans;
	ans = 0;
	string a;
	vector<char> all;
	while(cin >> a) {
		for (auto i : a) {
			all.push_back(i);
		}
	}
	vector<pair<ll,pair<ll,pair<ll,ll>>>> d(40,{0,{0,{0,0}}});
	for (ll i = 0; i < all.size(); i++) {
		nd = all[i]-'a';
		d[nd].first += d[nd].second.first + (i - d[nd].second.second.second-1)*d[nd].second.second.first;
		d[nd].second.first += (i - d[nd].second.second.second)*d[nd].second.second.first;
		d[nd].second.second.first++;
		d[nd].second.second.second = i;
	}
	for (auto i : d) {
		ans += i.first;
	}
	cout << ans;
}