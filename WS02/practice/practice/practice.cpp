#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int arr[5];
	int* arr;
	int c = 3, d = 4;
	swap(c,d);
	cout << "c: " << c << "  d: " << d << endl;
	
	
}