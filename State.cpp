#include<iostream>
using namespace std;

enum class STATE {
	ATTACK,
	RUN,
	JUMP
};

/*
void RunState() {
	// 달리고 있을 때 무언가를 처리
	cout << "달리고 있다" << endl;
}

void JumpState() {
	cout << "점프중" << endl;

}

void AttackState() {
	cout << "공격중" << endl;

}
*/

// 클래스로 만든다면
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
		cout << "점프 상태로 진입" << endl;
	}
	void InputEvent()override {
		cout << "점프 중에 키 입력을 받는다" << endl;
	}
	void Update()override {
		cout << "점프 중에 위치 변경" << endl;
	}
	void ExitState()override {
		cout << "점프 끝" << endl;
	}
};

class RunState :public IState {
public:
	void EnterState()override {
		cout << "달리는 상태로 진입" << endl;
	}
	void InputEvent()override {
		cout << "달리는 중에 키 입력을 받는다" << endl;
	}
	void Update()override {
		cout << "달리는 중. 달리는 속도를 업데이트" << endl;
	}
	void ExitState()override {
		cout << "달리기 끝" << endl;
	}
};

class Character {
	IState* curState;
public:
	Character() {
		curState = new RunState();
	}
	void SetCurState(IState* s) {
		// 이전 상태 종료
		curState->ExitState();

		// 상태 변경하고
		curState = s;

		// 진입
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