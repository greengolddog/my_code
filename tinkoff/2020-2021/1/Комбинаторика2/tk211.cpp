#include <bits/stdc++.h>
using namespace std;

void f(string & st, string open, int n) {
    if (st.size() == n) {
	if (open.empty()) {
	    cout << st << "\n";
	}
	return;
    }
    int fl = n - st.size() - 1;
    st += '0';
    if (fl > open.size()) {
	st.back() = '(';
	f(st, open + '(', n);
	st.back() = '[';
	f(st, open + '[', n);
    }
    if (!open.empty() && open.back() == '(') {
	st.back() = ')';
	open.pop_back();
	f(st, open, n);
	open += '(';
    }
    if (!open.empty() && open.back() == '[') {
	st.back() = ']';
	open.pop_back();
	f(st, open, n);
	open += '[';
    }
    st.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("brackets2.in", "r", stdin);
    freopen("brackets2.out", "w", stdout);
    int n;
    cin >> n;
    string st = "";
    f(st, "", n);
}
