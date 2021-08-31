#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

stack<int>* make_yard(int yard_num) {
	stack<int>* Yard = new stack<int>[yard_num];
	stack<int> temp_yard;
	int Each_num, temp;
	for (int i = 0; i < yard_num; i++) {
		cin >> Each_num;
		for (int j = 0; j < Each_num; j++) {
			cin >> temp;
			temp_yard.push(temp);
		}
		Yard[i] = temp_yard;
		temp_yard = stack<int>();
	}
	return Yard;
}

void Clean(stack<int>* Yard, int yard_num) {
	int* arr = new int[yard_num];
	int i = 0, max, temp_num, min;
	for (i = 0; i < yard_num; i++) {arr[i] = Yard[i].size();}
	if (*max_element(arr, arr + yard_num) == 0 || *max_element(arr, arr + yard_num) - *min_element(arr, arr + yard_num) <= 1)
		return;
	while (1) {  
		temp_num = -1;
		for (i = 0; i < yard_num; i++) {     
			if (arr[i] >= temp_num && arr[i] != 0) {
				if (arr[i] == temp_num) { if (Yard[i].top() > Yard[max].top()) max = i; }
				else { temp_num = arr[i];   max = i; }
			}
		}
		min = min_element(arr, arr + yard_num) - arr;
		Yard[min].push(Yard[max].top());
		Yard[max].pop();
		arr[min]++; arr[max]--;
		if (*max_element(arr, arr + yard_num) - *min_element(arr, arr + yard_num) <= 1)break;
	}
}
void Print(stack<int>* Yard, int yard_num) {
	stack<int> temp;
	for (int i = 0; i < yard_num; i++) {
		cout << i + 1 << " > ";
		if (Yard[i].empty()) {cout << endl; continue;}
		while (!Yard[i].empty()) {temp.push(Yard[i].top());Yard[i].pop();}
		while (!temp.empty()) {cout << temp.top() << " ";temp.pop();}
		stack<int> temp();
		cout << endl;
	}
}

int main(void) {
	int yard_num;
	cin >> yard_num;
	stack<int>* Yard = make_yard(yard_num);
	Clean(Yard, yard_num);
	Print(Yard, yard_num);
	return 0;
}