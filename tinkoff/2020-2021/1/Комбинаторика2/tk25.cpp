#include <bits/stdc++.h>
using namespace std;

void outv(vector<long long> arr, long long n) {
    for (long long i = 0; i < n; i++) {
	cout << arr[i] << ' ';
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, b, k;
    cin >> n >> k;
    vector<long long> arr(k, 0);
    for (long long i = k - 1; i >= 0; i--) {
	arr[i] = k - i;
    }
    while (1 == 1) {
	outv(arr, k);
	b = 0;
	for (long long i = k - 1; i > 0; i--) {
	    if ((arr[i] + 1) < arr[i - 1]) {
		b = 1;
		arr[i] += 1;
		for (long long j = i + 1; j < k; j++) {
		    arr[j] = k - j;
		}
		break;
	    }
	}
	if (b == 0) {
	    if (arr[0] < n) {
		arr[0] += 1;
		for (long long i = 1; i < k; i++) {
		    arr[i] = k - i;
		}
	    } else {
		break;
	    }
	}
    }
}
