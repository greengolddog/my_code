#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
#define db double

using namespace std;

struct point {
	db x;
	db y;
	point(db x = 0.0, db y = 0.0): x(x), y(y){}
	friend istream& operator>> (istream& inp, point p);
}

istream& operstor>> (istream& inp, point p) {
	inp >> p.x >> p.y;
	return inp;
}

struct triangle {
	point a;
	point b;
	point c;
	triangle(point a = point(), point b = point(), point c = point()): a(a), b(b), c(c){}
	db square() {

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, r;
	cin >> n >> r;
}
