#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;
pair<point,int> jum[1000];
vector<pair<point,int>> arr[5];


bool compare(pair<point,int> &a, pair<point,int> &b) {
    int ax = a.first.first, ay = a.first.second;
    int bx = b.first.first, by = b.first.second;
    if (bx * ay - ax * by < 0) return true;
    else if (bx * ay - ax * by == 0) {
        if ((ax * ax + ay * ay) < (bx * bx + by * by)) return true;
        else return false;
    }
    else return false;
}

int main(void) {
    ifstream in("angle.inp");
    ofstream out("angle.out");
    int num; in >> num;
    int page = 0;
    for (int i = 0; i < num; i++) {
        in >> jum[i].first.first >> jum[i].first.second;
        if (jum[i].first.first > 0) {
            if (jum[i].first.second > 0 || jum[i].first.second == 0)  page = 1;
            else page = 4;
        }
        else {
            if (jum[i].first.second > 0 || jum[i].first.second == 0) page = 2;
            else page = 3;
        }
        jum[i].second = i + 1;
        arr[page].push_back(jum[i]);
    }
    for (int i = 1; i < 5; i++) sort(arr[i].begin(), arr[i].end(), compare);
    for (int i = 1; i < 5; i++) { for (auto K : arr[i]) out << K.second << endl; }
    in.close();
    out.close();
}