#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
vector<int> m(30, 0);

int rec(char cps) {
	int aa = 2, ab = 2, ac = 2;
	if (m[(cps-'a')*10] > 0) {
		m[(cps-'a')*10]--;
		aa = rec('a');
		m[(cps-'a')*10]++;
		if (aa == 1) {
			return 2;
		}
	}
	if (m[(cps-'a')*10+1] > 0) {
		m[(cps-'a')*10+1]--;
		ab = rec('b');
		m[(cps-'a')*10+1]++;
		if (ab == 1) {
			return 2;
		}
	}
	if (m[(cps-'a')*10+2] > 0) {
		m[(cps-'a')*10+2]--;
		ac = rec('c');
		m[(cps-'a')*10+2]++;
		if (ac == 1) {
			return 2;
		}
	}
	return 1;
}

int rec2 () {
	int aa=2,ab=2,ac=2,ba=2,bb=2,bc=2,ca=2,cb=2,cc=2;
	if (m[0] > 0) {
		m[0]--;
		aa = rec('a');
		m[0]++;
		if (aa == 1) {
			return 1;
		}
	}
	if (m[1] > 0) {
		m[1]--;
		ab = rec('b');
		m[1]++;
		if (ab == 1) {
			return 1;
		}
	}
	if (m[2] > 0) {
		m[2]--;
		ac = rec('c');
		m[2]++;
		if (ac == 1) {
			return 1;
		}
	}
	if (m[10] > 0) {
		m[10]--;
		ba = rec('a');
		m[10]++;
		if (ba == 1) {
			return 1;
		}
	}
	if (m[11] > 0) {
		m[11]--;
		bb = rec('b');
		m[11]++;
		if (bb == 1) {
			return 1;
		}
	}
	if (m[12] > 0) {
		m[12]--;
		bc = rec('c');
		m[12]++;
		if (bc == 1) {
			return 1;
		}
	}
	if (m[20] > 0) {
		m[20]--;
		ca = rec('a');
		m[20]++;
		if (ca == 1) {
			return 1;
		}
	}
	if (m[21] > 0) {
		m[21]--;
		cb = rec('b');
		m[21]++;
		if (cb == 1) {
			return 1;
		}
	}
	if (m[22] > 0) {
		m[22]--;
		cc = rec('c');
		m[22]++;
		if (cc == 1) {
			return 1;
		}
	}
	return 2;
}

int main() {
	int a,c;
	string i3;
	char i1,i2;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> i3;
		i1 = i3[0];
		i2 = i3[i3.size()-1];
		m[((i1-'a')*10)+(i2-'a')]++;
	}
	if (rec2() == 1) {
		cout << "Artem";
	} else {
		cout << "Boris";
	}
}