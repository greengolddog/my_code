#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector<int>> su(n*10, vector<int>(m*10, 0));
    su[2][2] = 1;
    for (int i = 5; i <= (4+n)*4; i++) {
	for (int j = 2; j <= i-2; j++) {
	    if (i-j <= n+1) {
		if (j <= m+1) {
		    su[i-j][j] = su[i-j-2][j-1]+su[i-j-2][j+1]+su[i-j-1][j-2]+su[i-j+1][j-2];
		}
	    }
	}
    }
    cout << su[n+1][m+1] << "\n";
}