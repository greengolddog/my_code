#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, string>> arr(n, {0, " "});
    for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	__int128 i128 = 1;
	vector<pair<__int128, ll>> s(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		s[i].second = i;
		if (arr[i].second == "mg") {
			s[i].first = i128*arr[i].first;
		}
		if (arr[i].second == "g") {
			s[i].first = i128*arr[i].first*1000;
		}
		if (arr[i].second == "kg") {
			s[i].first = i128*arr[i].first*1000*1000;
		}
		if (arr[i].second == "Mg") {
			s[i].first = i128*arr[i].first*1000*1000*1000;
		}
		if (arr[i].second == "Gg") {
			s[i].first = i128*arr[i].first*1000*1000*1000*1000;
		}
		if (arr[i].second == "mp") {
			s[i].first = i128*arr[i].first*16380;
		}
		if (arr[i].second == "p") {
			s[i].first = i128*arr[i].first*16380*1000;
		}
		if (arr[i].second == "kp") {
			s[i].first = i128*arr[i].first*16380*1000*1000;
		}
		if (arr[i].second == "Mp") {
			s[i].first = i128*arr[i].first*16380*1000*1000*1000;
		}
		if (arr[i].second == "Gp") {
			s[i].first = i128*arr[i].first*16380*1000*1000*1000*1000;
		}
		if (arr[i].second == "mt") {
			s[i].first = i128*arr[i].first*1000000;
		}
		if (arr[i].second == "t") {
			s[i].first = i128*arr[i].first*1000000*1000;
		}
		if (arr[i].second == "kt") {
			s[i].first = i128*arr[i].first*1000000*1000*1000;
		}
		if (arr[i].second == "Mt") {
			s[i].first = i128*arr[i].first*1000000*1000*1000*1000;
		}
		if (arr[i].second == "Gt") {
			s[i].first = i128*arr[i].first*1000000*1000*1000*1000*1000;
		}
	}
	sort(s.begin(), s.end());
	for (ll i = 0; i < n; i++) {
		cout << arr[s[i].second].first << ' ' << arr[s[i].second].second << '\n';
	}
}
