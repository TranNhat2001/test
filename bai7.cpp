#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<random>
#include<iostream>
#include <cmath>
#define MAX 1000

void nhapM1C_SoNguyen(int *&a, int &n)
{ 
	n = 10;
	a = (int*)malloc(n * sizeof(int)); 
	for (int i = 0; i < n; i++)
		*(a + i) = rand() % 100;
}
void xuatM1C_SoNguyen(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, *(a + i), a + i);
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], a + i);
	}
}
void timMaxVaDiaChi(int *a, int n) {
	int* maxPtr = a;
	for (int i = 1; i < n; i++) {
		if (*(a + i) > *maxPtr) {
			maxPtr = a + i;
		}
	}
	printf("\nPhan tu lon nhat trong mang: %d", *maxPtr);
	printf("\nDia chi cua phan tu lon nhat: %x", maxPtr);
}
void xuatDiaChiChanLe(int *a, int n) {
    int* maxEvenPtr = nullptr;
    int* minOddPtr = nullptr;
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            if (maxEvenPtr == nullptr || *(a + i) > *maxEvenPtr) {
                maxEvenPtr = a + i;
            }
        }
        else {
            if (minOddPtr == nullptr || *(a + i) < *minOddPtr) {
                minOddPtr = a + i;
            }
        }
    }

    if (maxEvenPtr != nullptr) {
        printf("\nDia chi cua phan tu chan lon nhat: %x", maxEvenPtr);
    }
    else {
        printf("\nKhong co phan tu chan trong mang.");
    }

    if (minOddPtr != nullptr) {
        printf("\nDia chi cua phan tu le nho nhat: %x", minOddPtr);
    }
    else {
        printf("\nKhong co phan tu le trong mang.");
    }
}
void xoaPhanTu(int *a, int &n, int value) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) == value) {
            for (int j = i; j < n - 1; j++) {
                *(a + j) = *(a + j + 1);
            }
            n--;
            i--;
        }
    }
}
void themPhanTuDauTien(int *a, int &n, int x) {
    for (int i = n - 1; i >= 0; i--) {
        a[i + 1] = a[i];
    }
    a[0] = x;
    n++;
}
bool laSoChinhPhuong(int n) {
    int sqr = sqrt(n);
    return (sqr * sqr == n);
}
int tongSoChinhPhuong(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(a[i])) {
            sum += a[i];
        }
    }
    printf("\nTong so chinh phuong la: %d", sum);
    return sum;
}
void lietKeCucDai(int a[MAX], int n)
{
    printf("\nCac gia tri cuc dai co trong mang la:");
    for (int i = 1;i < n - 1;i++)
    {
        int b = a[i] - a[i - 1];
        int c = a[i] - a[i + 1];
        if (b > 0 && c > 0)
            printf("%d ", *&a[i]);
    }
}
void main()
{
    int *a, n, x = 36, value = 0;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);
	timMaxVaDiaChi(a, n);
    xuatDiaChiChanLe(a, n);
    xoaPhanTu(a, n, value);
    themPhanTuDauTien(a, n, x);
    xuatM1C_SoNguyen(a, n);
    tongSoChinhPhuong(a, n);
    lietKeCucDai(a, n);
	_getch();
}