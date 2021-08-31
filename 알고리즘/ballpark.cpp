#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int main() {
	ifstream in("ballpark.inp");
	ofstream out("ballpark.out");
	vector<pair<int, int>> ans;
	int row, col,i = 0, j = 0,MAX=0;
	in >> row >> col;
	string temp;
	in >> temp;
	for (char x : temp) { arr[0][i++] = abs((int)(x - 48) - 1); }
	for (i = 1; i < row; i++) {
		in >> temp;
		for(char x:temp){ 
			arr[i][j] = abs((int)(x - 48) - 1);
			if (j != 0) {
				if (arr[i - 1][j - 1] != 0 && arr[i - 1][j] != 0 && arr[i][j - 1] != 0 && arr[i][j] != 0 ) {
					arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1]))+1;
					if (arr[i][j] > MAX) {
						MAX = arr[i][j];
					}
				}
			}
			j++;
		}
		j = 0;
	}
	int n = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (arr[i][j] == MAX) {
				n++;
				ans.push_back(make_pair(j - MAX + 1+1,abs(i-row)));
			}
		}
	}
	out << MAX << " " << n<<"\n";
	sort(ans.begin(), ans.end());
	for (pair<int, int> x : ans) {
		out << x.first << " " << x.second << "\n";
	}
	in.close();
	out.close();
}

