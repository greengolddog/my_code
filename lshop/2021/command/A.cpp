#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr1(n, 0), arr2(n, 0);
	vector<pair<ll, ll>> arr(n*2, {-1, -1});
	for (ll i = 0; i < n; i++) {
		ll now;
		cin >> now;
		now--;
		arr1[i]= now*2;
		if (arr[now*2].first == -1) {
			arr[now*2].first = i;
			arr[now*2].second = 0;
		} else {
			arr[now*2+1].first = i;
			arr[now*2+1].second = 0;
			arr1[i]++;
		}
	}
	for (ll i = 0; i < n; i++) {
		ll now;
		cin >> now;
		now--;
		arr2[i] = now*2;
		if (arr[now*2].first == -1) {
			arr[now*2].first = i;
			arr[now*2].second = 1;
		} else {
			arr[now*2+1].first = i;
			arr[now*2+1].second = 1;
			arr2[i]++;
		}
	}
	cout << n*4 << '\n';
	ll col = 0;
	for (ll i = 0; i < n; i++) {
		if (arr[i*2].second == 0) {
			cout << arr[i*2].first+1 << ' ' << arr[i*2].first+1 << '\n';
			swap(arr[i*2].second, arr[arr2[arr[i*2].first]].second);
			swap(arr1[arr[i*2].first], arr2[arr[i*2].first]);
			col++;
		}
		cout << i+1 << ' ' << arr[i*2].first+1 << '\n';
		swap(arr[i*2], arr[arr1[i]]);
		swap(arr1[i], arr2[arr[i*2].first]);
		col++;
		if (arr[i*2+1].second == 1) {
			cout << arr[i*2+1].first+1 << ' ' << arr[i*2+1].first+1 << '\n';
			swap(arr[i*2+1].second, arr[arr1[arr[i*2+1].first]].second);
			swap(arr2[arr[i*2+1].first], arr1[arr[i*2+1].first]);
			col++;
		}
		cout << arr[i*2+1].first+1 << ' ' << i+1 << '\n';
		swap(arr[i*2+1], arr[arr2[i]]);
		swap(arr2[i], arr1[arr[i*2+1].first]);
		col++;
	}
	for (ll i = col; i < n*4; i++) {
		cout << 1 << ' ' << 1 << '\n';
	}
}
