/*
[ �� ���� ]
1. �� �Ŵ��� ����
2. �� �Ŵ����� �� 1, 2 ����
3. �� �Ŵ����� ���� �� 1�� ����
4. �� �Ŵ����� ���� ���� (�÷��̾� != ����)
	1) ȭ�� ����(�÷��̾� ��ġ�� ����)
	2) ȭ�� ���
	3) Ű �Է� ���
5. ���� ���� �ι�°�� ���� �� �ι�° �� ���

1. �� �Ŵ���
	- �������
		�� �� Ŭ������ �޾� map ����
			�� ���� ���� �� �̸��� ���
	- ����Լ�
		�� �� ���� �� �߰�
		�� ���� �� ����
		�� ���� ����

2. ��
	- �������
		�� �� ��ȣ
		�� Ű �ʱ�ȭ
		�� �� ȭ��
		�� �÷��̾� ��ġ
		�� ���� ��ġ
	- ����Լ�
		�� �÷��̾� ��ġ�� ���� ȭ�� ����
		�� Ű �ޱ�
		�� Ű�� �÷��̾� ��ġ ��ȯ �� ����
		�� �� ���
		�� ����

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

// �� �̸��� Ű�� �� ��ü�� ����� map�� �����Ͽ���.
// �� ��ü������ �̸��� ���� ���� �ִ�.
// �� ��ü���� �̸��� �������� ���� ������ ���� �� ����.
// ���� �˰� ������..
// ������ �˾ƺ���
class Scene {
	int sceneNum;			// �� ��ȣ
	char key = 0;			// Ű �ʱ�ȭ
	char tile[20][20];		// �� ȭ��
	int px = 1, py = 1;		// �÷��̾� ��ġ
	int dx = 9, dy = 1;		// ���� ��ġ
public:
	Scene() :sceneNum(1) {}
	Scene(int num) :sceneNum(num) {}

	// Ű �ޱ�
	void InputKey() {
		key = _getch();
		switch (key) {
		case 72:			// ��
			// Ű ����
			if (tile[py - 1][px] == ' ') {
				py--;
			}
			break;
		case 75:			// ��
			if (tile[py][px-1] == ' ') {
				px--;
			}
			break;
		case 77:			// ��
			if (tile[py][px + 1] == ' ') {
				px++;
			}
			break;
		case 80:			// ��
			if (tile[py + 1][px] == ' ') {
				py++;
			}
			break;
		}
		key = 0;
	}

	// �÷��̾� ��ġ�� ���� ȭ�� ����
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

	// �� ���
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
					cout << "Ż��~";
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

	void StartLoop() {
		currentScene->Loop();
	}

	void ShowDisplay() {
		currentScene->DisplayScene();
	}
};

int main() {
	// 1. �� �Ŵ��� ����
	SceneManager* sceneManager = new SceneManager();

	// 2. �� �Ŵ����� �� 1,2 ����
	// �����Ͷ� ȭ��ǥ
	sceneManager->AddScene("before deongeon", new Scene(1));
	sceneManager->AddScene("deongeon", new Scene(2));

	// 3. �� �Ŵ����� ���� �� 1�� ����
	sceneManager->SetCurrentScene("before deongeon");

	// 4. �� �Ŵ����� ���� ����
	sceneManager->StartLoop();

	// 5. �� �Ŵ����� ���� �� 2�� ����
	sceneManager->SetCurrentScene("deongeon");
	sceneManager->ShowDisplay();
}