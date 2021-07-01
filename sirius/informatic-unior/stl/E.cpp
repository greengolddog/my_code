#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll n;
	string trash;
	cin >> n;
	getline(cin, trash);
	map<string, vector<string>> arr;
	set<string> se;
	for (ll i = 0; i < n; i++) {
		string s, p;
		getline(cin, s);
		s.push_back(',');
		ll now = 0;
		while (true) {
			if (s[now] == ' ') {
				break;
			}
			p.push_back(s[now]);
			now++;
		}
		now += 3;
		string ns;
		while (now < s.size()) {
			if (s[now] == ',') {
				now += 2;
				if (se.find(ns) == se.end()) {
					se.insert(ns);
					arr[ns] = vector<string>(1, p);
				} else {
					arr[ns].push_back(p);
				}
				ns = "";
			} else {
				ns.push_back(s[now]);
				now++;
			}
		}
	}
	cout << se.size() << '\n';
	for (auto i : arr) {
		cout << i.first << " - ";
		string ans;
		for (auto j : i.second) {
			ans += j+", ";
		}
		ans.pop_back();
		ans.pop_back();
		cout << ans << '\n';
	}
}
