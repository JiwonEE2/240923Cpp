/*
[ 씬 응용 ]
1. 씬 매니저 생성
2. 씬 매니저로 씬 1, 2 생성
3. 씬 매니저로 현재 씬 1로 설정
4. 씬 매니저로 루프 실행 (플레이어 != 던전)
	1) 화면 세팅(플레이어 위치에 따라)
	2) 화면 출력
	3) 키 입력 대기
5. 현재 씬을 두번째로 변경 후 두번째 씬 출력

1. 씬 매니저
	- 멤버변수
		ㄴ 씬 클래스를 받아 map 생성
			ㄴ 현재 씬과 그 이름을 사용
	- 멤버함수
		ㄴ 씬 생성 및 추가
		ㄴ 현재 씬 설정
		ㄴ 루프 실행

2. 씬
	- 멤버변수
		ㄴ 씬 번호
		ㄴ 키 초기화
		ㄴ 씬 화면
		ㄴ 플레이어 위치
		ㄴ 던전 위치
	- 멤버함수
		ㄴ 플레이어 위치에 따른 화면 세팅
		ㄴ 키 받기
		ㄴ 키로 플레이어 위치 반환 및 조정
		ㄴ 씬 출력
		ㄴ 루프
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