#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	if (s == "biba") {
		cout << "boba";
		return 0;
	}
	if (s == "boba") {
		cout << "biba";
		return 0;
	}
	stringstream in(s);
	ll a, b;
	in >> a;
	cin >> b;
	__int128 ans = (__int128)a*b;
	if (ans < 0) {
		cout << '-';
		ans = -ans;
	}
	if (ans == 0) {
		cout << 0;
	}
	vector<ll> aa;
	while (ans > 0) {
		aa.push_back(ans%10);
		ans = ans/10;
	}
	reverse(aa.begin(), aa.end());
	for (auto i : aa) {
		cout << i;
	}
}
