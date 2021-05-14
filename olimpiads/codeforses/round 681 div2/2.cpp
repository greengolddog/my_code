#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, s, c, i1, i2, sum;
    cin >> n >> s;
    vector<long long> arr1;
    for (long long i = 1; i <= n; i++) {
	arr1.push_back(i);
    }
    for (long long i = 0; i < s; i++) {
	cin >> c >> i1;
	if (c == 1) {
	    cin >> i2;
	    sum = 0;
	    for (long long j = i1 - 1; j < i2; j++) {
		sum += arr1[j];
	    }
	    cout << sum << "\n";
	} else {
	    for (long long j = 0; j < i1; j++) {
		next_permutation(arr1.begin(), arr1.end());
	    }
	}
    }
}