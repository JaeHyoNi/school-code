#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> string_box;

char DNA[4] = { 'a','c','g','t' };
int N[4];
struct Box {
    string_box xbox[4];
    int xbox_num[4] = { 0, };
};
int temp;
char matrix[200000][1002];
int num;
ofstream out("read.out");


void BOX_PRINT(Box& box) {
    for (int i = 0; i < 4; i++) {
        if (box.xbox_num[i] != 0) {
            out << endl << i << "���� " << box.xbox_num[i] << "��" << endl;
            for (auto K : box.xbox[i])
                out << matrix[K];
        }
    }
    out << endl;
}

void select_max(string_box& box) {
    string ttemp = matrix[box[0]];
    for (auto K : box) {
        if (matrix[K] > ttemp) {
            ttemp = matrix[K];
        }
    }
    out << "��: " <<ttemp;
    return;
}


//num�� ã�� ��° deep�� ���� 1���� 2�� �� ������ 2���� 
void radix_find(int num, int deep, string_box& box) {
    //cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
    out << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
    printf("num = %d\n", num);
    out << "num = " << num << endl;
    int t_num = 0, i = 0;
    Box temp;
    string_box temp_box;

    for (auto K : box) {
        if (matrix[K][deep] == '\0' || matrix[K][deep] == '\n') {
            num--;
            out << "num ��ȭ num: " << num << endl;
            if (num == 0) {
                out << "��: " << matrix[K];
                return;
            }
            continue;
        }
        t_num = 0;
        for (auto D : DNA) {
            if (D == matrix[K][deep])
                break;
            t_num += 1;
        }
        temp.xbox[t_num].push_back(K);
        temp.xbox_num[t_num]++;
    }

     BOX_PRINT(temp);


    for (i = 0; i < 4; i++) {
        //num�� ���Ե� �迭�� ã�´�
        if (temp.xbox_num[i] == 0) { continue; }
        if (num - temp.xbox_num[i] > 0) num -= temp.xbox_num[i];
        else if (num - temp.xbox_num[i] == 0) { num = 0; select_max(temp.xbox[i]); return; }
        else break;
    }

    if (temp.xbox_num[i] == 2) {
        if (num == 1) {
            if (strcmp(matrix[temp.xbox[i][0]], matrix[temp.xbox[i][1]]) > 0)
                out << " ��: " << matrix[temp.xbox[i][1]];
            else
                out <<"��: " << matrix[temp.xbox[i][0]];
        }
        return;
    }
    else  radix_find(num, deep + 1, temp.xbox[i]);
    return;
}


int main(void) {
    FILE* fs = fopen("3.inp", "r");

    Box b1;
    while (fgets(matrix[num], 1002, fs) != NULL) {
        temp = 0;
        for (auto K : DNA) {
            if (matrix[num][0] == 10) break;
            if (K == matrix[num][0]) break;
            temp += 1;
        }
        b1.xbox[temp].push_back(num);
        b1.xbox_num[temp]++;
        num++;
        cout << num << endl;
    }
    BOX_PRINT(b1);
    for (int i = 0; i < 4; i++)   N[i] = floor((i + 1) * num / 5 + 1);
    cout << num << endl;
    for (auto K : N) { cout << K << " "; }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        int temp = N[i], k;
        for (k = 0; k < 4; k++) {
            if (temp - b1.xbox_num[k] > 0) temp -= b1.xbox_num[k];
            else break;
        }
        if (temp - b1.xbox_num[k] == 0) { select_max(b1.xbox[k]); }
        else radix_find(temp, 1, b1.xbox[k]);
    }
    fclose(fs);
    out.close();
}