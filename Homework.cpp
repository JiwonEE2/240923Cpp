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
};


// �� �̸��� Ű�� �� ��ü�� ����� map�� �����Ͽ���.
// �� ��ü������ �̸��� ���� ���� �ִ�.
// �� ��ü���� �̸��� �������� ���� ������ ���� �� ����.
// ���� �˰� ������..
// ������ �˾ƺ���
class Scene {
	string desc;
public:
	Scene() :desc("(�� ����)") {}
	Scene(const string& d) :desc(d) {}

	string GetDescription()const {
		return desc;
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
	}
};

int main() {
	SceneManager* sceneManager = new SceneManager();

	// �����Ͷ� ȭ��ǥ
	sceneManager->AddScene("before deongeon", new Scene("���� ���� �� ��ֹ��� �ִ� ��"));
	sceneManager->AddScene("deongeon", new Scene("����"));

	sceneManager->SetCurrentScene("before deongeon");
	sceneManager->ShowCurrentScene();

	Player* p = new Player();
	while (true) {
		p->InputKey();
	}
}