#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n,q,l,r;
	double sr,c,maxi=0;
	vector<pair<double,int>> s;
	vector<int> mas(10000000, 0);
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> c;
		s.push_back({c,i+1});
	}
	cin >> q;
	for (ll k = 0; k < q; k++) {
		set<double> s2;
		cin >> l >> r;
		for (ll j = l-1; j < r; j++) {
			mas[s[j].first] += 1;
			s2.insert(s[j].first);
		}
		sr = -1;
		for (auto i : s2) {
			if (sr == -1) {
				sr = mas[round(i)];
			} else {
				for (ll j = 0; j < mas[round(i)]; j++) {
					sr = (sr+i)/2;
				}
			}
			mas[round(i)] = 0;
		}
		cout << setprecision(20) << sr << "\n";
	}
}