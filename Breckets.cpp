/* Дана строка состоящая из скобок “{},(),[]”, определить является ли данная строка правильно скобочной последовательность.  
Например (()) – псп, а ((() нет. */
#include <iostream>

int main() {
	char str[100];
	bool flag = true;

	std::cout<<"Enter the breckets: ";
	std::cin>>str;

	for(int i(0); i < strlen(str) / 2; i++) {
		std::cout<<str[i]<<" to " <<str[strlen(str) - i - 1]<<std::endl;
		if(str[i] == 40 && str[strlen(str) - i - 1] == 41
			|| str[i] == 91 && str[strlen(str) - i - 1] == 93
			|| str[i] == 123 && str[strlen(str) - i - 1] == 125) {

			flag = true;
		}
		else {
			flag = false;
			break;
		}
	}
	if(flag) {
		std::cout<<"All is correct."<<std::endl;
	}
	else {
		std::cout<<"All is not correct."<<std::endl;
	}
	system("pause");
	return 0;
}
