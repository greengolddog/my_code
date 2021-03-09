#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, string> dict;
    int n;
    cin >> n;
    string f, s;
    for (int i = 0; i < n; i++) {
	cin >> f >> s;
	dict[f] = s;
	dict[s] = f;
    }
    cin >> f;
    cout << dict[f];
}