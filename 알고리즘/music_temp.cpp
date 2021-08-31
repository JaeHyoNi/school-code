#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
typedef struct point { int x; int y; int num; }point;
vector<point> vec;
string str;
int match, mis, gap;
int str1_st, str2_st, str1_end, str2_end,temp_num;
string str1, str2;
string t1, t2;

bool compare(point a, point b) {
	if (a.num > b.num) return true;
	else if (a.num == b.num) {
		if (a.x > b.x) return true;
		else return false;
	}
	else return false;
}

void P_Mat(int i) {
	int matrix_size = i;
	for (int i = 0; i < matrix_size + 3; i++) {
		if (i < 3) printf("   0");
		else printf("%4c", str[i - 3]);
	}
	cout << endl;
	for (int i = 0; i < matrix_size + 2; i++) {
		if (i < 2) printf("   0");
		else printf("%4c", str[i - 2]);
		for (int j = 0; j < matrix_size + 2; j++) {
			printf("%4d", arr[i][j]);

		}
		printf("\n");
	}
}

void backtrack(int x, int y, int num) {
	if (str1_end > str2_end) {
		if (y < str2_end) {
			//cout << "중복"; 
			return;
		}
	}
	else if (x < str1_end) {
		//cout << "중복"; 
		return;
	}
	if (x < 2 || y < 2) { return; }
	if (num == match && str[x-2]==str[y-2] ) {
		str1_st = y; str2_st = x;
		str1.push_back(str[x - 2]);
		str2.push_back(str[y - 2]);
		//printf("[str1=%d~%d]\n[str2=%d~%d]\n", str1_st, str1_end, str2_st, str2_end);
		if (str1_end < str2_st || str2_end < str1_st) {
			//cout << "중복되지않음\n";
			reverse(str1.begin(), str1.end());
			reverse(str2.begin(), str2.end());
			//cout << "정답 하나 str1 = " << str1 << " str2 = " << str2 << endl;
			if (x > y) {
				cout << str1 << "\n" << str2<<"\n"<<temp_num;
			}
			else
				cout << str << "\n" << str2 << "\n" << temp_num;
			str1.pop_back();
			str2.pop_back();
			exit(0);
		}
		else {
			reverse(str1.begin(), str1.end());
			reverse(str2.begin(), str2.end());
			cout << "오답 str1 = " << str1 << " str2 = " << str2 << endl;
			reverse(str1.begin(), str1.end());
			reverse(str2.begin(), str2.end());
			str1.pop_back();
			str2.pop_back();
			cout << "중복됨\n";
		}
		//cout << "빽\n";
	}
	bool m = str[x - 2] == str[y - 2];
	if (arr[x - 1][y - 1] + match == num) {
		if (m) {
		
			///cout << "대각선 실행\n";
			str1.push_back(str[y - 2]);
			str2.push_back(str[x - 2]);
			//printf("str1에 %c추가 str2에 %c 추가\n", str[y - 2], str[x - 2]);
			backtrack(x - 1, y - 1, num - match);
			str1.pop_back(); str2.pop_back();
			//cout << "빽\n";
		}
	}
	if (arr[x - 1][y - 1] + mis == num) {
		if (!m) {
			
			//cout << "대각선mis 실행\n";
			str1.push_back(str[y - 2]);
			str2.push_back(str[x - 2]);
			//printf("str1에 %c추가 str2에 %c 추가\n", str[y - 2],str[x-2]);
			backtrack(x - 1, y - 1, num - mis);
			str1.pop_back(); str2.pop_back();
			//cout << "빽\n";
		}
	}
	if (arr[x - 1][y] + gap == num) {
		
		//cout << "위쪽 실행\n";
		str2.push_back(str[x - 2]);
		//printf("str2에 %c추가\n", str[x - 2]);
		backtrack(x - 1, y, num - gap);
		str2.pop_back();
		//cout << "빽\n";
	}
	if (arr[x ][y-1] + gap == num) {
		
		//cout << "왼쪽 실행\n";
		str1.push_back(str[y - 2]);
		//printf("str1에 %c추가\n", str[y - 2]);
		backtrack(x, y-1, num - gap);
		str1.pop_back();
		//cout << "빽\n";
	}
}

void find() {
	for (point& c : vec) {
		//printf("x=%d y=%d num=%d\n", c.x, c.y, c.num);
		str1_end = c.y; str2_end = c.x;
		temp_num = c.num;
		backtrack(c.x, c.y, c.num);
		//printf("없넹\n");
	}
}
int main() {
	ifstream in("3.inp");
	ofstream out("jug.out");
	in >> match >> mis >> gap; in >> str;
	int matrix_size = str.size();
	for (int i = 0; i < matrix_size+2; i++) { arr[0][i] = arr[i][0] = i; }
	cout << matrix_size << endl;
	for (int i = 2; i < matrix_size + 2; i++) {
		for (int j = i + 1; j < matrix_size + 2; j++) {
			bool m = str[i - 2] == str[j - 2];
			arr[i][j] = max(match * m, max(arr[i - 1][j - 1] + match * m + mis * !m, max(arr[i][j - 1] + gap, max(0, arr[i - 1][j] + gap))));
			if (arr[i][j] >= match) {
				vec.push_back({ i,j,arr[i][j] });
			}
		}
	}
	//P_Mat(matrix_size);
	sort(vec.begin(), vec.end(), compare);
	//for (point& x : vec) { printf("[i=%3d, j=%3d , num = %3d]\n", x.x, x.y, x.num); } //벡터출력함수
	cout << endl;
	find();
	in.close();
	out.close();	
}
