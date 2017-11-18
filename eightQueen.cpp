#include <iostream>

using namespace std;

const int BOARD_LENGTH = 8;

void placeQueen(int row, int* queen, int* plus, int* minus);
bool checkRepeat(int num, const int* array, int value);
void print(const int* queen);

int main(){
	int queen[BOARD_LENGTH];
	int plus[BOARD_LENGTH];
	int minus[BOARD_LENGTH];
	placeQueen(0, queen, plus, minus);
	return 0;
}

void placeQueen(int row, int* queen, int* plus, int* minus){
	for(int i = 0; i < BOARD_LENGTH; i++){
		if(!checkRepeat(row, queen, i) &&
			!checkRepeat(row, plus, row + i) &&
			!checkRepeat(row, minus, row - i)){
			queen[row] = i;
			plus[row] = row + i;
			minus[row] = row - i;
			if(row != BOARD_LENGTH - 1){
				placeQueen(row + 1, queen, plus, minus);
			}
			else{
				print(queen);
			}
		}
	}
}

bool checkRepeat(int num, const int* array, int value){
	for(int i = 0; i < num; i++){
		if(value == array[i]) return true;
	}
	return false;
}

void print(const int* queen){
	for(int i = 0; i < BOARD_LENGTH; i++){
		cout << char('a' + i) << queen[i] + 1 << " ";
	}
	cout << endl;
}

