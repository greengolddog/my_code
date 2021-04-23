#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n, l, stc, r, s, t;
	cin >> n >> l;
	l = l * 2 - 2;
	stc = 0;
	for (ll i = 0; i < n; i++) {
		cin >> r >> s >> t;
		if ((l == 0) or (l == 2)) {
			stc++;
		} else {
			if (t >= l) {
				stc++;
			} else {
				r--;
				s--;
				if ((s%l) < ((s+t)%l)) {
					if (((((s%l) >= r) and (((s+t)%l) <= r)) or (((s%l) <= r) and (((s+t)%l) >= r))) or ((((s%l) >= (l-r)) and (((s+t)%l) <= (l-r))) or (((s%l) <= (l-r)) and (((s+t)%l) >= (l-r))))) {
						stc++;
					}
				} else {
					if (((((s%l) <= r) and (((s+t)%l) <= r)) or (((s%l) >= r) and (((s+t)%l) >= r))) or ((((s%l) >= (l-r)) and (((s+t)%l) >= (l-r))) or (((s%l) <= (l-r)) and (((s+t)%l) <= (l-r))))) {
						stc++;
					}
				}
			}
		}
	}
	cout << stc;
}