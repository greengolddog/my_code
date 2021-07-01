#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool cmp(pair<string, ll> a, pair<string, ll> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, ln = 0;
	cin >> n;
	map<string, ll> ci, num;
	map<ll, string> rev_num;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll a;
		cin >> a;
		ci[s] = a;
		num[s] = ln;
		rev_num[ln] = s;
		ln++;
	}
	vector<map<string, ll>> arr(n);
	vector<set<string>> sarr(n);
	map<string, ll> p;
	string s;
	while (cin >> s) {
		string s2;
		cin >> s2;
		p[s2] = 0;
		if (sarr[num[s]].find(s2) == sarr[num[s]].end()) {
			sarr[num[s]].insert(s2);
			arr[num[s]][s2] = 1;
		} else {
			arr[num[s]][s2] += 1;
		}
	}
	for (ll i = 0; i < n; i++) {
		vector<pair<string, ll>> win;
		for (auto j : arr[i]) {
			win.push_back(j);
		}
		sort(win.begin(), win.end(), cmp);
		p[win[0].first] += ci[rev_num[i]];
	}
	vector<pair<string, ll>> ans;
	for (auto i : p) {
		ans.push_back(i);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (auto i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}
