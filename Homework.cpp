/*
[ Ű�Է� ��� ]
1. cin -> ���۸� ����ϱ� ������ ���͸� ������ �ϴ� ���ŷο��� �ִ�.

2. getch() -> �ѹ��� �ϳ��� Ű�� ���� �� ������ �����ӵ��� ������.
	���� Ȱ���ϴ� Ư�� ��ư
	�� ���� ����Ű : 75
	�� ���� ����Ű : 77
	�� �� ����Ű : 72
	�� �Ʒ� ����Ű : 80
	EnterŰ : 13

3. GetAsyncKeyState() -> ��Ƽ �Է��� �����ϴ�.

[ ȭ�� ���� ]
#include<Windows.h>	// Sleep()�� ���ԵǾ� �ִ� ���
Sleep(300);			// �Ͻ����� window.h ��� �ʿ�
  o
 /|\
  |��
*/
#include<iostream>
#include<map>
#include<conio.h>
using namespace std;

enum class STATE {
	IDLE, UP, LEFT, RIGHT, DOWN
};

class Tile {
	// ���� 2���� �迭�� ����
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
		case 72:			// ��
			state = STATE::UP;
			y++;
			cout << x << ", " << y;
			cout << "\t��\n";
			break;
		case 75:			// ��
			state = STATE::LEFT;
			x--;
			cout << x << ", " << y;
			cout << "\t��\n";
			break;
		case 77:			// ��
			state = STATE::RIGHT;
			x++;
			cout << x << ", " << y;
			cout << "\t��\n";
			break;
		case 80:			// ��
			state = STATE::DOWN;
			y--;
			cout << x << ", " << y;
			cout << "\t��\n";
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


// �� �̸��� Ű�� �� ��ü�� ����� map�� �����Ͽ���.
// �� ��ü������ �̸��� ���� ���� �ִ�.
// �� ��ü���� �̸��� �������� ���� ������ ���� �� ����.
// ���� �˰� ������..
// ������ �˾ƺ���
class Scene {
	string desc;
	string display;
	string name;
	Tile* t;
public:
	Scene() :desc("(�� ����)"), display("(�� ȭ��)") {}
	Scene(const string& desc, const string& dis) :desc(desc), display(dis) {}
	Scene(const string& n) :name(n) {}

	string GetDescription()const {
		return desc;
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
	// �⺻�����ڿ��� ���� �� ��ü�� ����ְ�, �̸��� string���� ������ �ִ�. ������?
	SceneManager() :currentScene(nullptr), currentSceneName("") {}
	// �Ҹ��ڿ� �� ���� �Լ��� ����?
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
			currentScene = it->second;	// �� ��ü
			currentSceneName = name;	// �� �̸�
		}
		// ����ó�� : ���� ���� ���
	}

	void ShowCurrentScene()const {
		// ����ó�� : ���� ���� �������� �ʾ��� ���
		cout << "���� �� �̸� : " << currentSceneName << endl;
		cout << "���� �� ���� : " << currentScene->GetDescription() << endl;
		cout << "���� �� ȭ�� : \n";
		currentScene->DisplayScene();
	}
};

int main() {
	SceneManager* sceneManager = new SceneManager();

	// �����Ͷ� ȭ��ǥ
	sceneManager->AddScene("before deongeon", new Scene("before deongeon"));
	// sceneManager->AddScene("before deongeon", new Scene("���� ���� �� ��ֹ��� �ִ� ��", "--"));
	sceneManager->AddScene("deongeon", new Scene("����","00"));

	sceneManager->SetCurrentScene("before deongeon");
	sceneManager->ShowCurrentScene();

	Player* p = new Player();

	int px = 0, py = 0;
	int dx = 10, dy = 0;	// ���� ��ġ

	while (px != dx || py != dy) {
		p->InputKey();
		px = p->GetPlayerX();
		py = p->GetPlayerY();
	}

	sceneManager->SetCurrentScene("deongeon");
	sceneManager->ShowCurrentScene();
}