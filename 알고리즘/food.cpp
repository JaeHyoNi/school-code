#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int information[50][5], K;
int m[4], ans[5], temp[5];
vector<int> temp2;
vector<int> ans2;
queue<int> price_0;
int visit[50];
int do;
bool satisfied() {
    for (int i = 0; i < 4; i++) { if (m[i] > temp[i]) return false; }
    return true;
}

bool is_this_answer() {
    if (temp[4] < ans[4]) {
        for (int i = 0; i < 5; i++) { ans[i] = temp[i]; }
        return true;
    }
    else if (temp[4] == ans[4]) {
        if (temp[0] + temp[1] + temp[2] + temp[3] > ans[0] + ans[1] + ans[2] + ans[3]) {
            for (int i = 0; i < 5; i++) { ans[i] = temp[i]; }
            return true;
        }
    }
    return false;
}

void find_answer(int num) {
    if (information[num][4] == 0) return;
    if (temp[4] + information[num][4] > ans[4]) return;
    visit[num + 1] = 1;
    for (int i = 0; i < 5; i++) { temp[i] += information[num][i]; }
    if (satisfied()) {
        if (is_this_answer()) {
            do++;
            vector<int> sw;
            swap(sw, ans2);
            for (int i = 0; i < K + 1; i++) { if (visit[i]) ans2.push_back(i); }
        }
        for (int i = 0; i < 5; i++) { temp[i] -= information[num][i]; }
        visit[num + 1] = 0;
        return;
    }
    for (int i = num + 1; i < K; i++) { find_answer(i); }
    for (int i = 0; i < 5; i++) { temp[i] -= information[num][i]; }
    visit[num + 1] = 0;
    return;
}

int main(void) {
    ifstream in("food.inp");
    ofstream out("food.out");
    ans[4] = 100000;
    in >> K;
    in >> m[0] >> m[1] >> m[2] >> m[3];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 5; j++) {
            in >> information[i][j];
        }
        if (information[i][4] == 0) {
            for (int j = 0; j < 4; j++) {
                m[j] -= information[i][j];
            }
            visit[i + 1] = 1;
        }
    }
    for (int i = 0; i < K; i++) find_answer(i);
    if (ans2.empty()) out << "none";
    for (auto K : ans2) { out << K << " "; }
    cout << do;
}



