#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    long double l, r;
    cin >> n;
    vector<long long int> start(n, 0);
    vector<long long int> speed(n, 0);
    for (int i = 0; i < n; i++) {
	cin >> start[i] >> speed[i];
    }
    l = 0;
    r = 10000000000;
    long double mini1, maxi1, mini2, maxi2;
    for (int i; i < 200; i++) {
        long double mid1 = l + ((r - l) / 3);
        long double mid2 = l + ((r - l) / 3 * 2);
	mini1 = start[0] + (speed[0] * mid1);
	mini2 = start[0] + (speed[0] * mid2);
	maxi1 = start[0] + (speed[0] * mid1);
	maxi2 = start[0] + (speed[0] * mid2);
        for (int j = 1; j < n; j++) {
	    long double now = start[j] + (speed[j] * mid1);
	    mini1 = min(mini1, now);
	    maxi1 = max(maxi1, now);
	}
	for (int j = 1; j < n; j++) {
	    long double now = start[j] + (speed[j] * mid2);
	    mini2 = min(mini2, now);
	    maxi2 = max(maxi2, now);
	}
        if (maxi1-mini1 >= maxi2-mini2) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    for (int j = 0; j < n; j++) {
	long double now = start[j] + (speed[j] * l);
	mini1 = min(mini1, now);
	maxi1 = max(maxi1, now);
    }
    cout << setprecision(20) << l << ' ' << setprecision(20) << maxi1 - mini1;
}