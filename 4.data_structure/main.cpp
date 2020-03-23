#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector; using std::sort;
using std::domain_error; using std::istream;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// vector<double>의 중앙값을 구함
// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");	// domain_error 객체 발생
		
	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;
	double median;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size == 0)
		throw domain_error("student has done no homework");

	return grade(midterm, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		// 이전 내용을 제거
		hw.clear();

		// 과제 점수를 읽음
		double x;

		while (cin >> x)
			hw.push_back(x);

		// 다음 학생의 점수 입력 작업을 고려해 스트림을 지움.
		in.clear();
	}
	return in;
} 

int main()
{
	cout << "please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "please enther your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";
	vector<double> homework;

	read_hw(cin, homework);

	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You must enter your grades"
			"Please try again" << endl;
		return 1;
	}
	return 0;
}