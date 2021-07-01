#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

string rec(string& s, vector<vector<ll>>& arr, ll l, ll r) {
	if (arr[l][r] == -1) {
		if (r-l == 0) {
			return string(1, s[l]);
		} else {
			return "";
		}
	}
	if (arr[l][r] == 0) {
		return s[l]+rec(s, arr, l+1, r-1)+s[r];
	}
	if (arr[l][r] == 1) {
		return rec(s, arr, l+1, r);
	}
	return rec(s, arr, l, r-1);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	vector<vector<ll>> arr(s.size(), vector<ll>(s.size(), 0));
	vector<vector<ll>> pred(s.size(), vector<ll>(s.size(), -1));
	for (ll i = 0; i < s.size(); i++) {
		arr[i][i] = 1;
	}
	for (ll i = 1; i < s.size(); i++) {
		for (ll j = 0; j < s.size()-i; j++) {
			if (s[j] == s[j+i]) {
				pred[j][j+i] = 0;
				arr[j][j+i] = arr[j+1][j+i-1] + 2;
			} else {
				if (arr[j+1][j+i] > arr[j][j+i-1]) {
					pred[j][j+i] = 1;
				} else {
					pred[j][j+i] = 2;
				}
				arr[j][j+i] = max(arr[j+1][j+i], arr[j][j+i-1]);
			}
		}
	}
	cout << arr[0][s.size()-1] << '\n';
	cout << rec(s, pred, 0, s.size()-1);
}
