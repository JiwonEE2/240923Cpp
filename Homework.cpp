/*
[ �� ���� ]
1. �� �Ŵ��� ����
2. �� �Ŵ����� ù��°, �ι�° �� ����
3. �� �Ŵ����� ���� �� ù��°�� ����
4. �÷��̾�(1,1)�� ����(9,1) ��ġ �ʱ�ȭ
5. �� �Ŵ����� �� ���
6. �÷��̾� == ���� ��ġ�� ������
	1) false
		(1) �Է��� ��ٸ���
		(2) Ű�� ���� �÷��̾� ��ġ�� ������Ʈ
		(3) �� �Ŵ����� �� ���(�����)

	2) true
		(1) ���� ���� �ι�°�� ���� �� �ι�° �� ���

1. �� �Ŵ���
	- �� Ŭ������ �޾� map ����
	- ����Լ�
		�� �� ���� �� �߰�
		�� ���� �� ����
		�� �� ���(�����)

2. ��
	- �������
		�� �� ȭ��
		�� �÷��̾� ��ġ
		�� ���� ��ġ
	- ����Լ�
		�� �� ���



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
	Player() :x(1), y(1) {}

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
	string name;
	char tile[20][20];
public:
	Scene(const string& n) :name(n) {}

	void SetDisplay(int px,int py) {
		if (name == "before deongeon") {
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
		else if (name == "deongeon") {
			for (int y = 0; y < 20; y++) {
				for (int x = 0; x < 20; x++) {
					if (x == px && y == py) {
						tile[y][x] = '0';
					}
					else if (y == 0 || y == 19) {
						tile[y][x] = '=';
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
	}

	void DisplayScene() {
		
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 20; x++) {
				cout << tile[y][x];
			}
			cout << "\n";
		}
	}
};

class SceneManager {
	map<string, Scene*>scenes;
	Scene* currentScene;
	string currentSceneName;
	int px=0, py=0;
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

	void SetPlayerXY(int x, int y) {
		px = x;
		py = y;
	}

	void ShowCurrentScene() {
		// ����ó�� : ���� ���� �������� �ʾ��� ���
		cout << "���� �� �̸� : " << currentSceneName << endl;
		cout << "���� �� ȭ�� : \n";
		currentScene->SetDisplay(px,py);
		currentScene->DisplayScene();
	}
};

int main() {
	SceneManager* sceneManager = new SceneManager();

	// �����Ͷ� ȭ��ǥ
	sceneManager->AddScene("before deongeon", new Scene("before deongeon"));
	sceneManager->AddScene("deongeon", new Scene("deongeon"));
	
	Player* p = new Player();

	int px = p->GetPlayerX();
	int py = p->GetPlayerY();

	int dx = 10, dy = 0;	// ���� ��ġ

	sceneManager->SetPlayerXY(px, py);

	sceneManager->SetCurrentScene("before deongeon");
	sceneManager->ShowCurrentScene();	

	while (px != dx || py != dy) {

		// Ű�� �޾ƿͼ� ������ ��������. �׳� ������ ������ �׷�?
		p->InputKey();
		px = p->GetPlayerX();
		py = p->GetPlayerY();
		sceneManager->SetPlayerXY(px, py);
	}	

	sceneManager->SetCurrentScene("deongeon");
	sceneManager->ShowCurrentScene();
}