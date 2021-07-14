#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll n;
    	cin >> n;
	vector<bool> arr(n+1, false);
	arr[1] = true;
	arr[2] = true;
	for (ll i = 3; i <= n; i++) {
		if (i % 3 == 0) {
			arr[i] = !arr[i-1] || !arr[i-2];
		}
		if (i % 3 == 1) {
			arr[i] = !arr[i-1] || !arr[i-3];
		}
		if (i % 3 == 2) {
			arr[i] = !arr[i-1] || !arr[i-2] || !arr[i-3];
		}
	}
	cout << 1-arr[n]+1;
}
