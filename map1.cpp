#include<iostream>
#include<map>
using namespace std;

class Armor {
	string name;
	int defense;
public:
	Armor() :name(""), defense(0) {}
	Armor(const string& n, int d) :name(n), defense(d) {}

	string GetName()const {
		return name;
	}
	int GetDefense()const {
		return defense;
	}
};

class Scene {
	string desc;
public:
	Scene() :desc("") {}
	Scene(const string& d) :desc(d) {}

	string GetDescription()const {
		return desc;
	}
};

class SceneManager {
	// ���� �̸��� Ű�� �ϰ� �� �����͸� ������ �����ϴ� map
	map<string, Scene*>scenes;
	Scene* currentScene;		// ���� ���� ����Ű�� ������
	string currentSceneName;	// ���� ���� �̸�
public:
	SceneManager() :currentScene(nullptr), currentSceneName("") {}
	~SceneManager() {
		// map������� ��� ���� ���鼭 ����
		for (auto& pair : scenes) {
			delete pair.second;
		}
	}

	// ���� �߰��ϴ� �Լ�
	void AddScene(const string& name, Scene* scene) {
		scenes[name] = scene;			// ���� �̸��� Ű������ �ϰ� �����͸� ������ ����
	}
	// ���� �����ϴ� �Լ�
	void RemoveScene(const string& name) {
		auto it = scenes.find(name);	// �� �̸����� map���� ã��
		// ���� �����ϸ�
		if (it != scenes.end()) {
			delete it->second;			// �������� �Ҵ�� �� ��ü ����
			scenes.erase(it);			// map���� ����
		}
	}
	// ���� ���� �����ϴ� �Լ�
	void SetCurrentScene(const string& name) {
		auto it = scenes.find(name);	// �� �̸��� map���� ã��
		if (it != scenes.end()) {
			currentScene = it->second;
			currentSceneName = name;
		}
		else {
			cout << "���� ã�� �� ����" << endl;
		}
	}
	// ����ϴ� �Լ�
	void ShowCurrentScene()const {
		if (currentSceneName.empty()) {
			cout << "�������� ����" << endl;
			return;
		}
		cout << "���� �� : " << currentSceneName << endl;
		cout << "�� ���� : " << currentScene->GetDescription() << endl;

		cout << "==================================================" << endl;

	}
};

int main() {
	// Ű�� ���ڿ�, ���� Armor ��ü
	/*
	map<string, Armor>armorMap;

	armorMap.insert(make_pair("helmet", Armor("ö����", 5)));
	armorMap.insert(make_pair("shield", Armor("��������", 1)));
	armorMap.insert(make_pair("greaves", Armor("�Ź�", 3)));
	armorMap.insert(make_pair("������", Armor("����", 35)));

	cout << "=== ��ü �� ��� ===" << endl;
	for (const auto& pair : armorMap) {
		cout << "Ű�� : " << pair.first << endl;
		cout << "�� �̸� : " << pair.second.GetName() << endl;
		cout << "���� : " << pair.second.GetDefense() << endl;
	}

	cout << "==================================================" << endl;

	string searchKey;
	cout << "�˻��� ���� Ű�� �Է� : ";
	cin >> searchKey;

	auto it = armorMap.find(searchKey);

	if (it != armorMap.end()) {
		cout << "--- ã�� �� ---" << endl;
		cout << "�̸� : " << it->second.GetName() << endl;
		cout << "���� : " << it->second.GetDefense() << endl;
	}
	else {
		cout << "���� ã�� �� ����" << endl;
	}
	*/

	SceneManager* sceneManager = new SceneManager();

	sceneManager->AddScene("MainMenu", new Scene("���θ޴� : ����, �ɼ�, ����"));
	sceneManager->AddScene("Level1", new Scene("���� 1 : ù��° ����"));

	sceneManager->SetCurrentScene("MainMenu");	// ���� �� ����
	sceneManager->ShowCurrentScene();

	sceneManager->SetCurrentScene("Level1");
	sceneManager->ShowCurrentScene();

	sceneManager->RemoveScene("MainMenu");

	sceneManager->SetCurrentScene("������");
	sceneManager->ShowCurrentScene();
}