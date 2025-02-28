//Bài 3: Để quản lý hàng hóa, mỗi một mặt hàng được lưu trữ các 
//thông tin: mã hàng (char[8]), tên hàng (char[30]), số lượng (int), 
//đơn giá (float), thành tiền (float). Hãy lập chương trình thực 
//hiện các yêu cầu sau:
//-Khai báo kiểu dữ liệu cấu trúc lưu trữ thông tin cho một mặt hàng
//-Nhập vào từ bàn phím một danh sách n mặt hàng (không nhập trường 
//Thành tiền).
//-Viết hàm tính thành tiền cho các mặt hàng biết
//-Thành tiền = số lượng * đơn giá
//-Hiển thị thông tin những mặt hàng có đơn giá lớn hơn 50.

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct MH {
	char ma[8], ten[30];
	int slg;
	float gia, thanhTien = 0;
} a[100];

void Nhap(MH a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		fflush(stdin);
		cout << "Nhap ma: "; cin.getline(a[i].ma, 8);
		cout << "Nhap ten: "; cin.getline(a[i].ten, 30);
		fflush(stdin);
		cout << "Nhap so luong: "; cin >> a[i].slg;
		cout << "Nhap gia: "; cin >> a[i].gia;
		a[i].thanhTien += a[i].gia*a[i].gia;
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "MA:" <<
					setw(20) << "TEN:" <<
					setw(20) << "SO LUONG:" <<
					setw(20) << "GIA:" <<
					setw(20) << "THANH TIEN:" << endl;
}

void Xuat(MH a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		cout << left << setw(20) << a[i].gia <<
						setw(20) << a[i].ten <<
						setw(20) << a[i].slg <<
						setw(20) << a[i].gia <<
						setw(2) << a[i].thanhTien << " nghin dong" << endl;
	}
}

void Gia(MH a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i].gia > 50) {
			cout << left << setw(20) << a[i].gia <<
							setw(20) << a[i].ten <<
							setw(20) << a[i].slg <<
							setw(20) << a[i].gia <<
							setw(2) << a[i].thanhTien << " nghin dong" << endl;
		}
	}
}
int main() {
	int n;
	cout << "Nhap so mat hang: "; cin >> n;
	MH a[n];
	Nhap(a, n);
	Xuat(a, n);
	
//	Gia > 50
	cout << "\nMat hang co gia > 50:" << endl;
	Gia(a, n);
	return 0;
}
