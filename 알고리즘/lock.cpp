#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int number, discovered[900], maze_num[30][30], N, M, current;
vector<int> cut;
vector<int> vertex[900], answer;
char maze[30][30];
bool visit[900],visit2[900];
int S, T;
vector<pair<int, int>> ans;


bool check(int shut_off) {
    queue<int> bfs;
    bfs.push(S);
    memset(visit, 0, N * M * sizeof(bool));
    while (!bfs.empty()) {
        current = bfs.front(); bfs.pop();
        if (current == T)  return false;
        for (auto K : vertex[current]) {
            if (K == shut_off) continue;
            if (visit[K] == 0) { bfs.push(K); visit[K] = 1; }
        }
    }
    return true;
}

int dfs(int here, bool isRoot) {
    discovered[here] = ++number;
    int ret = discovered[here];
    int child = 0;
    for (int i = 0; i < vertex[here].size(); i++) {
        int next = vertex[here][i];
        if (discovered[next]) { ret = min(ret, discovered[next]); continue; }
        child++;
        int prev = dfs(next, false);
        if (!isRoot && prev >= discovered[here]) cut.push_back(here);
        ret = min(ret, prev);
    }
    if (isRoot) if (child >= 2) cut.push_back(here);
    return ret;
}

int main(void) {
    ifstream in("lock.inp");
    ofstream out("lock.out");
    in >> N >> M;
    string temp;
    for (int i = 0; i < N; i++) {
        in >> temp;
        for (int j = 0; j < M; j++) {
            maze[i][j] = temp[j];
            maze_num[i][j] = i * M + j;
            if (temp[j] == 'S') { S = maze_num[i][j]; maze[i][j] = '_'; }
            else if (temp[j] == 'T') { T = maze_num[i][j]; maze[i][j] = '_'; }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == '_' && maze[i + 1][j] == '_') {
                vertex[maze_num[i][j]].push_back(maze_num[i + 1][j]);
                vertex[maze_num[i + 1][j]].push_back(maze_num[i][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (maze[i][j] == '_' && maze[i][j + 1] == '_') {
                vertex[maze_num[i][j]].push_back(maze_num[i][j + 1]);
                vertex[maze_num[i][j + 1]].push_back(maze_num[i][j]);
            }
        }
    }
    for (int i = 1; i <= N * N; i++) if (!discovered[i]) dfs(i, true);
    for (auto K : cut)
        if (check(K) && (visit2[K] == false) && (K != T)) {
            answer.push_back(K); visit2[K] = 1;
        }
    if (check(-1)) { out << "0"; in.close(); out.close(); exit(0);  }
    out << answer.size() << "\n";
    for (auto K : answer) ans.push_back(make_pair(K % M + 1, N - K / M));
    sort(ans.begin(), ans.end());
    for (auto K : ans)  out << K.first << " " << K.second << endl;
    in.close();
    out.close();
}