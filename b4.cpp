//Bài 4: Tạo cấu trúc Hocsinh gồm các thành phần sau: Mã số 
//(ms Kiểu chuỗi 7 ký tự), Họ và tên (ht kiểu chuỗi 30 ký tự), 
//Quê quán (qq kiểu chuỗi 30 ký tự), tổng điểm (td kiểu float). 
//Sau đó viết chương trình gồm các chức năng sau:
//-	Nhập danh sách gồm n học sinh trong đó n nguyên dương được 
//nhập vào từ bàn phím.
//-	In ra danh sách lớp theo thứ tự giảm dần của tổng điểm
//-	In ra danh sách các học sinh có quê tai Nam Định

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct Hocsinh {
	char ma[7], hoten[30], quequan[30];
	float tongdiem;
} a[100];

void Nhap(Hocsinh a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		fflush(stdin);
		cout << "Nhap ma: "; cin.getline(a[i].ma, 7);
		cout << "Nhap ho ten: "; cin.getline(a[i].hoten, 30);
		cout << "Nhap que quan: "; cin.getline(a[i].quequan, 30);
		fflush(stdin);
		cout << "Nhap tong diem: "; cin >> a[i].tongdiem;
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "MA:" <<
					setw(20) << "HO TEN:" <<
					setw(20) << "QUE QUAN:" <<
					setw(20) << "TONG DIEM:" << endl;
}

void Xuat(Hocsinh a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		cout << left << setw(20) << a[i].ma <<
						setw(20) << a[i].hoten <<
						setw(20) << a[i].quequan <<
						setw(20) << a[i].tongdiem << endl;
	}
}

void Swap(Hocsinh &x, Hocsinh &y) {
	Hocsinh temp = x;
	x = y;
	y = temp;
}

void Sapxep(Hocsinh a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i].tongdiem < a[j].tongdiem) {
				Swap(a[i], a[j]);
			}
		}
	}
	Xuat(a, n);
}

void Quequan(Hocsinh a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(strcmp(a[i].quequan, "Nam Dinh") == 0) {
			cout << left << setw(20) << a[i].ma <<
							setw(20) << a[i].hoten <<
							setw(20) << a[i].quequan <<
							setw(20) << a[i].tongdiem << endl;
		}
	}
}

int main() {
	int n;
	cout << "Nhap so hoc sinh: "; cin >> n;
	Hocsinh a[n];
	Nhap(a, n);
	Xuat(a, n);
	
//	Tong diem giam dan
	cout << "\nDanh sach sau khi sap xep:" << endl;
	Sapxep(a, n);
	
//	Que quan Nam Dinh
	cout << "\nDanh sach hoc sinh que Nam Dinh:" << endl;
	Quequan(a, n);
	return 0;
}
