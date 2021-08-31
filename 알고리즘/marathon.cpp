#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<char,int> arr[27];
bool used[27];
int cur = 0, id = 0,new_id=0,full_id=0,num=0;
vector<pair<char, int>> road[26];
map<char, int> a_road;
string ans, temp_ans;
int main(void) {
	ifstream in("marathon.inp");
	ofstream out("marathon.out");
	in >> N >> M;
	int i, weight;
	char c1, c2;
	for (i = 0; i < M; i++) {
		in >> c1 >> c2 >> weight;
		road[c1 - 'a'].push_back(make_pair(c2, weight));
		road[c2 - 'a'].push_back(make_pair(c1, weight));
	}
	for (auto K : road[0]) {
		a_road[K.first] = K.second;
	}
	arr[0] = make_pair('a',0);
	used['a'-'a'] = true;
	bool yes = 0;
	while (1) {
		full_id = road[(int)arr[cur].first - 'a'].size();
		vector<pair<char, int>>& temp = road[(int)arr[cur].first - 'a'];
		if (arr[cur + 1].first == 0 || arr[cur+1].first == NULL) {
			id = 0; i = 0;
		}
		else {
			id = new_id = arr[cur + 1].second;
			i = id + 1;
		}
		if (i!= 0) {
			num -= temp[id].second;
			used[(int)arr[cur+1].first - 'a'] = false;
		}
		arr[cur + 1] = make_pair(NULL, 0); 
		yes = false;
		for (i; i < full_id; i++) {
			if (num + temp[i].second <= 42 && used[(int)temp[i].first - 'a'] == false) {
				yes = true;
				id = i;
				break;
			}
		}
		temp_ans = "";
		if (!yes) {cur -= 1;}
		else {
			cur++;
			arr[cur] = make_pair(temp[id].first, id);
			num += temp[id].second;
			used[(int)arr[cur].first - 'a'] = true;
			if (a_road[arr[cur].first]!=0) {
				if (num + a_road[arr[cur].first]== 42) {
					for (int j = 0; j < cur+1; j++) {
						temp_ans.push_back(arr[j].first);
					}
					if (ans == "") ans = temp_ans;
					else if (cur + 1 > ans.size()) {
						ans = temp_ans;
					}
					else if (cur + 1 == ans.size()) {
						if (temp_ans < ans) {
							ans=temp_ans;
						}
					}
				}
			}
			continue;
		}
		if (cur == -1) break;
	}
	out << ans.size() << endl;
	for (auto K : ans) {
		out << K << " ";
	}
}