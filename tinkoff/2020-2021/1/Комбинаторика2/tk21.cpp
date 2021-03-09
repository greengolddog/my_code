#include <bits/stdc++.h>
using namespace std;

void outv(vector<long long> arr) {
    for (auto i : arr) {
	cout << i;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, b;
    cin >> n;
    vector<long long> arr(n, 0);
    outv(arr);
    while (1 == 1) {
	b = 0;
	for (long long i = n - 1; i >= 0; i--) {
	    if (arr[i] == 0) {
		b = 1;
		arr[i] = 1;
		for (long long j = i + 1; j < n; j++) {
		    arr[j] = 0;
		}
		break;
	    }
	}
	if (b == 0) {
	    break;
	}
	outv(arr);
    }
}