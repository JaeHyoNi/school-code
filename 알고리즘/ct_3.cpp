#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
int arr2[8][16];
int num,t,ans;

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
void square3() {
	arr[0][0] = arr2[2][0]; arr[2][2] = arr2[2][4];
	arr[0][2] = arr2[3][0]; arr[2][0] = arr2[3][4];
	arr[0][1] = arr2[1][0] - arr[0][0] - arr[0][2];
	arr[1][0] = arr2[0][0] - arr[0][0] - arr[2][0];
	arr[1][1] = arr2[3][2] - arr[0][2] - arr[2][0];
	arr[1][2] = arr2[2][1] - arr[1][0] - arr[1][1];
	arr[2][1] = arr2[0][1] - arr[0][1] - arr[1][1];
	ans_matrix();
}

void check_answer() {
	for (int i = 0; i < num; i++) {
		if (arr[num][i] != arr2[0][i])
			return;
	}
	int a, b,j=0;
	int temp1[20] = { 0, }, temp2[20] = { 0, };
	
	for (int i = num - 1; i > -1; i--) {
		a = 0; b = i;
		while (a < num && b < num)
			temp1[j] += arr[a++][b++];
		j++;
	}
	for (int i = 1; i < num; i++) {
		a = i; b = 0;
		while (a < num && b < num)
			temp1[j] += arr[a++][b++];
		j++;
	}
	for (int i = 0; i < num + num - 1; i++) {
		if (arr2[2][i] != temp1[i]) {
			return;
		}
	}
	j = 0;
	for (int i = 0; i < num; i++) {
		a = 0; b = i;
		while (a<num && b>-1)
			temp2[j] += arr[a++][b--];
		j++;
	}
	for (int i = 1; i < num; i++) {
		a = i; b = num - 1;
		while (a <num && b>-1)
			temp2[j] += arr[a++][b--];
		j++;
	}
	for (int i = 0; i < num + num - 1; i++) {
		if (arr2[3][i] != temp2[i]) {
			return;
		}
	}
	ans_matrix();
	in.close();
	out.close();
	exit(0);
}

void square(int deep) {
	int i = 0;
	bool pass = true;
	vector<int> block ;
	for (i = 0; i < arr2[1][deep]; i++)		block.push_back(1);
	for (i    ; i < num;           i++)		block.push_back(0);
	do {
		for (i = 0; i < num; i++) {  
			arr[deep][i] = block[i];          
			if (block[i])   arr[num][i]++;
		}
		if (deep == num - 1)
			check_answer();
		else {
			pass = true;
			for (i = 0; i < num; i++) {
				if (arr[num][i] > arr2[0][i])
					pass = false;
			}
			if (pass) 
				square(deep + 1);	
		}
		for (i = 0; i < num; i++) {
			if (block[i])   arr[num][i]--;
		}
	} while (prev_permutation(block.begin(), block.end()));
}

int main(void) {
	int i,j;
	in >> num;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < num; j++)
			in >> arr2[i][j];
	}
	for (i = 2; i < 4; i++) {
		for (j = 0; j < num + num - 1; j++)
			in >> arr2[i][j];
	}
	if (num == 3) square3();
	else square(0);
}
