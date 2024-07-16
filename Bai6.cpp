#include<iostream>
#include<string>
#include<stdlib.h>


using namespace std;

int main() {
	string name;
	string gioitinh;
	int NgaySinh;
	int ThangSinh;
	int NamSinh;
	printf ("Nhap ho ten: ");
	scanf_s("%s", &name);
	printf ("Nhap gioi tinh: ");
	scanf_s("%s", &gioitinh);
	printf ("Nhap ngay sinh : ");
	scanf_s("%d", &NgaySinh);
	printf("Nhap thang sinh : ");
	scanf_s("%d", &ThangSinh);
	printf("Nhap nam sinh : ");
	scanf_s("%d", &NamSinh);
	int tuoi = 2024 - NamSinh;

	if (gioitinh != "nam" && gioitinh != "nu") {
		printf ("Loi!");
		return 0;
	}
	else {
		if (gioitinh == "nam") {
			if (tuoi > 62 || tuoi < 18) {
				printf("Khong phu hop tuoi lao dong");
				return 0;
			}
		}
		if (gioitinh == "nu") {
			if (tuoi > 60 || tuoi < 18) {
				printf("Khong phu hop tuoi lao dong");
				return 0;
			}
		}
	}
	printf (" gioi tinh: %s, sinh ngay: %d/%d/%d, so tuoi hien tai: %d ", gioitinh, NgaySinh, ThangSinh, NamSinh , tuoi);
	if (gioitinh == "nam") {
		printf("Ngay nghi huu la : %d/%d ", ThangSinh, 2024 + 62 - tuoi);
	}
	if (gioitinh == "nu") {
		printf("Ngay nghi huu la : %d/%d ", ThangSinh, 2024 + 60 - tuoi);
	}
}