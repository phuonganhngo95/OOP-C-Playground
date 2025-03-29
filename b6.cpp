//Xây dựng lớp tủ lạnh TULANH  gồm những thuộc tính sau: 
//Mã tủ lạnh, tên hãng, dung tích, giá chưa thuế là các 
//thuộc tính. Trong lớp có định nghĩa các hàm sau:
//-	Hàm khởi tạo với các tham số có giá trị ngầm định.
//-	Hàm hủy.
//-	Hàm nhập dữ liệu cho một tủ lạnh.
//-	Hàm in các thông tin của một tủ lạnh.
//-	Hàm tính giá sau thuế. Biết nếu dung tích >= 500 lít 
//thì giá sau thuế = 1,15*giá chưa thuế, ngược lại thì giá 
//sau thuế = 1,1*giá chưa thuế
//  Viết chương trình nhập vào danh sách n tủ lạnh (n 
//nguyên dương nhập từ bàn phím) và in ra màn hình: 
//-	Danh sách tủ lạnh của hãng “Hitachi”
//-	Danh sách tủ lạnh đã sắp xếp theo thứ tự tăng dần của 
//dung tích
//-	Danh sách tủ lạnh đã xóa các tủ lạnh có giá sau thuế 
//< 1000.

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class TULANH {
	protected:
		char ma[100], hang[100];
		int dungtich;
		long long chuathue;
	public:
		TULANH(char ma[100]=" ", char hang[100]=" ", int dungtich=0, long long chuathue=0.0) : dungtich(dungtich), chuathue(chuathue) {
			strcpy(this->ma, ma);
			strcpy(this->hang, hang);
		}
		
		~TULANH() {}
		
		void Nhap();
		
		void Xuat();
		
		long long getSauThue() {
			return (dungtich>=500) ? (1.15*chuathue) : (1.1*chuathue);
		}
		
		friend void Hitachi(TULANH a[], int n);

		friend void DungTich(TULANH a[], int n);
};

void TULANH::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập tên hãng: "; cin.getline(hang, 100);
	fflush(stdin);
	cout << "Nhập dung tích: "; cin >> dungtich;
	cout << "Nhập giá chưa thuế: "; cin >> chuathue;
}

void TULANH::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << hang <<
					setw(20) << dungtich <<
					setw(20) << chuathue <<
					setw(20) << getSauThue() << endl;
}

void nhap(TULANH a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "MÃ:" <<
					setw(20) << "HÃNG:" <<
					setw(20) << "DUNG TÍCH:" <<
					setw(20) << "CHƯA THUẾ:" <<
					setw(20) << "SAU THUẾ:" << endl;
}

void xuat(TULANH a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

void Hitachi(TULANH a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(strcmp(a[i].hang, "Hitachi") == 0) {
			a[i].Xuat();
		}
	}
}

void Swap(TULANH &x, TULANH &y) {
	TULANH temp = x;
	x = y;
	y = temp;
}

void DungTich(TULANH a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i].dungtich > a[j].dungtich) {
				Swap(a[i], a[j]);
			}
		}
	}
	xuat(a, n);
}

void XoaSauThue(TULANH a[], int n) {
	for(int i = 0; i < n; ) {
		if(a[i].getSauThue() < 1000) {
			for(int j = i; j < n-1; j++) {
				a[j] = a[j+1];
			}
			n--;
		} else {
			i++;
		}
	}
	xuat(a, n);
}
int main() {
	int n, lc;
	TULANH a[100];
	
	do {
		cout << "===============================CHƯƠNG TRÌNH QUẢN LÝ TỦ LẠNH===============================" << endl;
		cout << "|| 1. Nhập thông tin                                                                    ||" << endl;
		cout << "|| 2. Danh sách tủ lạnh Hitachi                                                         ||" << endl;
		cout << "|| 3. Sắp xếp dung tích tăng dần                                                        ||" << endl;
		cout << "|| 4. Xóa tủ lạnh có giá sau thuế < 1000                                                ||" << endl; 
		cout << "|| 0. Thoát                                                                             ||" << endl;
		cout << "==========================================================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n=====================================NHẬP THÔNG TIN=====================================" << endl;
				cout << "Nhập số tủ lạnh: "; cin >> n;
				nhap(a, n);
				break;
			}
			
			case 2: {
				cout << "\n======================================TỦ LẠNH HITACHI=====================================" << endl;
				Hitachi(a, n);
				cout << endl;
				break;
			}
			
			case 3: {
				cout << "\n=====================================DUNG TÍCH TĂNG DẦN===================================" << endl;
				DungTich(a, n);
				cout << endl;
				break;
			}
			
			case 4: {
				cout << "\n==================================XOÁ GIÁ SAU THUẾ < 1000=================================" << endl;
				XoaSauThue(a, n);
				cout << endl;
				break;
			}
			
			case 0: {
				break;
			}
			
			default:
				cout << "Lựa chọn không phù hợp" << endl;
		}
	}while(lc != 0);
	return 0;
}
