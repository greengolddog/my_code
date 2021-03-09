#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    vector<int> s;
    while (cin >> a) {
	if (a == "+") {
	    s[s.size() - 2] += s[s.size() - 1];
	    s.pop_back();
	} elif(a == "-") {
	    s[s.size() - 2] -= s[s.size() - 1];
	    s.pop_back();
	} elif(a == "*") {
	    s[s.size() - 2] *= s[s.size() - 1];
	    s.pop_back();
	} else {
	    s.push_back(stoi(a));
	}
    }
    cout << s[0];
}
