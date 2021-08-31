#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in("deck.inp");
	ofstream out("deck.out");
	int  i, num, sum, temp = 0;
	long long multi = 1, N, tem, squared = 0, temp2 = 0;
	in >> N; num = N;
	sum = N * (N + 1) / 2;
	while (in >> tem) {
		temp += tem;
		temp2 += tem * tem;
		N--;
	}
	if (N == 1) {
		out << sum - temp;
		in.close();
		out.close();
		exit(0);
	}
	for (i = 1; i < num + 1; i++) { squared += (long long)i * i; }
	sum -= temp;
	squared -= temp2;
	int A = (sum + sqrt(sum * sum - 4 * (sum * sum - (int)squared) / 2)) / 2;
	int B = sum - A;
	if (A > B) { swap(A, B); }
	out << A << "\n" << B;
	in.close();
	out.close();
}

