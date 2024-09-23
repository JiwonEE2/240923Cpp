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
  o
 /|\
  |ㄴ
*/
#include<iostream>
#include<map>
#include<conio.h>
using namespace std;

// 씬 이름을 키로 씬 객체를 밸류로 map을 생성하였다.
// 씬 객체에서는 이름은 없고 설명만 있다.
// 씬 객체에서 이름을 설정하지 않은 이유가 있을 것 같다.
// 뭔가 알것 같은데..
// 다음에 알아보자
class Scene {
	int sceneNum;			// 씬 번호
	char key = 0;			// 키 초기화
	char tile[20][20];		// 씬 화면
	int px = 1, py = 1;		// 플레이어 위치
	int dx = 9, dy = 1;		// 던전 위치
public:
	Scene() :sceneNum(1) {}
	Scene(int num) :sceneNum(num) {}

	// 키 받기
	void InputKey() {
		key = _getch();
		switch (key) {
		case 72:			// 상
			// 키 조정
			if (tile[py - 1][px] == ' ') {
				py--;
			}
			break;
		case 75:			// 좌
			if (tile[py][px-1] == ' ') {
				px--;
			}
			break;
		case 77:			// 우
			if (tile[py][px + 1] == ' ') {
				px++;
			}
			break;
		case 80:			// 하
			if (tile[py + 1][px] == ' ') {
				py++;
			}
			break;
		}
		key = 0;
	}

	// 플레이어 위치에 따른 화면 세팅
	void SetDisplay() {
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				if (x == px && y == py) {
					tile[y][x] = '0';
				}
				else if (y == 0 || y == 19) {
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

	// 씬 출력
	void DisplayScene() {
		if (sceneNum == 1) {
			for (int y = 0; y < 20; y++) {
				for (int x = 0; x < 20; x++) {
					cout << tile[y][x];
				}
				cout << "\n";
			}
		}
		else {
			for (int y = 0; y < 20; y++) {
				for (int x = 0; x < 20; x++) {
					cout << "탈출~";
				}
				cout << "\n";
			}
		}
	}

	void Loop() {
		while (px != dx || py != dy) {
			SetDisplay();
			//system("cls");
			DisplayScene();
			InputKey();
		}
	}
};

class SceneManager {
	map<string, Scene*>scenes;
	Scene* currentScene;
	string currentSceneName;
public:
	// 기본생성자에서 현재 씬 객체는 비어있고, 이름은 string으로 정해져 있다. 이유는?
	SceneManager() :currentScene(nullptr), currentSceneName("") {}
	// 소멸자와 씬 삭제 함수의 차이?
	/*~SceneManager() {
		for (auto& pair : scenes) {
			delete pair.second;
		}
	}*/

	void AddScene(const string& name, Scene* scene) {
		scenes[name] = scene;
	}

	void SetCurrentScene(const string& name) {
		auto it = scenes.find(name);
		if (it != scenes.end()) {
			currentScene = it->second;	// 씬 객체
			currentSceneName = name;	// 씬 이름
		}
		// 예외처리 : 씬이 없을 경우
	}

	void StartLoop() {
		currentScene->Loop();
	}

	void ShowDisplay() {
		currentScene->DisplayScene();
	}
};

int main() {
	// 1. 씬 매니저 생성
	SceneManager* sceneManager = new SceneManager();

	// 2. 씬 매니저로 씬 1,2 생성
	// 포인터라서 화살표
	sceneManager->AddScene("before deongeon", new Scene(1));
	sceneManager->AddScene("deongeon", new Scene(2));

	// 3. 씬 매니저로 현재 씬 1로 설정
	sceneManager->SetCurrentScene("before deongeon");

	// 4. 씬 매니저로 루프 실행
	sceneManager->StartLoop();

	// 5. 씬 매니저로 현재 씬 2로 설정
	sceneManager->SetCurrentScene("deongeon");
	sceneManager->ShowDisplay();
}