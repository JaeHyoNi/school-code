#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int>* make_road(int road_num) {
	queue<int>* Air_road = new queue<int> [road_num];
	queue<int> temp_road;
	int Each_num,temp_air;
	for (int i = 0; i < road_num; i++) {
		while (1) {
			cin >> temp_air;
			temp_road.push(temp_air);
			if (temp_air == 0) break;
		}
		Air_road[i] = temp_road;
		temp_road = queue<int>();
	}
	return Air_road;
}

void Take_OFF(queue<int>* Air_road,int road_num) {
	int i, temp_air, road_n;
	int* arr = new int[road_num];
	for (i = 0; i < road_num; i++) {
		if (!Air_road[i].empty())    arr[i] = Air_road[i].front();
		else                         arr[i] = 99999;
	}
	while (1) {
		temp_air = min_element(arr, arr + road_num)-arr;
		if (*min_element(arr, arr + road_num) == 99999) { break; }
		if (arr[temp_air] != 0)          {cout << arr[temp_air]<<endl;}
		Air_road[temp_air].pop();
		if (!Air_road[temp_air].empty()) {arr[temp_air] = Air_road[temp_air].front();}
		else                             {arr[temp_air] = 99999;}
	}
}

int main(void) {
	int road_num, airplane_num;
	cin >> road_num;
	queue<int>* Air_road = make_road(road_num);
	Take_OFF(Air_road, road_num);
	return 0;
}