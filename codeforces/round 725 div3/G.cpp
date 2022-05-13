#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n, last = 0;
		cin >> n;
		unordered_map<string, pair<pair<ll, string>, pair<tuple<bool, bool, bool>, tuple<bool, bool, bool>>>> arr;
		for (ll i = 0; i < n; i++) {
			string name;
			cin >> name;
			string c;
			cin >> c;
			string s;
			cin >> s;
			if (c == "=") {
				string a, b;
				cin >> b >> b;
				a = s;
				auto[a1, a2, a3] = arr[a].second.second;
				auto[b1, b2, b3] = arr[b].second.first;
				arr[name] = make_pair({arr[a].first.first+arr[b].first.first+(a1 && b3)+(a2 && b2)+(a3 && b1), "ddddddddddddddddd"}, make_pair(arr[a].second.first, arr[b].second.second));
			}
			if (c == ":=") {
				ll now = 0;
				for (ll i = 0; i+3 < s.size(); i++) {
					now += ((s[i] == 'h') && (s[i+1] == 'a') && (s[i+2] == 'h') && (s[i+3] == 'a'));
				}
				arr[name] = make_pair({now, s}, make_pair(make_tuple(s[0] == 'a', (s.size() > 1) && (s[0] == 'h') && (s[1] == 'a'), (s.size() > 2) && (s[0] == 'a') && (s[1] == 'h') && (s[2] == 'a')), make_tuple(s.back() == 'h', (s.size() > 1) && (s.back() == 'h') && (s[s.size()-2] == 'a'), (s.size() > 2) && (s.back() == 'h') && (s[s.size()-2] == 'a') && (s[s.size()-3] == 'a'))));
			}
			last = arr[name].first;
		}
		cout << last << '\n';
	}
}
