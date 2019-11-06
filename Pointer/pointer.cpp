#include"pointer.h"
void sort_(int *a, int n){
	int i, j;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++)
		if (a[j] > a[j + 1])
		{
			int tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	}
}
void inputArray(int* &a, int &n){
	a = new int[n];
	for (int i = 0; i < n; i++){
		printf("arr[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
}

void dellocateArray(int *&a){
	delete[] a;
}

void printArray(int* a, int n){
	for (int i = 0; i < n; i++)
		cout << *(a+i)<< " ";
	cout << endl;
}
int findMin(int* a, int n){
	int min = a[0];
	for (int i = 0; i < n; i++){
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int findMaxModulus(int* a, int n){
	int max = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
bool isAscending(int* a, int n){
	for (int i = 0; i<n - 1; i++) {
		if (a[i+1]>a[i])
			continue;
		else
			return false;
	}
	return true;
}

int sumofArray(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
int isPrime(int x){
	if (x == 1) return 0;
	bool isPrime = true;
	for (int i = 2; i <= x / 2; ++i)
	{
		if (x % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime)
		return 1;
	else
		return 0;
	return 0;
}
int countPrime(int* a, int n)
{
	int count = 0;

	for (int i = 0; i < n; i++){
		if (isPrime(a[i]))
			count++;
	}

	return count;
}
void reverseArray(int* &a, int n){
	int i = 0, j = n - 1;
	while (i < j){
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++;
		j--;
	}
}

int LinearSearch(int* a, int n, int key){
	for (int i = 0; i < n; i++){
		if (a[i] == key) return i;
	}
	return -1;
}

int sentinelLinearSearch(int* a, int n, int key){
	int last_value, i;

	if (--n < 1)
		return -1;

	last_value = a[n];

	a[n] = key;

	i = 0;
	while (a[i] != key)
		++i;

	a[n] = last_value;

	return (a[i] == key) ? i : -1;
}

int BinarySearch(int* a, int n, int key){
	int l1, i, j, flag = 0;
	l1 = 0;
	i = n - 1;
	while (l1 <= i)
	{
		j = (l1 + i) / 2;
		if (a[j] == key)
		{
			return j;
		}
		else
		if (a[j] < key)
			l1 = j + 1;
		else
			i = j - 1;
	}
	if (flag == 0)
		return -1;
	return -1;
}

int recursiveBinarySearch(int* a, int left, int right, int key){
	if (right >= left) {
		int mid = left + (right - left) / 2;

		if (a[mid] == key)
			return mid;

		if (a[mid] > key)
			return recursiveBinarySearch(a, left, mid - 1, key);

		return recursiveBinarySearch(a, mid + 1, right, key);
	}
	return -1;
}
void main(){
	int x, n = 0;
	int *a = NULL;
	do{
		cout << "0.Exit" << endl;
		cout << "1.Input array" << endl;
		cout << "2.Print array" << endl;
		cout << "3.Find min" << endl;
		cout << "4.Find max" << endl;
		cout << "5.Check if array is ascending" << endl;
		cout << "6.Sum of array" << endl;
		cout << "7.Count prime number in array" << endl;
		cout << "8.Reverse array" << endl;
		cout << "9.Linear seach" << endl;
		cout << "- Sentinel linear search" << endl;
		cout << "- Binary search" << endl;
		cout << "- Recursive Binary search" << endl;
		cout << "Enter number to excute: "; cin >> x;


		if (x == 0){
			return;
		}
		if (x == 1){
			system("cls");

			printf("Nhap n: ");
			scanf_s("%d", &n);
			inputArray(a, n);

			goto next;
		}
		if (n != 0){
			if (x == 2){
				system("cls");

				printArray(a, n);

				goto next;
			}
			if (x == 3){
				system("cls");

				int	min = findMin(a, n);
				cout << "Min = " << min << endl;

				goto next;
			}
			if (x == 4){
				system("cls");

				int max = findMaxModulus(a, n);
				cout << "Max = " << max << endl;

				goto next;
			}
			if (x == 5){
				system("cls");

				if (isAscending(a, n))
					cout << "Array is Ascending" << endl;
				else
					cout << "Array is not Ascending" << endl;

				goto next;
			}
			if (x == 6){
				system("cls");

				cout << "Sum of the elements in array is " << sumofArray(a, n) << endl;

				goto next;
			}
			if (x == 7){
				system("cls");

				cout << "There are " << countPrime(a, n) << " of prime number in array" << endl;

				goto next;
			}
			if (x == 8){
				system("cls");

				cout << "Before revers: ";
				printArray(a, n);
				cout << "After reverse: ";
				reverseArray(a, n);
				printArray(a, n);

				goto next;
			}
			if (x == 9){
				system("cls");

				int key = 0;
				cout << "Enter key: "; cin >> key;
				cout << "Linear search: " << LinearSearch(a, n, key) << endl;
				cout << "Sentinel linear search " << sentinelLinearSearch(a, n, key) << endl;
				sort_(a, n);
				cout << "Binary search: " << BinarySearch(a, n, key) << endl;
				cout << "Recursive binary search: " << recursiveBinarySearch(a, 0, n - 1, key) << endl;

				goto next;
			}
		}
		else{
			system("cls");
			cout << "In order to run task, you have to enter array first!" << endl;
		}
		
	next:
		cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
		system("cls");

	} while (1);

}