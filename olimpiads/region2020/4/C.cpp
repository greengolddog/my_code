#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n, p, sp, r1, r2, ni, c;
	cin >> n >> p;
	vector<pair<ll, vector<ll>>> m(n+1, {0,vector<ll>(0,0)});
	map<vector<int>, int> mapp;
	set<vector<int>> sett;
	set<ll> s;
	for (ll i = 1; i < n; i++) {
		cin >> r1 >> r2;
		m[r1].second.push_back(r2);
		m[r2].second.push_back(r1);
	}
	for (ll i = 1; i <= p; i++) {
		cin >> ni;
		sp = 1;
		vector<int> cmm;
		vector<vector<ll>> pl(ni+1, vector<ll>(0,0));
		for (ll j = 1; j <= ni; j++) {
			cin >> r1;
			pl[j].push_back(r1);
			m[r1].first = i;
			s.insert(j);
			cmm.push_back(r1);
		}
		if (sett.find(cmm) == sett.end()) {
		sett.insert(cmm);
		while ((s.size() > 0) and (*s.begin() == 1)) {
			vector<int> cvu;
			for (auto np : s) {
				c = 0;
				for (auto vp : pl[np]) {
					for (auto svp : m[vp].second) {
						if (m[svp].first != i) {
							m[svp].first = i;
							pl[np].push_back(svp);
							if (np == 1) {
								sp++;
							}
							c = 1;
						}
					}
				}
				if (c == 0) {
					cvu.push_back(np);
				}
			}
			for (auto np : cvu) {
				s.erase(np);
			}
		}
		mapp[cmm]=sp;
		}
		s.clear();
		cout << mapp[cmm] << endl;
	}
}