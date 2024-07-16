#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b, c;
	printf("Nhap so nguyen a: ");
	scanf_s("%d", &a);
	printf("Nhap so nguyen b: ");
	scanf_s("%d", &b);
	printf("Nhap so nguyen c: ");
	scanf_s("%d", &c);
	if (a - b == 0)
	{
		printf("Khong thuc hien duoc phep tinh (mau so khac 0).");
	}
	else
	{
		printf("Ket qua phep tinh: %.2f", c / (double)(a - b));
	}
	_getch();
}