#include <bits/stdc++.h>
#define ll long long
#define elif else if

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll c, p, n;
    	cin >> c >> p >> n;
    	ll t = 0, lp = 0, f = 0;
    	while (true) {
	    	ll nlp = max(0.0, ceil(((c - lp) * 1.0)/((f * p + 1) * 1.0))) * (f * p + 1) + lp - c;
	    	if ((t + max(0.0, ceil(((c - lp) * 1.0) / ((f * p + 1) * 1.0))) + max(0.0, ceil(((n - nlp) * 1.0)/((f * p + p + 1) * 1.0)))) <=
				(t + max(0.0, ceil(((n - lp) * 1.0)/((f * p + 1) * 1.0))))) {
		    	t += max(0.0, ceil(((c - lp) * 1.0) / ((f * p + 1) * 1.0)));
		    	lp = nlp;
		    	f++;
		} else {
			break;
		}
	}
	cout << int(t+max(0.0, ceil(((n - lp) * 1.0)/((f * p + 1) * 1.0))));
}
