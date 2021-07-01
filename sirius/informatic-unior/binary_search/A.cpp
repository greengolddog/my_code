#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll l = 0, r = 1000000001;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		cout << '?' << ' ' << mid << endl;
		string ans;
		cin >> ans;
		if (ans == "YES") {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << "! " << r;
}
