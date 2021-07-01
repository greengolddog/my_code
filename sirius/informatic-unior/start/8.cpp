#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> speed(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> speed[i];
	}
	set<pair<ll, ll>> arr;
	for (ll i = 0; i < n; i++) {
		arr.insert({0, i});
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		pair<ll, ll> now = *arr.begin();
		arr.erase(arr.begin());
		ll t;
		cin >> t;
		cout << now.second+1 << ' ';
		arr.insert({now.first+t*speed[now.second], now.second});
	}
}
