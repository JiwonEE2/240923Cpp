/*
Map
- ���� �����̳� �� ����ϰ� ����Ѵ�.
�� key, value ������ ����(pair)
�� key(������)�� �����̳ʿ� �ߺ������� �� �� ����.
*/
#include<iostream>
#include<map>
using namespace std;
int main() {
	map<string, int>data;	// key : string, value : int

	// �ݺ���
	map<string, int>::iterator iter;

	// 1. value-type�� �̿��� ���
	// �⺻���� Ű-�� �� Ÿ���� ��Ÿ����. �� ����� ��������� pair��ü�� �����Ͽ� insert�� ����
	// �������� �ټ� ������
	data.insert(map<string, int>::value_type("������", 1));

	// 2. make_pair : pair ��ü�� �����ϴ� �Լ� ���ø�
	// make_pair("������", 5)�� std::pair<string, int>Ÿ���� ��ü�� ����
	// ������ ���
	// ���ø� ���ڸ� �ڵ����� �߷��ϹǷ� Ÿ���� ��Ȯ���� ���� �� ����
	// ������ Ÿ���� �ٷ� ���� ������� Ÿ�Լ����� �ʿ��� �� �ִ�.
	data.insert(make_pair("������", 5));

	// 3. pair�� �̿��� ��� : Ű-�� ���� ��������� �����Ͽ� ����
	// ��Ȯ�� Ÿ�� ������ ���� �������� ���� �� ����
	data.insert(pair<string, int>("ȭ����", 10));
	data.insert(pair<string, int>("������", 30));
	data.insert(pair<string, int>("�����", 50));
	data.insert(pair<string, int>("�ݿ���", 120));

	// 4. ��ü�� ���� �����ϴ� ���
	// pair�� ���ø� ���ڴ� map�� key�� valueŸ�԰� ��ġ�ؾ� �Ѵ�.
	// ��ü�� ������ �� insert�� �ϱ� ������ �ʿ信 ���� ��ü�� �����ϰų� ������ ���� �ִ�.
	pair<string, int>pt1("�����", 300);
	data.insert(pt1);
	data.erase("�����");

	for (auto& pair : data) {
		cout << "Ű�� : " << pair.first << ", ������ : " << pair.second << endl;
	}
	// map�� �ڱⰡ �˾Ƽ� �ڵ� �������ش�.
	/*
	find : �־��� Ű�� ã�� iterator�� ��ȯ. Ű�� �������� ������ end ��ȯ
	clear : map�� ��� ��Ҹ� ����
	at : �־��� Ű�� �ش��ϴ� ���� ����. Ű�� �������� ������ �����߻�(out of range)
	*/

	// 1. ���� ��������
	map<string, int>myMap;
	// 2. insert�� �ؼ� �����͸� �߰�����
	myMap.insert(make_pair("���", 1));
	myMap.insert(make_pair("�ٳ���", 2));
	myMap.insert(make_pair("���ξ���", 3));
	myMap.insert(make_pair("����", 4));

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << "Ű : " << it->first << ", �� : " << it->second << endl;
	}

	// ����
	for (auto it = myMap.rbegin(); it != myMap.rend(); ++it) {
		cout << "Ű : " << it->first << ", �� : " << it->second << endl;
	}
}