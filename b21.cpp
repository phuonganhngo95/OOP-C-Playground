#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class TAIKHOAN {
	protected:
		char stk[100], ten[100];
		long long sodu;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getLai() = 0;
};

void TAIKHOAN::Nhap() {
	fflush(stdin);
	cout << "Nhập số tài khoản: "; cin.getline(stk, 100);
	cout << "Nhập tên chủ: "; cin.getline(ten, 100);
	fflush(stdin);
	cout << "Nhập số dư: "; cin >> sodu;
}

void TAIKHOAN::Xuat() {
	cout << left << setw(20) << stk <<
					setw(20) << ten <<
					setw(20) << sodu;
}

class TAIKHOANTHANHTOAN : public TAIKHOAN {
	protected:
		float phi;
	public:
		void Nhap();
		void Xuat();
		long long getLai() {
			return 0.003*sodu-phi;
		}
};

void TAIKHOANTHANHTOAN::Nhap() {
	TAIKHOAN::Nhap();
	cout << "Nhập phí duy trì: "; cin >> phi;
}

void TAIKHOANTHANHTOAN::Xuat() {
	TAIKHOAN::Xuat();
	cout << setw(20) << phi <<
			setw(20) << getLai() << endl;
}

class TAIKHOANTIETKIEM : public TAIKHOAN {
	protected:
		int kyhan;
	public:
		void Nhap();
		void Xuat();
		long long getLai() {
			if(kyhan < 6) {
				return 0.005 * sodu;
			} else if(kyhan>=6 && kyhan<12) {
				return 0.007 * sodu;
			} else {
				return 0.1 * sodu;
			}
		}
};

void TAIKHOANTIETKIEM::Nhap() {
	TAIKHOAN::Nhap();
	cout << "Nhập kỳ hạn gửi: "; cin >> kyhan;
}

void TAIKHOANTIETKIEM::Xuat() {
	TAIKHOAN::Xuat();
	cout << setw(20) << kyhan <<
			setw(20) << getLai() << endl;
}

class QL {
	public:
		TAIKHOAN *a[100];
		void nhap() {
			int n = 0, lc;
			long long tongdu = 0;
			
			while(true) {
				cout << "Chọn đối tượng Tài khoản:" << endl;
				cout << "1. Thanh toán" << endl;
				cout << "2. Tiết kiệm" << endl;
				cout << "0. Thoát" << endl;
				cout << "Nhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new TAIKHOANTHANHTOAN();
				}
				if(lc == 2) {
					a[n] = new TAIKHOANTIETKIEM();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				tongdu += a[n]->getLai();
				n++;
			}
			cout << "\nTổng số dư sau khi tính lãi suất hàng tháng: " << tongdu << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
