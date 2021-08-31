#include <bits/stdc++.h>
using namespace std;

void visit(char** mat,int** check, int x, int y,int &temp,int m, int n) {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
	if (x < 0 || y < 0 || x == m || y == n) {return ;}
	if (!(check[x][y] == 0 && mat[x][y] == '#')) { return ; }
	temp++;
	check[x][y] = 1;
	int i, j;
	for (i = 0; i < 4; i++) {visit(mat, check, x + dx[i], y + dy[i], temp,m,n);}
}

int main() {
	int m, n, k, i, j,vir_num=0,temp,big=0;
	char te;
	cin >> n >> m >> k;
	char** mat;
	int**check;
	mat = new char* [m];
	check = new int* [m];
	for (int i = 0; i < m; i++) { mat[i] = new char[n], check[i] = new int[n]; }
	for (i = 0; i < m; i++) { for (j = 0; j < n; j++) { cin >> te; mat[i][j] = te; check[i][j] = 0; } }
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (mat[i][j] == '#' && check[i][j] == 0) {
				temp = 0;
				visit(mat, check, i, j, temp, m, n);
				if (temp >= k) { vir_num++; }
				if (big < temp) big = temp;
			}
		}
	}
	if(vir_num == 0) cout<<"0";
	else cout << vir_num << " " << big;
	return 0;
}

