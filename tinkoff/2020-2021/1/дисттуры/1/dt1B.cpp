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
    int maxi, maxii, mini, sct, prs;
    sct = 0;
    mini = min(cc[0] - 1, n-1);
    for (int j = 0;j < mini + 1;j++) {
	sct += cz[j];
    }
    prs = mini;
    maxi = sct;
    maxii = 0;
    for (int i = 1; i <= n; i++) {
	mini = min(i + cc[i] - 1, n-1);
	sct -= cz[i-1];
	if (mini > prs) {
	    for (int j = prs + 1;j < mini + 1;j++) {
		sct += cz[j];
	    }
	}
	if (mini < prs) {
	    for (int j = mini + 1;j < prs + 1;j++) {
		sct -= cz[j];
	    }
	}
	if (sct >= maxi) {
	    maxi = sct;
	    maxii = i;
	}
	prs = mini;
    }
    cout << maxi << ' ' << maxii;
}
