#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
int arr2[8][16];
int num, t, ans;
int diagonal1[16], diagonal2[16];

ifstream in("ct.inp");
ofstream out("ct.out");

void ans_matrix() {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (arr[i][j]) out << "B ";
			else out << "- ";
		}
		out << endl;
	}
}

void check_answer() {
	for (int i = 0; i < num * 2 - 1; i++) {
		if (diagonal1[i] != arr2[2][i]) return;
		if (diagonal2[i] != arr2[3][i]) return;
	}
	ans_matrix();
	in.close();
	out.close();
	exit(0);
}

void square(int deep) {
	int i = 0;
	bool pass = true;
	vector<int> block;
	for (i = 0; i < arr2[1][deep]; i++)		block.push_back(1);
	for (i; i < num; i++)		block.push_back(0);
	do {
		for (i = 0; i < num; i++) {
			arr[deep][i] = block[i];
			if (block[i]) {
				arr[num][i]++;
				diagonal1[deep - i + num - 1]++;
				diagonal2[deep + i]++;
			}
		}
		pass = true;
		for (i = 0; i < num; i++) {
			if (arr[num][i] > arr2[0][i]) { pass = false; break; }
			if (diagonal1[i] > arr2[2][i]) { pass = false; break; }
			if (diagonal2[i] > arr2[3][i]) { pass = false; break; }
		}
		if (pass) {
			if (deep == num - 1) check_answer();
			else square(deep + 1);
		}
		for (i = 0; i < num; i++) {
			if (block[i]) {
				arr[num][i]--;
				diagonal1[deep - i + num - 1]--;
				diagonal2[deep + i]--;
			}
		}
	} while (prev_permutation(block.begin(), block.end()));
}
int main(void) {
	int i, j;
	in >> num;
	for (i = 0; i < 2; i++) { for (j = 0; j < num; j++)           in >> arr2[i][j]; }
	for (i = 2; i < 4; i++) { for (j = 0; j < num + num - 1; j++) in >> arr2[i][j]; }
	square(0);
}
