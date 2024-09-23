#include<iostream>
using namespace std;

enum class STATE {
	ATTACK,
	RUN,
	JUMP
};

/*
void RunState() {
	// �޸��� ���� �� ���𰡸� ó��
	cout << "�޸��� �ִ�" << endl;
}

void JumpState() {
	cout << "������" << endl;

}

void AttackState() {
	cout << "������" << endl;

}
*/

// Ŭ������ ����ٸ�
class IState {
public:
	virtual void EnterState() = 0;
	virtual void InputEvent() = 0;
	virtual void Update() = 0;
	virtual void ExitState() = 0;
};

class JumpState :public IState {
public:
	void EnterState()override {
		cout << "���� ���·� ����" << endl;
	}
	void InputEvent()override {
		cout << "���� �߿� Ű �Է��� �޴´�" << endl;
	}
	void Update()override {
		cout << "���� �߿� ��ġ ����" << endl;
	}
	void ExitState()override {
		cout << "���� ��" << endl;
	}
};

class RunState :public IState {
public:
	void EnterState()override {
		cout << "�޸��� ���·� ����" << endl;
	}
	void InputEvent()override {
		cout << "�޸��� �߿� Ű �Է��� �޴´�" << endl;
	}
	void Update()override {
		cout << "�޸��� ��. �޸��� �ӵ��� ������Ʈ" << endl;
	}
	void ExitState()override {
		cout << "�޸��� ��" << endl;
	}
};

class Character {
	IState* curState;
public:
	Character() {
		curState = new RunState();
	}
	void SetCurState(IState* s) {
		// ���� ���� ����
		curState->ExitState();

		// ���� �����ϰ�
		curState = s;

		// ����
		curState->EnterState();
	}
	void InputEvent() {
		curState->InputEvent();
	}
	void Update() {
		curState->Update();
	}
};

int main() {
	/*
	STATE state = STATE::ATTACK;

	switch (state)
	{
	case STATE::ATTACK:
		AttackState();
		break;
	case STATE::RUN:
		RunState();
		break;
	case STATE::JUMP:
		JumpState();
		break;
	default:
		break;
	}
	*/
	Character c;

	c.InputEvent();
	c.Update();
	c.SetCurState(new JumpState());
	
	c.InputEvent();
	c.Update();
}