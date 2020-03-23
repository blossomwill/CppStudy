// �Է��� �޾� �׵θ��� ���� �λ縻�� ����
#include <iostream>
#include <string>

// ǥ�� ���̺귯������ �����ͼ� ����� �̸��� ���
using std::cin; using std::endl;
using std::cout; using std::string;
int main()
{
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;

	// ����Ϸ��� �޽����� ����
	const std::string greeting = "Hello, " + name + "!";

	// �λ縻�� �� �� �׵θ� ������ ���� ����
	const int pad = 1;

	
	// ����� ���� ��ü ����
	const int rows = pad * 2 + 3;
	const std::string::size_type cols = greeting.size() + (pad) * 2 + 2;
	// �Է°� ����� ����
	std::cout << std::endl;
	const std::string space(greeting.size() + (pad) * 2, ' ');

	// �Һ���: ���ݱ��� r�� ���� ���
	int r = 0;

	// r�� 0���� �����ϸ� �Һ����� ��
	for(r = 0 ; r != rows; ++r){
		// �� �������� �Һ����� ��
		
		std::string::size_type c = 0;
		//�Һ���: ���� �࿡�� c�� ���ڸ� ���
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