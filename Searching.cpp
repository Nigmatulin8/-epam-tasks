/* Напишите функцию, которая для отсортированного массива целых чисел определяет, содержится ли в нем заданное значение. */
#include <iostream>

int binarySearch(int mas[], int item, int l_border, int r_border);
void insertionSort(int data[], int length);

int main() {
	int arrLength = 0;
	int elemToSearch = 0;

	std::cout<<"Enter the array length: ";
	std::cin>>arrLength;

	std::cout<<"Enter the array elements: ";
	int *mas = new int[arrLength];
	for (auto i(0); i < arrLength; ++i) {
		std::cin>>mas[i];
	}

	insertionSort(mas, arrLength);
	std::cout<<"Sorted array: ";
	for(int i(0); i < arrLength; i++) {
		std::cout<<mas[i]<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"Enter the number you want to find: ";
	std::cin>>elemToSearch;

	std::cout<<"The item "<<elemToSearch<<" is in position - " <<binarySearch(mas, elemToSearch, 0, arrLength)<<std::endl;

	delete [] mas;
	system("pause");
	return 0;
}

int binarySearch(int mas[], int item, int l_border, int r_border) {
	int midElem = 0;
	while(true) {
		midElem = (l_border + r_border) / 2;

		if(l_border > r_border) return -1;

		if(item > mas[midElem]) {
			l_border = midElem + 1;
		}
		else if (item < mas[midElem]) {
			r_border = midElem - 1;
		}
		else {
			return midElem + 1;
		}
	}
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
