// �Է��� �޾� �׵θ��� ���� �λ縻�� ����
#include <iostream>
#include <string>

int main()
{
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;

	// ����Ϸ��� �޽����� ����
	const std::string greeting = "Hello, " + name + "!";

	// �λ縻�� �� ��° ��� �� ��° ��
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";

	// �λ縻�� ù ��° ��� �ټ� ��° ��
	const std::string first(second.size(), '*');

	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	
	return 0;
}