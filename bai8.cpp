#include <iostream>
#include<stdio.h>
#include<stdio.h>
#include<conio.h>

struct PhanSo {
    int tu;
    int mau;
};

void Nhap(PhanSo &ps) {
    do {
        printf ("Nhap tu so: ");
        scanf_s("%d", &ps.tu);
        printf("Nhap mau so (khac 0): ");
        scanf_s("%d", &ps.mau);
    } while (ps.mau == 0);
}
void Xuat(const PhanSo &ps) {
    printf("%d/%d \n",ps.tu, ps.mau);
}
void XuatMauLonHonTu(const PhanSo a[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].mau > a[i].tu) {
            Xuat(a[i]);
            j++;
        }
    }
    if (j == 0)
    {
        printf("Khong co \n");
    }
}
int DemPhanSoChan(const PhanSo a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].tu % 2 == 0 && a[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void RutGon(PhanSo &ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}
PhanSo TinhTich(const PhanSo a[], int n) {
    PhanSo result = a[0];
    for (int i = 1; i < n; i++) {
        result.tu *= a[i].tu;
        result.mau *= a[i].mau;
    }
    return result;
}
PhanSo TimMax(const PhanSo a[], int n) {
    PhanSo maxPS = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].tu * maxPS.mau > maxPS.tu * a[i].mau) {
            maxPS = a[i];
        }
    }
    return maxPS;
}
void main()
{
    int n;
    printf("Nhap so luong phan so: ");
    scanf_s("%d", &n);
    PhanSo* a = new PhanSo[n];

    printf("Nhap cac phan so:\n");
    for (int i = 0; i < n; i++) {
        Nhap(a[i]);
    }

    printf("Cac phan so co mau lon hon tu:\n");
    XuatMauLonHonTu(a, n);

    int dem = DemPhanSoChan(a, n);
    if (dem == 0)
    {
        printf("khong co phan so co mau va tu chan\n");
    }
    else
    {
        printf("So phan so co mau va tu chan: %d \n", dem);
    }
    
    printf("Rut gon cac phan so:\n");
    for (int i = 0; i < n; i++) {
        RutGon(a[i]);
        Xuat(a[i]);
    }
    PhanSo tinhTich = TinhTich(a, n);
    RutGon(tinhTich);
    printf("Tich cac phan so: %d/%d \n", tinhTich.tu, tinhTich.mau);

    PhanSo maxPS = TimMax(a, n);
    RutGon(maxPS);
    printf("Phan so lon nhat: %d/%d \n", maxPS.tu, maxPS.mau);
	_getch();
}