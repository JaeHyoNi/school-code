#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char arr[3][101];
char found(int s,int i) {
	int s1, s2;
	if (s == 0) { s1 = 1; s2 = 2; }
	else if (s == 1) { s1 = 0; s2 = 2; }
	else { s1 = 0; s2 = 1; }
	if (arr[s1][i] != 'f' && arr[s2][i] != 'f') { return 'f'; }
	else return 's';
}
int main() {
	ifstream in("jug.inp");
	ofstream out("jug.out");
	int temp,k,i=0,s1, s2, s3,N;
	in >> s1 >> s2 >> s3;
	arr[0][s1] =arr[1][s2] = arr[2][s3] =  's';
	while (i < s1) { arr[0][i] = arr[1][i] = arr[2][i] = 'f'; i++; }
	i = s1+1;
	while (i <= s2) {
		if (i - s1 >= s1) {arr[0][i] = 'f';}
		else arr[0][i] = 's';
		i++;
	}
	temp = s1 + s2;
	while (i <= s3) {
		k = i % temp;
		arr[0][i] = arr[1][i] = 's';	
		if      (k < s1)             arr[0][i] = arr[1][i] = 'f';  
		else                        {if (k >= 2 * s1) {arr[0][i] = 'f';}}
		i++;
	}
	if (s3 - s1 >= s1) { arr[0][s3] = 'f'; }
	if (s3 - s2 >= s1) { arr[1][s3] = 'f'; }

	while (i < 100) {
		arr[0][i] = found(0,i-s1);
		arr[1][i] = found(1,i-s2);
		arr[2][i] = found(2,i-s3);
		i++;
	}
	while (in >> k) {
		if (arr[0][k] != 'f' && arr[1][k] != 'f' && arr[2][k] != 'f')  out << "S" << endl;
		else                                                           out << "F" << endl;
	}
	in.close();
	out.close();
}
