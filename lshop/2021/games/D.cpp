#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mex(vector<ll>& arr) {
	if (arr.size() == 0) {
		return 0;
	}
	sort(arr.begin(), arr.end());
	if (arr[0] > 0) {
		return 0;
	}
	for (ll i = 0; i < arr.size()-1; i++) {
		if (arr[i]+1 < arr[i+1]) {
			return arr[i]+1;
		}
	}
	return arr[arr.size()-1]+1;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> gr(n+1, 0);
	for (ll i = 2; i <= n; i++) {
		vector<ll> arr;
		for (ll j = 0; j < i; j++) {
			arr.push_back(gr[j]^gr[i-j-1]);
		}
		gr[i] = mex(arr);
	}
	cout << (gr[n] > 0 ? "Schtirlitz\n" : "Mueller");
	for (ll j = 0; j < n; j++) {
		if ((gr[j]^gr[n-j-1]) == 0) {
			cout << j+1 << ' ';
		}
	}
}
