#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, sum, m;
    cin >> n >> m;
    vector<long long> arr2(n);
    sum = 0;
    for (long long i = 0; i < n; i++) {
	cin >> arr2[i];
	sum += arr2[i];
    }
    vector<long long> arr(m + 1, 0);
    arr[0] = 1;
    for (long long i = 0; i < n; i++) {
	for (long long j = sum; j > 0; j--) {
	    if (arr[j] == 0) {
		if ((j - arr2[i]) >= 0) {
		    arr[j] = arr[j - arr2[i]];
		}
	    }
	}
    }
    for (long long i = m; i >= 0; i--) {
	if (arr[i] == 1) {
	    cout << i;
	    break;
	}
    }
}
