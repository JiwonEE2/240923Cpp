#include<iostream>
#include<map>
using namespace std;

class Tile {
	char tile[20][20];
public:
	Tile() {
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				if (y == 0 || y == 19) {
					tile[y][x] = '-';
				}
				else if (x == 0 || x == 19) {
					tile[y][x] = '|';
				}
				else {
					tile[y][x] = ' ';
				}
			}
		}
	}
	void ShowTile() {
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				cout << tile[y][x];
			}
			cout << "\n";
		}
	}
};

int main() {
	Tile t;
	t.ShowTile();
}