#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 1; iii <= t; iii++) {
		string s;
		cin >> s;
		ll cg;
		cin >> cg;
		set<char> se;
		se.insert('A');
		se.insert('C');
		se.insert('U');
		se.insert('G');
		map<char, ll> ma;
		ma['A'] = 0;
		ma['C'] = 1;
		ma['U'] = 2;
		ma['G'] = 3;
		vector<pair<ll, ll>> arr;
		ll uk = 0;
		while (uk < s.size()) {
			if (se.find(s[uk]) != se.end()) {
				arr.push_back({ma[s[uk]], 0});
			} else {
				arr[arr.size()-1].second = arr[arr.size()-1].second*10 + s[uk]-'0';
			}
		}
		vector<ll> arr2;
		for (ll i = 2; i < arr.size(); i++) {
			ll ni = i-1;
			for (ll j = 0; j < arr[ni].second; j++) {
				arr2.push_back(arr[ni].first);
			}
		}
		vector<vector<vector<ll>>> dp(arr2.size(), vector<vector<ll>>(arr2.size(), vector<ll>(cq, 0)));
		for (ll i = 1; i < arr2.size(); i++) {
			for (ll j = 0; j < arr2.size()-i; j++) {
				for (ll l = 0; l < cg; l++) {
					dp[j][j+i][l] = dp[j][j+i-1][l];
					for (ll k = j; k < j+i; k++) {
						if (arr2[j+i] % 2 == arr2[k] % 2) {
							dp[j][j+i][l] = max(dp[j][j+i][l], 1+dp[j][k-1]+dp[k+1][j+i]);
						}
					}
				}
			}
		}
		cout << dp[0][arr2.size()-1];
	}
}
