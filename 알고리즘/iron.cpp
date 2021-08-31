#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[26], answer[26], MAX;
vector<pair<int, int>> road[26];
vector<int> contain_a;
bool used[26], pass;
string ans, temp;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    else return false;
}

bool check() {
    for (auto K : contain_a) { if (used[K] == 0) return true; }
    return false;
}

void check_answer(int new_weight, int length) {
    if (MAX < new_weight) {
        MAX = new_weight;
        ans = "";
        for (int i = 0; i < length; i++) ans.push_back((char)(arr[i] + 'a'));
    }
    else if (MAX == new_weight) {
        temp = "";
        for (int i = 0; i < length; i++) temp.push_back((char)(arr[i] + 'a'));
        if (temp < ans) ans = temp;
    }
}

int long_road(int current, int weight, int length) {
    vector<pair<int, int>>& temp = road[current];
    int edge_n = road[current].size();
    int i = 0;
    if (temp[0].first == 0) {
        check_answer(weight + temp[0].second, length);
        if (!check()) {
            if (length != 0) arr[length - 1] = 0;
            used[current] = 0;
            return 0;
        }
        i = 1;
    }
    if (current == 0) { edge_n--; }
    for (i; i < edge_n; i++) {
        if (used[temp[i].first] == 0) {
            used[temp[i].first] = 1;
            arr[length] = temp[i].first;
            long_road(temp[i].first, weight + temp[i].second, length + 1);
            arr[length] = 0;
            used[temp[i].first] = 0;
        }
    }
    return 0;
}

int main(void) {
    ifstream in("iron.inp");
    ofstream out("iron.out");
    in >> N >> M;
    char c1, c2;
    int weight;
    for (int i = 0; i < M; i++) {
        in >> c1 >> c2 >> weight;
        road[c1 - 'a'].push_back(make_pair(c2 - 'a', weight));
        road[c2 - 'a'].push_back(make_pair(c1 - 'a', weight));
    }
    for (auto K : road[0]) contain_a.push_back(K.first);
    for (int i = 0; i < 26; i++) sort(road[i].begin(), road[i].end(), compare);
    long_road(0, 0, 1);
    out << MAX << endl;
    for (auto K : ans) {
        out << K << " ";
    }
}



