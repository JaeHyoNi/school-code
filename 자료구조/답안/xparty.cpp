#include <bits/stdc++.h>
using namespace std;
typedef map<char, vector<char> > vertex;

bool check(int tar[3]) {
	if (tar[0] == tar[1] && tar[0] == tar[2] && tar[0] == 0) {return 1;}
	else return 0;
}

int main() {
	int num,time=1,i,j; cin >> num;
	vertex road;
	queue<char> q[3];
	map<char, int [3]> visit;
	char fri[3]; for (i = 0; i < 3; i++) { cin >> fri[i]; q[i].push(fri[i]); }
	char ver, temp;
	for (int i = 0; i < num; i++) {
		cin >> ver; 
		while (1) {
			cin >> temp;
			if (temp == '$')	break;
			road[ver].push_back(temp);
			visit[ver][0] = 1;visit[ver][1] = 1;visit[ver][2] = 1;
		} 
	}
	for (i = 0; i < 3; i++) {visit[fri[i]][i] = 0;}
	while (1) {
		for (i = 0; i < 3; i++) {
			int num = q[i].size();
			for (j = 0; j < num; j++) {
				char temp = q[i].front(); q[i].pop();
				for (auto k : road[temp]) {
					visit[k][i] = 0;
					q[i].push(k);
				}
			}
		}
		auto iter = visit.begin();
		for (iter; iter != visit.end();iter++) {
			if (check(iter->second)) {
				cout << iter->first << endl<< time;
				exit(0);
			}
		}
		time += 3;
	}
}

