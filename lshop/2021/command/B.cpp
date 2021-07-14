#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	ll n;
	cin >> n;
	vector<pair<char, ll>> arr(1, {' ', 0});
	for (auto i : s) {
		if (arr.back().first != i) {
			arr.push_back({i, 1});
		} else {
			arr.back().second++;
		}
	}
	arr.erase(arr.begin());
	if (arr.size() == 1) {
		cout << s.size()*n/2;
		return 0;
	}
	ll ans = 0;
	if (arr[0].first == arr.back().first) {
		ans = arr[0].second/2+arr.back().second/2+(arr[0].second+arr.back().second)/2*(n-1);
	} else {
		ans = arr[0].second/2*n+arr.back().second/2*n;
	}
	for (ll i = 1; i < arr.size()-1; i++) {
		ans += arr[i].second/2*n;
	}
	cout << ans;
}
