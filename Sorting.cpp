/*
Дан массив целых чисел. Напишите функцию, которая получает данный массив в качестве аргумента и 
сортирует его по возрастанию, а также программу для демонстрации работы этой функции
*/
#include <iostream>

void insertionSort(int data[], int length);
int main(){
	int arrLength;

	std::cout<<"Enter the array length: ";
	std::cin>>arrLength;

	std::cout<<"Enter the array: ";
	int *mas = new int[arrLength];
	for (auto i(0); i < arrLength; ++i) {
		std::cin>>mas[i];
	}

	std::cout<<"\nEntered array (unsorted): ";
	for(auto i(0); i < arrLength; ++i) {
		std::cout<<mas[i]<<" ";
	}
	std::cout<<std::endl;

	insertionSort(mas, arrLength);

	std::cout<<"\nSorted array: ";
	for(auto i(0); i < arrLength; ++i) {
		std::cout<<mas[i]<<" ";
	}
	std::cout<<"\n"<<std::endl;

	delete [] mas;
	system("pause");
	return 0;
}

void insertionSort(int arr[], int length) {
	int key = 0;
	int temp = 0;
	for(int i(1); i < length; i++){
		key = arr[i];
		temp = i - 1;
		while(temp >= 0 && arr[temp] > key){
			arr[temp + 1] = arr[temp];
			temp = temp - 1;
			arr[temp + 1] = key;
		}
	}
}
