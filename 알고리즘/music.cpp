#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
typedef struct point { int x; int y; int num; }point;
vector<point> vec;
string str;
int match, mis, gap;
int str1_st, str2_st, str1_end, str2_end, temp_num,temp_big;
int t_max,t_x,t_y;
int exist_num = 9999999;
bool exist = 0; 
int gap_step[2] = { 0,0 }, mis_step = 0;
string str1, str2;
string t1, t2;
typedef struct ans { string str; string str2; int num;  int st; }ans;
vector<ans> answer;

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
			if (a.str < b.str)
				return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

void backtrack(int x, int y, int num) {
	if (x < 2 || y < 2) { return; }															
	if ((str1_end > str2_end && y<=str2_end) || (str1_end<str2_end && x<=str1_end)) {               
 		if (y <= str2_end) { 
			num = num + mis * mis_step + gap *( gap_step[0]+gap_step[1]);
			t1 = str1; t2 = str2;
			for (int k = 0; k < mis_step; k++) { t1.pop_back(); x++;  t2.pop_back(); y++; }
			for (int k = 0; k < gap_step[0]; k++) { t2.pop_back(); x++; }
			for (int k = 0; k < gap_step[1]; k++) { t1.pop_back(); y++; }
			int k = min(x, y);
			if (temp_num - num >= temp_big) {
				temp_big = temp_num - num;
				reverse(t1.begin(), t1.end());
				reverse(t2.begin(), t2.end());
				if (x > y) { swap(t1, t2); }
				if (!answer.empty()) {
					if (!(answer.back().str == t1 || answer.back().str == t2)) {
						answer.push_back({ t2, t1, temp_num - num ,k });
					}
				}
				else answer.push_back({ t2, t1, temp_num - num ,k });
			}
			return;
		}
	}
	if (num == match && str[x - 2] == str[y - 2]) {											
		str1_st = y; str2_st = x;
		str1.push_back(str[y - 2]);															
		str2.push_back(str[x - 2]);
		if (str1_end < str2_st || str2_end < str1_st) {
			reverse(str1.begin(), str1.end());
			reverse(str2.begin(), str2.end());
			exist_num = temp_num;
			exist = 1;
			t1 = str1; t2 = str2;
			if (x > y) { swap(t1, t2); }
			answer.push_back({ t2,t1,temp_num ,min(x,y)});
			reverse(str1.begin(), str1.end());
			reverse(str2.begin(), str2.end());
			str1.pop_back();
			str2.pop_back();
			return;
		}
		else {
			str1.pop_back();
			str2.pop_back();
			return;
		}
	}
	bool m = str[x - 2] == str[y - 2];
	if (arr[x - 1][y - 1] + match == num) {											
		if (m) {
			gap_step[0]=gap_step[1] = mis_step = 0;
			str1.push_back(str[y - 2]);
			str2.push_back(str[x - 2]);
			backtrack(x - 1, y - 1, num - match);
			str1.pop_back(); str2.pop_back();
		}
	}
	if (arr[x - 1][y - 1] + mis == num) {												
		if (!m) {
			mis_step++;
			str1.push_back(str[y - 2]);
			str2.push_back(str[x - 2]);
			backtrack(x - 1, y - 1, num - mis);
			str1.pop_back(); str2.pop_back();
			mis_step--;
		}
	}
	if (arr[x - 1][y] + gap == num) {												
		gap_step[0]++;
		str2.push_back(str[x - 2]);
		backtrack(x - 1, y, num - gap);
		str2.pop_back();
		gap_step[0]--;
	}
	if (arr[x][y - 1] + gap == num) {													
		gap_step[1]++;
		str1.push_back(str[y - 2]);
		backtrack(x, y - 1, num - gap);
		str1.pop_back();
		gap_step[1]--;
	}
}

void find() {																	 
	for (point& c : vec) {
		str1_end = c.y; str2_end = c.x;
		temp_num = c.num;
		if ((temp_num < exist_num && exist)  || temp_num<temp_big) { break; }
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
