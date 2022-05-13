#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll, string>> arr(n, {0, ""});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	vector<pair<ll, ll>> s(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		s.second = i;
		if (
}
