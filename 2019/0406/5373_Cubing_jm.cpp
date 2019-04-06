#include <iostream>
#include <tuple>
#include <cstring>

using namespace std;

char u[9];
char d[9];
char f[9];
char b[9];
char l[9];
char r[9];

void rotation_a(char *pl, char di) {

	//1. 자기 면 돌리기
	char tmp[9];
	strncpy(tmp, pl, sizeof(tmp));
	
	if (di == '+') {
		tie(pl[0], pl[1], pl[2]) = { tmp[6], tmp[3], tmp[0] };
		tie(pl[3], pl[4], pl[5]) = { tmp[7], tmp[4], tmp[1] };
		tie(pl[6], pl[7], pl[8]) = { tmp[8], tmp[5], tmp[2] };
	}
	else {
		tie(pl[0], pl[1], pl[2]) = { tmp[2], tmp[5], tmp[8] };
		tie(pl[3], pl[4], pl[5]) = { tmp[1], tmp[4], tmp[7] };
		tie(pl[6], pl[7], pl[8]) = { tmp[0], tmp[3], tmp[6] };
	}
}

void rotation_b(char pl, char di) {

	//2. 옆 면 돌리기
	if (pl == 'U') {
		
		rotation_a(u, di);

		char t1, t2, t3;
		tie(t1, t2, t3) = { b[6],b[7],b[8] };

		if (di == '+') {
			tie(b[6], b[7], b[8]) = { l[8],l[5],l[2] };
			tie(l[8], l[5], l[2]) = { f[2],f[1],f[0] };
			tie(f[2], f[1], f[0]) = { r[0],r[3],r[6] };
			tie(r[0], r[3], r[6]) = { t1, t2, t3 };
		}
		else {
			tie(b[6], b[7], b[8]) = { r[0],r[3],r[6] };
			tie(r[0], r[3], r[6]) = { f[2],f[1],f[0] };
			tie(f[2], f[1], f[0]) = { l[8],l[5],l[2] };
			tie(l[8], l[5], l[2]) = { t1, t2, t3 };
		}
	}
	if (pl == 'D') {

		rotation_a(d, di);

		char t1, t2, t3;
		tie(t1, t2, t3) = { b[2],b[1],b[0] };

		if (di == '+') {
			tie(b[2], b[1], b[0]) = { r[8],r[5],r[2] };
			tie(r[8], r[5], r[2]) = { f[6],f[7],f[8] };
			tie(f[6], f[7], f[8]) = { l[0],l[3],l[6] };
			tie(l[0], l[3], l[6]) = { t1, t2, t3 };
		}
		else {
			tie(b[2], b[1], b[0]) = { l[0],l[3],l[6] };
			tie(l[0], l[3], l[6]) = { f[6],f[7],f[8] };
			tie(f[6], f[7], f[8]) = { r[8],r[5],r[2] };
			tie(r[8], r[5], r[2]) = { t1, t2, t3 };
		}
	}
	if (pl == 'F') {

		rotation_a(f, di);
		
		char t1, t2, t3;
		tie(t1, t2, t3) = { d[2],d[1],d[0] };
		
		if (di == '+') {
			tie(d[2], d[1], d[0]) = { r[6],r[7],r[8] };
			tie(r[6], r[7], r[8]) = { u[6],u[7],u[8] };
			tie(u[6], u[7], u[8]) = { l[6],l[7],l[8] };
			tie(l[6], l[7], l[8]) = { t1, t2, t3 };
		}
		else {
			tie(d[2], d[1], d[0]) = { l[6],l[7],l[8] };
			tie(l[6], l[7], l[8]) = { u[6],u[7],u[8] };
			tie(u[6], u[7], u[8]) = { r[6],r[7],r[8] };
			tie(r[6], r[7], r[8]) = { t1, t2, t3 };
		}
	}
	if (pl == 'B') {

		rotation_a(b, di);
		
		char t1, t2, t3;
		tie(t1, t2, t3) = { d[6],d[7],d[8] };

		if (di == '+') {
			tie(d[6], d[7], d[8]) = { l[2],l[1],l[0] };
			tie(l[2], l[1], l[0]) = { u[2],u[1],u[0] };
			tie(u[2], u[1], u[0]) = { r[2],r[1],r[0] };
			tie(r[2], r[1], r[0]) = { t1, t2, t3 };
		}
		else {
			tie(d[6], d[7], d[8]) = { r[2],r[1],r[0] };
			tie(r[2], r[1], r[0]) = { u[2],u[1],u[0] };
			tie(u[2], u[1], u[0]) = { l[2],l[1],l[0] };
			tie(l[2], l[1], l[0]) = { t1, t2, t3 };
		}
	}
	if (pl == 'L') {

		rotation_a(l, di);
		
		char t1, t2, t3;
		tie(t1, t2, t3) = { b[0],b[3],b[6] };

		if (di == '+') {
			tie(b[0], b[3], b[6]) = { d[0],d[3],d[6] };
			tie(d[0], d[3], d[6]) = { f[0],f[3],f[6] };
			tie(f[0], f[3], f[6]) = { u[0],u[3],u[6] };
			tie(u[0], u[3], u[6]) = { t1, t2, t3 };
		}
		else {
			tie(b[0], b[3], b[6]) = { u[0],u[3],u[6] };
			tie(u[0], u[3], u[6]) = { f[0],f[3],f[6] };
			tie(f[0], f[3], f[6]) = { d[0],d[3],d[6] };
			tie(d[0], d[3], d[6]) = { t1, t2, t3 };
		}
	}
	if (pl == 'R') {
		
		rotation_a(r, di);

		char t1, t2, t3;
		tie(t1, t2, t3) = { b[2],b[5],b[8] };

		if (di == '+') {
			tie(b[2], b[5], b[8]) = { u[2],u[5],u[8] };
			tie(u[2], u[5], u[8]) = { f[2],f[5],f[8] };
			tie(f[2], f[5], f[8]) = { d[2],d[5],d[8] };
			tie(d[2], d[5], d[8]) = { t1, t2, t3 };
		}
		else {
			tie(b[2], b[5], b[8]) = { d[2],d[5],d[8] };
			tie(d[2], d[5], d[8]) = { f[2],f[5],f[8] };
			tie(f[2], f[5], f[8]) = { u[2],u[5],u[8] };
			tie(u[2], u[5], u[8]) = { t1, t2, t3 };
		}
	}
}

int main() {

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		//초기화
		fill(u, u + 9, 'w');
		fill(d, d + 9, 'y');
		fill(f, f + 9, 'r');
		fill(b, b + 9, 'o');
		fill(l, l + 9, 'g');
		fill(r, r + 9, 'b');

		int n;
		cin >> n;
		while (n--) {
			char plane, dir;
			cin >> plane >> dir;
			rotation_b(plane, dir);
		}

		for (int i = 0; i < 9; i++) {
			cout << u[i];
			if ((i + 1) % 3 == 0)
				cout << '\n';
		}
	}
	return 0;
}
