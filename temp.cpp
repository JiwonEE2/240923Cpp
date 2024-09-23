/*
[ 키입력 방식 ]
1. cin -> 버퍼를 사용하기 때문에 엔터를 눌러야 하는 번거로움이 있다.

2. getch() -> 한번에 하나의 키만 받을 수 있으며 반응속도가 느리다.
	많이 활용하는 특수 버튼
	← 좌측 방향키 : 75
	→ 우측 방향키 : 77
	↑ 위 방향키 : 72
	↓ 아래 방향키 : 80
	Enter키 : 13

3. GetAsyncKeyState() -> 멀티 입력이 가능하다.

[ 화면 정지 ]
#include<Windows.h>	// Sleep()이 포함되어 있는 헤더
Sleep(300);			// 일시정지 window.h 헤더 필요
*/

#include<iostream>
#include<conio.h>	// _getch가 포함되어 있는 헤더
using namespace std;

class Scene {
	string stemp;
public:
	string StartScene() {
		int cursorLocation = 0;
		int choice = -1;

		// 게임 종료를 선택할 때까지
		while (choice != 2) {
			if (cursorLocation < 0) {
				cursorLocation = 0;
			}
			else if (cursorLocation > 2) {
				cursorLocation = 2;
			}

			switch (cursorLocation) {
			case 0:
				system("cls");	// 화면 지우기
				cout << "Welcome to Dori's RPG\n";
				cout << "▶ 새 게임\n   저장된 게임\n   게임 종료\n";
				break;
			case 1:
				system("cls");
				cout << "Welcome to Dori's RPG\n";
				cout << "   새 게임\n▶ 저장된 게임\n   게임 종료\n";
				break;
			case 2:
				system("cls");
				cout << "Welcome to Dori's RPG\n";
				cout << "   새 게임\n   저장된 게임\n▶ 게임 종료\n";
				break;
			}

			char key = _getch();		// 키 받는 함수
			switch (key) {
			case 13:			// enter
				system("cls");
				choice = cursorLocation;
				break;
			case 72:			// 위로
				system("cls");
				cursorLocation--;
				break;
			case 80:			// 아래로
				system("cls");
				cursorLocation++;
				break;
			}

			switch (choice) {
			case 0:
				// 새 게임 생성 화면으로
				system("cls");
				return NameSelectScene();
				// choice = -1;
				break;
			case 1:
				// 게임 로드 화면으로
				system("cls");
				break;
			}
		}
	}

	string NameSelectScene() {
		cout << "이름을 입력하세요 : ";
		cin >> stemp;
		return stemp;
	}
};

class Player {
	string playerName;
public:
	string GetPlayerName() {
		return playerName;
	}
	void SetPlayerName(string pn) {
		playerName = pn;
	}
};

class Game {
	Scene scene;
	Player player;
	string stemp;

public:
	Game() {
		player.SetPlayerName(scene.StartScene());
	}
};

int main() {
	Game g;
}