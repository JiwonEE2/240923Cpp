#include<iostream>
#include<map>
#include<conio.h>
using namespace std;

enum class STATE {
	IDLE, UP, LEFT, RIGHT, DOWN
};

class Tile {
	// 쉽게 2차원 배열로 하자
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
	void DisplayTile() {
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				cout << tile[y][x];
			}
			cout << "\n";
		}
	}
};

class Player {
	STATE state;
	int x, y;
	char key;
public:
	Player() {
		x = 0;
		y = 0;
	}
	void InputKey() {
		key = _getch();
		switch (key) {
		case 72:			// 상
			state = STATE::UP;
			y++;
			cout << x << ", " << y;
			cout << "\t상\n";
			break;
		case 75:			// 좌
			state = STATE::LEFT;
			x--;
			cout << x << ", " << y;
			cout << "\t좌\n";
			break;
		case 77:			// 우
			state = STATE::RIGHT;
			x++;
			cout << x << ", " << y;
			cout << "\t우\n";
			break;
		case 80:			// 하
			state = STATE::DOWN;
			y--;
			cout << x << ", " << y;
			cout << "\t하\n";
			break;
		}
	}
	int GetPlayerX() {
		return x;
	}
	int GetPlayerY() {
		return y;
	}
};


// 씬 이름을 키로 씬 객체를 밸류로 map을 생성하였다.
// 씬 객체에서는 이름은 없고 설명만 있다.
// 씬 객체에서 이름을 설정하지 않은 이유가 있을 것 같다.
// 뭔가 알것 같은데..
// 다음에 알아보자
class Scene {
	string name;
	Tile* t;
public:
	Scene() :name("(씬 이름)") {}
	Scene(const string& n) :name(n) {
		t;
	}

	void DisplayScene()const {
		if (name == "before deongeon") {
			t->DisplayTile();
		}
		else if (name == "deongeon") {

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

	void ShowCurrentScene()const {
		// 예외처리 : 현재 씬이 설정되지 않았을 경우
		cout << "현재 씬 이름 : " << currentSceneName << endl;
		cout << "현재 씬 화면 : \n";
		currentScene->DisplayScene();
	}
};

int main() {
	SceneManager* sceneManager = new SceneManager();

	// 포인터라서 화살표
	sceneManager->AddScene("before deongeon", new Scene("before deongeon"));
	sceneManager->AddScene("deongeon", new Scene("deongeon"));

	sceneManager->SetCurrentScene("before deongeon");
	sceneManager->ShowCurrentScene();

	Player* p = new Player();

	int px = 0, py = 0;
	int dx = 10, dy = 0;	// 던전 위치

	while (px != dx || py != dy) {
		p->InputKey();
		px = p->GetPlayerX();
		py = p->GetPlayerY();
	}

	sceneManager->SetCurrentScene("deongeon");
	sceneManager->ShowCurrentScene();
}