#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	string a, b;
	cin >> a;
	ll n, c;
	cin >> n;
	vector<ll> kb(50, 0),kb2(50, 0);
	for (ll i = 0; i < a.size(); i++) {
		kb[a[i]-'a']++;
	}
	for (ll i = 0; i < n; i++) {
		cin >> b;
		for (ll i = 0; i < b.size(); i++) {
			kb2[b[i]-'a']++;
		}
		c = 0;
		for (ll i = 0; i < 50; i++) {
			if (kb2[i] != kb[i]) {
				c = 1;
			}
			kb2[i] = 0;
		}
		if (c == 0) {
			cout << b << endl;
		}
	}		
}