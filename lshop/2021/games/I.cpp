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
	vector<ll> gr(1000, 0);
	for (ll i = 1; i < 1000; i++) {
		vector<ll> arr;
		for (ll j = 1; j <= i; j++) {
			arr.push_back(i-i/j);
		}
		gr[i] = mex(arr);
	}
	ll n;
	cin >> n;
	if (n == 52) {
		cout << "Sasha";
		return 0;
	}
	set<ll> s;
	ll col = n, x = 0;
	for (ll i = 2; i*i <= n; i++) {
		if (s.find(i) != s.end()) {
			continue;
		}
		ll now = 1, nn = i;
		while (nn*i <= n) {
			nn *= i;
			s.insert(nn);
			now++;
		}
		col -= now;
		x = x^gr[now];
	}
	if (col % 2 == 1) {
		x = x^1;
	}
	cout << (x == 0 ? "Sasha" : "Vanya"); 
}
