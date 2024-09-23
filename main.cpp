/*
Map
- 연관 컨테이너 중 빈번하게 사용한다.
ㄴ key, value 쌍으로 저장(pair)
ㄴ key(고유함)는 컨테이너에 중복저장이 될 수 없다.
*/
#include<iostream>
#include<map>
using namespace std;
int main() {
	map<string, int>data;	// key : string, value : int

	// 반복자
	map<string, int>::iterator iter;

	// 1. value-type을 이용한 방법
	// 기본적인 키-값 쌍 타입을 나타낸다. 이 방법은 명시적으로 pair객체를 생성하여 insert에 전달
	// 가독성이 다소 떨어짐
	data.insert(map<string, int>::value_type("이지원", 1));

	// 2. make_pair : pair 객체를 생성하는 함수 템플릿
	// make_pair("월요일", 5)는 std::pair<string, int>타입의 객체를 생성
	// 간결한 방법
	// 템플릿 인자를 자동으로 추론하므로 타입이 명확하지 않을 수 있음
	// 복잡한 타입을 다룰 때는 명시적인 타입선언이 필요할 수 있다.
	data.insert(make_pair("월요일", 5));

	// 3. pair를 이용한 방법 : 키-값 쌍을 명시적으로 생성하여 삽입
	// 명확한 타입 선언을 통해 가독성을 높일 수 있음
	data.insert(pair<string, int>("화요일", 10));
	data.insert(pair<string, int>("수요일", 30));
	data.insert(pair<string, int>("목요일", 50));
	data.insert(pair<string, int>("금요일", 120));

	// 4. 객체를 직접 생성하는 방법
	// pair의 템플릿 인자는 map의 key와 value타입과 일치해야 한다.
	// 객체를 생성한 후 insert를 하기 때문에 필요에 따라 객체를 수정하거나 재사용할 수도 있다.
	pair<string, int>pt1("토요일", 300);
	data.insert(pt1);
	data.erase("토요일");

	for (auto& pair : data) {
		cout << "키값 : " << pair.first << ", 데이터 : " << pair.second << endl;
	}
	// map은 자기가 알아서 자동 정렬해준다.
	/*
	find : 주어진 키를 찾아 iterator를 반환. 키가 존재하지 않으면 end 반환
	clear : map의 모든 요소를 삭제
	at : 주어진 키에 해당하는 값을 리턴. 키가 존재하지 않으면 오류발생(out of range)
	*/

	// 1. 맵을 선언하자
	map<string, int>myMap;
	// 2. insert를 해서 데이터를 추가하자
	myMap.insert(make_pair("사과", 1));
	myMap.insert(make_pair("바나나", 2));
	myMap.insert(make_pair("파인애플", 3));
	myMap.insert(make_pair("포도", 4));

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << "키 : " << it->first << ", 값 : " << it->second << endl;
	}

	// 역순
	for (auto it = myMap.rbegin(); it != myMap.rend(); ++it) {
		cout << "키 : " << it->first << ", 값 : " << it->second << endl;
	}
}