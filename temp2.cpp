/*
[ 씬 응용 ]
1. 씬 매니저 생성
2. 씬 매니저로 첫번째, 두번째 씬 생성
3. 씬 매니저로 현재 씬 첫번째로 설정
4. 플레이어(1,1)와 던전(9,1) 위치 초기화
5. 씬 매니저로 씬 출력
6. 플레이어 == 던전 위치일 때까지
	1) false
		(1) 입력을 기다린다
		(2) 키에 따라 플레이어 위치를 업데이트
		(3) 씬 매니저로 씬 출력(지우고)

	2) true
		(1) 현재 씬을 두번째로 변경 후 두번째 씬 출력

1. 씬 매니저
	- 멤버변수
		ㄴ 씬 클래스를 받아 map 생성
			ㄴ 현재 씬과 그 이름을 사용
	- 멤버함수
		ㄴ 씬 생성 및 추가
		ㄴ 현재 씬 설정
		ㄴ 씬 출력(지우고)

2. 씬
	- 멤버변수
		ㄴ 씬 화면
		ㄴ 플레이어 위치
		ㄴ 던전 위치
	- 멤버함수
		ㄴ 씬 출력
*/
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