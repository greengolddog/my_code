#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll now = 1, stc = -1;
	while (true) {
		if ((a+now-1)/now*now > b) {
			break;
		}
		now = now*2;
		stc++;
	}
	ll now5 = 1, stc5 = -1;
	while (true) {
		if ((a+now5-1)/now5*now5 > b) {
			break;
		}
		now5 = now5*5;
		stc5++;
	}
	cout << min(stc, stc5);
}
