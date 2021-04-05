#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

struct point {
	db x;
	db y;
	point(db x = 0.0, db y = 0.0): x(x), y(y) {}
	friend istream& operator>> (istream& inp, point& p);
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
};

istream& operator>> (istream& inp, point& p) {
	inp >> p.x >> p.y;
	return inp;
}

struct vct {
	point p;
	vct(point p2 = point(0, 0), point start = point(0, 0)) {
		p = p2 - start;
	}
	db operator^ (vct v) {
		return p.y*v.p.x - p.x * v.p.y;
	}
};

struct triangle {
	point a;
	point b;
	point c;
	triangle(point a = point(), point b = point(), point c = point()): a(a), b(b), c(c) {}
	db square() {
		vct v1(b, a), v2(c, a);
		return (v1^v2)/2;
	}
	friend istream& operator>> (istream& inp, triangle& t);
};

istream& operator>> (istream& inp, triangle& t) {
	inp >> t.a >> t.b >> t.c;
	return inp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	triangle t;
	cin >> t;
	cout << setprecision(20) << abs(t.square());
}
