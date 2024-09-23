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
*/

#include<iostream>
#include<conio.h>	// _getch�� ���ԵǾ� �ִ� ���
using namespace std;

class Scene {
	string stemp;
public:
	string StartScene() {
		int cursorLocation = 0;
		int choice = -1;

		// ���� ���Ḧ ������ ������
		while (choice != 2) {
			if (cursorLocation < 0) {
				cursorLocation = 0;
			}
			else if (cursorLocation > 2) {
				cursorLocation = 2;
			}

			switch (cursorLocation) {
			case 0:
				system("cls");	// ȭ�� �����
				cout << "Welcome to Dori's RPG\n";
				cout << "�� �� ����\n   ����� ����\n   ���� ����\n";
				break;
			case 1:
				system("cls");
				cout << "Welcome to Dori's RPG\n";
				cout << "   �� ����\n�� ����� ����\n   ���� ����\n";
				break;
			case 2:
				system("cls");
				cout << "Welcome to Dori's RPG\n";
				cout << "   �� ����\n   ����� ����\n�� ���� ����\n";
				break;
			}

			char key = _getch();		// Ű �޴� �Լ�
			switch (key) {
			case 13:			// enter
				system("cls");
				choice = cursorLocation;
				break;
			case 72:			// ����
				system("cls");
				cursorLocation--;
				break;
			case 80:			// �Ʒ���
				system("cls");
				cursorLocation++;
				break;
			}

			switch (choice) {
			case 0:
				// �� ���� ���� ȭ������
				system("cls");
				return NameSelectScene();
				// choice = -1;
				break;
			case 1:
				// ���� �ε� ȭ������
				system("cls");
				break;
			}
		}
	}

	string NameSelectScene() {
		cout << "�̸��� �Է��ϼ��� : ";
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