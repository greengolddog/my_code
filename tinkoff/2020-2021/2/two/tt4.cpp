#include <bits/stdc++.h>
#define ll int64_t
#define db double
#define elif else if

using namespace std;

vector<pair<ll, ll>> merge(vector<pair<ll, ll>>& arr1, vector<pair<ll, ll>>& arr2) {
	vector<pair<ll, ll>> new_arr;
	ll u1 = 0, u2 = 0;
	while((u1 < arr1.size()) && (u2 < arr2.size())) {
		if (arr1[u1].first > arr2[u2].first) {
			new_arr.push_back(arr1[u1]);
			u1++;
		} else {
			arr2[u2].second += u1;
			new_arr.push_back(arr2[u2]);
			u2++;
		}
	}
	if (u1 == arr1.size()) {
		for (ll i = u2; i < arr2.size(); i++) {
			arr2[i].second += u1;
			new_arr.push_back(arr2[i]);
		}
	} else {
		for (ll i = u1; i < arr1.size(); i++) {
			new_arr.push_back(arr1[i]);
		}
	}
	return new_arr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, l;
	cin >> n >> l;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(1, {0, 0}));
	for (ll i = 0; i < n; i++) {
		db s;
		cin >> s;
		arr[i][0].first = i + l*s;
	}
	while (arr.size() != 1) {
		vector<vector<pair<ll, ll>>> new_arr;
		for(ll i = 0; i < arr.size()/2; i++) {
			new_arr.push_back(merge(arr[i*2], arr[i*2+1]));
		}
		if (arr.size() % 2 == 1) {
			new_arr.push_back(arr[arr.size()-1]);
		}
		arr = new_arr;
	}
	ll summ = 0;
	for (ll i = 0; i < arr[0].size(); i++) {
		summ += arr[0][i].second;
	}
	cout << summ;
}
