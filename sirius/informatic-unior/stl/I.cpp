#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<pair<ll, ll>, string>> arr(n, {{0, 0}, ""});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].second;
		cin >> arr[i].first.first;
		cin >> arr[i].first.second;
		arr[i].first.first = abs(arr[i].first.first-180);
		if (arr[i].first.second > 75) {
			arr[i].first.second = 1000000000+arr[i].first.second;
		} else {
			arr[i].first.second = abs(arr[i].first.second-75);
		}
	}
	sort(arr.begin(), arr.end());
	for (ll i = 0; i < n; i++) {
		cout << arr[i].second << '\n';
	}
}
