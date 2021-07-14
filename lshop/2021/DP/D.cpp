#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	string p;
	cin >> p;
	vector<pair<pair<ll, ll>, char>> ans(1, {{0, 0}, '0'});
	char last = '0';
	for (auto i : p) {
		if (i == last) {
			ans.back().first.second++;
		} else {
			ans.push_back({{ans.back().first.second+1, ans.back().first.second+1}, i});
			last = i;
		}
	}
	cout << ans.size()-1 << '\n';
	ans.erase(ans.begin());
	for (auto[g, c] : ans) {
		cout << g.first << ' ' << g.second << ' ' << c << '\n';
	}
}
