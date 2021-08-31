#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int n = 0;

int main() {
	ifstream in("words.inp");
	ofstream out("words.out");
	int num;
	in >> num;
	string t, t1;
	map<string, int> gra;
	int nnum = round((double)num / 2);
	for (int i = 0; i < num; i++) {
		in >> t1;
		gra[t1] ++;
		if (gra[t1] == nnum) {
			out << t1;
			in.close();
			out.close();
			exit(0);
		}
	}
	out << "NONE";
	in.close();
	out.close();
}
