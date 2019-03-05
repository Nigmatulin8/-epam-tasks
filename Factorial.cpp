#include <iostream>

int main() {
	int factNumb = 0;
	long double result = 1;
	std::cout<<"Enter the number: ";
	std::cin>>factNumb;

	for(int i(1); i <= factNumb; i++) {
		result *= i;
	}

	std::cout<<result<<std::endl;
	system("pause");
	return 0;
}