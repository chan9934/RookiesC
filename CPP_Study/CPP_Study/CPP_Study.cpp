#include <iostream>

using namespace std;

// bool은 그냥 정수지만, 참/거짓을 나타내기 위해 사용한다 했었다.
// 사실 char도 마찬가지. 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다. 

// ASCII (American Standard Code for Information Interchange)

// '문자'의 의미로 작은 따옴포 ''사용
// char는 그냥 1byte 정수 Type 하지만 컴파일러에서 그 정수를 아스키코드와 매핑 시킨다.

char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1; // 정수를 담는거니 당연히 더하기도 가능


// 국제화 시대에는 영어만으로 서비스 할 수 없다.
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드 (unicode)

// 유니코드는 표기 방식이 여러가지가 있는데 대표적으로 UTF-8 UTF-16이다.
// UTF-8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트

// UTF-16 (마이크로소프트)
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분의 문자 2바이트
// - 매--우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = L'안'; //유니코드 중 UTF-16을 사용하는 타입 유니코드를 사용한다는 표시로 L을 붙여줘야한다.

// Escape Sequence
// 표기하기 애매한 애들을 표현
// \0 = 아스키코드0 = NULL
// \t = 아스키코드9 = Tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드13 = CarriageReturn (커서 <<)
// \'

// 문자열
// 문자들이 열을 지어서 모여 있는 것 (일종의 문자 배열)
// 정수 (1~8바이트) 고정 길이로
// 끝은 NULL (\0) C에서는 문자열마다 붙여줬어야 했나? C++은 컴파일러가 해주는듯

char str[] = { 'H', 'e', 'l', 'l', 'o' }; // 데이터 영역은 다 0으로 초기화 되었기에 아무 문제 없지만
char str3[] = "Hello World";


int main()
{
	wcout.imbue(locale("kor"));
	wcout << wch << endl;
	// cout은 char 전용이라 wcout를 해줘야 하고 한글 출력을 위해 따로 추가 처리가 필요하다.

	char str2[] = { 'H', 'e', 'l', 'l', 'o', '\0'}; // Stack 영역에선 초기화 되지 않은 곳에서 쓰레기 값이 남아 있어 문제가 생긴다
	cout << str << endl;
	cout << str2 << endl;
}
