#include <iostream>
#include <vector>
#include <string>

using namespace std;

char numLib[10][8] = {"|-| |-|", "  |   |", " -|-|- ", " -|- -|", "| |-  |", "|- - -|", "|- -|-|", " -|   |", "|-|-|-|", "|-|- -|"};
void PrintNum(int num, int size, int row){
    if (row % 2 == 1){
        cout << ' ';
        for (int i = 0; i < size; i++)
            cout << numLib[num][row];
        cout << ' ';
    }
    else if (row == 2){
        cout << numLib[num][0];
        for (int i = 0; i < size; i++)
            cout << ' ';
        cout << numLib[num][2];
    }
    else{
        cout << numLib[num][4];
        for (int i = 0; i < size; i++)
            cout << ' ';
        cout << numLib[num][6];
    }
}
int main(){
    int size; string num;
    cin >> size >> num;
    for (int row = 1; row <= 5; row++){
        if (row % 2 == 1){
            for (int i = 0; i < num.size(); i++){
                PrintNum(num[i] - '0', size, row);
                cout << ' ';
            }
            cout << endl;
        }
        else{
            for (int i = 0; i < size; i++){
                for (int i = 0; i < num.size(); i++){
                    PrintNum(num[i] - '0', size, row);
                    cout << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}
