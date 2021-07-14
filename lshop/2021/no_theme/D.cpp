#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(1, 0);
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '1') {
			arr.push_back(0);
		} else {
			arr.back()++;
		}
	}
	if (arr.size() == 1) {
		cout << n-1;
		return 0;
	}
	arr[0]--;
	ll ans = min(arr[0], (*max_element(arr.begin(), arr.end())-1)/2);
	arr[0]++;
	arr.back()--;
	ans = max(ans, min(arr.back(), (*max_element(arr.begin(), arr.end())-1)/2));
	arr.back()++;
	ans = max(ans, min(arr[0]-1, arr.back()-1));
	arr.pop_back();
	if (arr[0] != 0) {
		arr.erase(arr.begin());
		arr.push_back(0);
	}
	arr.push_back(0);
	sort(arr.begin(), arr.end());
	cout << min((arr.size() == 2 ? 1000000000000000 : arr[2]), max((arr.back()-2)/3, max((arr[arr.size()-2]-1)/2, ans)))+1;
}
