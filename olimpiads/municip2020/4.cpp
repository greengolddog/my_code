#include <bits/stdc++.h>
using namespace std;
int main() {
    long long  n, m, now1, now2;
    long long l, r;
    cin >> n >> m;
    vector<long long> start(n+m, 0);
    for (int i = 0; i < n+m; i++) {
	cin >> start[i];
    }
    l = -1;
    r = 10000000000000;
    long long mini1, maxi1, mini2, maxi2;
    while ((r - l) > 2) {
        long long mid1 = l + ((r - l) / 3);
        long long mid2 = l + ((r - l) / 3 * 2);
	now1 = 0;
        for (int j = 0; j < n+m; j++) {
	    if (j < n) {
		now1 += abs(start[j] + mid1);
	    } else {
		now1 += abs(start[j] - mid1);
	    }
	}
	now2 = 0;
	for (int j = 0; j < n+m; j++) {
	    if (j < n) {
		now2 += abs(start[j] + mid2);
	    } else {
		now2 += abs(start[j] - mid2);
	    }
	}
        if (now1 >= now2) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    cout << (l + r) / 2;
}