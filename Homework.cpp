/*
[ 키입력 방식 ]
1. cin -> 버퍼를 사용하기 때문에 엔터를 눌러야 하는 번거로움이 있다.

2. getch() -> 한번에 하나의 키만 받을 수 있으며 반응속도가 느리다.
	많이 활용하는 특수 버튼
	← 좌측 방향키 : 75
	→ 우측 방향키 : 77
	↑ 위 방향키 : 72
	↓ 아래 방향키 : 80
	Enter키 : 13

3. GetAsyncKeyState() -> 멀티 입력이 가능하다.

[ 화면 정지 ]
#include<Windows.h>	// Sleep()이 포함되어 있는 헤더
Sleep(300);			// 일시정지 window.h 헤더 필요
  o
 /|\
  |ㄴ
*/
#include<iostream>
using namespace std;

int main() {

}