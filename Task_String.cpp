/* Дана строка, вывести только те слова, которые встречаются в ней только один раз.  */
#include <iostream>
#include <string>

std::string trimStr(std::string str);
bool sym_check(char sym);
int length(std::string str);
std::string cutOutWord(std::string userStr, int index);

int main(){
	int index = 0, word_counter = 0, rhs_index = 0;
	std::string userStr, lhs = " ", rhs = " ";

	std::cout<<"Enter your string: ";
	std::getline(std::cin, userStr);
	userStr = trimStr(userStr);
	
	do { 
		lhs = cutOutWord(userStr, index);
		do {
			rhs = cutOutWord(userStr, rhs_index);
			rhs_index += length(rhs) + 1;

			if(lhs == rhs && lhs != "") { ++word_counter; }
			if(word_counter > 2) break;
		}	
		while(rhs != "");

		if(word_counter == 1) { std::cout << lhs << std::endl; }

		word_counter = 0; 
		rhs_index = 0;
		index += length(lhs) + 1;
	}		
	while(lhs != "");
		
	system("pause");
	return 0;
}

std::string trimStr(std::string str) {
	int index = 0;
	std::string output = "";
	while (str[index] == ' ') index++; //remove spaces from beginning 
	while(str[index]) {
		if((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A' && str[index] <= 'Z')
		|| (str[index] >= '1' && str[index] <= '9') || str[index] == ' ') {
			output += str[index];
		}
		++index;
	}
	return output;
}

bool sym_check(char sym) {
	if(sym == ' ' || sym == '.' || sym == ',' || sym == ':'
		|| sym == ';' || sym == '!' || sym == '?') return true;
	else return false; 
}

int length(std::string str) {
	int i = 0;
	while(str[i]) { ++i; }
	return i;
}

std::string cutOutWord(std::string userStr, int index){
	std::string singleWord = "";
	if(index > length(userStr)) return singleWord;
	
	while(userStr[index]) { 
		if (!sym_check(userStr[index])) {
			singleWord += userStr[index];
			index++;
		} 
		else break;
	}
	return singleWord;
}
