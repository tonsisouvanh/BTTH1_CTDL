#include"recursion.h"
int sumOfSquares(int n){
	if (n == 1) return 1;
	else
		return sumOfSquares(n-1) + _Pow_int(n, 2);
}
int fib(int n){
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int gcd(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}

void main(){
	int x, n = 0, a, b;
	cout << "- Sum of squares" << endl;
	cout << "- Fibonnaci" << endl;
	cout << "- Greatest common devide" << endl;

	printf("Enter number to calulate with 3 function above using recursive: ");
	scanf_s("%d", &n);
	printf("Enter a & b: ");
	scanf_s("%d%d", &a, &b);

	do{
		cout << "0.Exit" << endl;
		cout << "1.Sum of squares" << endl;
		cout << "2.Fibonnaci" << endl;
		cout << "3.Greatest common devide" << endl;
		cout << "Enter number to excute: "; cin >> x;

		if (x == 0){
			return;
		}
		if (x == 1){
			system("cls");

			cout << "Sum of squares = " << sumOfSquares(n) << endl;

			goto next;
		}
		if (x == 2){
			system("cls");

			cout <<"Fibonnaci number: "<< fib(n) << endl;

			goto next;
		}
		if (x == 3){
			system("cls");

			cout << "Greatest common devide: " << gcd(a, b) << endl;

			goto next;
		}

		next:
		cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
		system("cls");

	} while (1);

}