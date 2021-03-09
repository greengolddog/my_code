#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> cz(n, 0);
    vector<int> cc(n + 1, 0);
    for (int i = 0; i < n; i++) {
	cin >> cz[i];
    }
    for (int i = 0; i <= n; i++) {
	cin >> cc[i];
    }
    vector<vector<int>> pred(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
	pred[i][i] = cz[i];
	for (int j = i + 1; j < n; j++) {
	    pred[i][j] = pred[i][j - 1] + cz[j];
	}
    }
    int maxi, maxii, mini;
    maxi = 0;
    maxii = 0;
    for (int i = 0; i < n; i++) {
	if (cc[i] > 0) {
	    mini = min(i + cc[i] - 1, n-1);
	    if (pred[i][mini] >= maxi) {
		maxi = pred[i][mini];
		maxii = i;
	    }
	}
    }
    if (maxi == 0) {
	cout << 0 << ' ' << n;
    }
    else {
	cout << maxi << ' ' << maxii;
    }
}
