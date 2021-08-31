#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
typedef struct point { int x; int y; int num; }point;
typedef struct ans { string str; string str2; int num;  int st; }ans;
vector<point> vec;
vector<ans> answer;
string str,t1,t2;
int match, mis, gap;
int x_end, y_end, temp_num, temp_big,exist_num=99999;
bool exist = 0; 

bool compare(point a, point b) {
	if (a.num > b.num) return true;
	else if (a.num == b.num) {
		if (a.x > b.x) return true;
		else return false;
	}
	else return false;
}
bool compare2(ans a, ans b) {
	if (a.num > b.num) return true;
	else if (a.num == b.num) {
		if (a.st < b.st) return true;
		else if (a.st == b.st) {
			if (a.str < b.str) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

void backtrack(int x, int y, int num) {
	if (x < 2 || y < 2) return;											
	if ((y_end > x_end && y <= x_end) || (y_end < x_end && x <= y_end)) { 
		int k=0;
		if (y <= x_end) {    
			t2 = str.substr(x_end - 1, y_end -x_end);			
			t1 = str.substr(x - 2, x_end-y_end);
			k = x;
		}
		if (x <= y_end) {		
			t2 = str.substr(y_end - 1, x_end - 2); 
			t1 = str.substr(y - 2, y_end - 2);
			k = y;
		}
		if (temp_num - num >= temp_big) {
			temp_big = temp_num - num;
			if (!answer.empty()) if (!(answer.back().str == t1 || answer.back().str2 == t2)) answer.push_back({ t1, t2, temp_num - num ,k });
			else answer.push_back({ t1, t2, temp_num - num ,k });
		}
		return;
	}
	if (num == match && str[x - 2] == str[y - 2]) {									
		if (y_end < x || x_end < y) {
			exist_num = temp_num;
			exist = 1;
			t1 = str.substr(x - 2, x_end-x+1);
			t2 = str.substr(y - 2, y_end-y+1);
			if (x > y) { swap(t1, t2); }
			answer.push_back({ t1,t2,temp_num ,min(x,y) });
			return;
		}
		else  return;
	}
	bool m = str[x - 2] == str[y - 2];
	if (arr[x - 1][y - 1] + match == num) if (m) backtrack(x - 1, y - 1, num - match);
	if (arr[x - 1][y - 1] + mis == num) if (!m) backtrack(x - 1, y - 1, num - mis);
	if (arr[x - 1][y] + gap == num) backtrack(x - 1, y, num - gap);
	if (arr[x][y - 1] + gap == num) backtrack(x, y - 1, num - gap);
}

void find() {
	for (point& c : vec) {
		x_end = c.x; y_end = c.y; temp_num = c.num;
		if ((temp_num < exist_num && exist) || temp_num < temp_big) break; 
		backtrack(c.x, c.y, c.num);
	}
}

int main() {
	ifstream in("music.inp");
	ofstream out("music.out");
		in >> match >> mis >> gap; in >> str;
	int matrix_size = str.size();
	for (int i = 0; i < matrix_size + 2; i++) { arr[0][i] = arr[i][0] = i; }
	for (int i = 2; i < matrix_size + 2; i++) {
		for (int j = i + 1; j < matrix_size + 2; j++) {
			bool m = str[i - 2] == str[j - 2];
			arr[i][j] = max(match * m, max(arr[i - 1][j - 1] + match * m + mis * !m, max(arr[i][j - 1] + gap, max(0, arr[i - 1][j] + gap))));
			if (arr[i][j] >= match) {
				vec.push_back({ i,j,arr[i][j] });
			}
		}
	}
	sort(vec.begin(), vec.end(), compare);
	find();
	sort(answer.begin(), answer.end(), compare2);
	out << answer[0].str << "\n" << answer[0].str2 << "\n" << answer[0].num;
	in.close();
	out.close();
}
