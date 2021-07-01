#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<pair<ll, char>, pair<string, string>>> arr(n, {{0, 'a'}, {"", ""}});
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[i].second.first = s;
		cin >> s;
		arr[i].second.second = s+' ';
		cin >> s;
		if (s.size() == 3) {
			arr[i].first.first = (s[0]-'0')*10+(s[1]-'0');
			arr[i].first.second = s[2];
		} else {
			arr[i].first.first = s[0]-'0';
			arr[i].first.second = s[1];
		}
		cin >> s;
		arr[i].second.second += s;
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr) {
		cout << i.first.first << i.first.second << ' ' << i.second.first << ' ' << i.second.second << '\n';
	}
}
