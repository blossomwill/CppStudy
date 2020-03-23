// 입력을 받아 테두리로 묶인 인사말을 생성
#include <iostream>
#include <string>

// 표준 라이브러리에서 가져와서 사용할 이름을 언급
using std::cin; using std::endl;
using std::cout; using std::string;
int main()
{
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;

	// 출력하려는 메시지를 구성
	const std::string greeting = "Hello, " + name + "!";

	// 인사말과 한 쪽 테두리 사이의 공백 개수
	const int pad = 1;

	
	// 출력할 행의 전체 개수
	const int rows = pad * 2 + 3;
	const std::string::size_type cols = greeting.size() + (pad) * 2 + 2;
	// 입력과 출력을 구분
	std::cout << std::endl;
	const std::string space(greeting.size() + (pad) * 2, ' ');

	// 불변성: 지금까지 r개 행을 출력
	int r = 0;

	// r을 0으로 설정하면 불변성은 참
	for(r = 0 ; r != rows; ++r){
		// 이 지점에서 불변성은 참
		
		std::string::size_type c = 0;
		//불변성: 현재 행에서 c개 문자를 출력
		while (c != cols)
		{
			if (r == pad + 1 && c == pad + 1) {
				std::cout << greeting;
				c += greeting.size();
				
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
					std::cout << "*";
					++c;
				}
				else if (r == pad + 1) {
					std::cout << " ";
					++c;
				}
				else {
					std::cout << space;
					c += space.size();
				}
				
			}
		}
		std::cout << std::endl;
	}
	


	return 0;
}