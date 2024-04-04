#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class date{
    public:
    int ngay;
    int thang;
    int nam;
};
class hangHoa{
    public:
    string tenHang;
    int soLuong;
};

class hangNoidia : public hangHoa{
    private:
        string nguonGoc = "Viet Nam";
        date ngayNhapHang;
    public:
        string getNguongoc(){
            return nguonGoc;
        }
        void setNgayNhapHang(){
            cout << "Nhap ngay nhap hang: \n";
            cout << "Ngay: ";
            cin >> ngayNhapHang.ngay;
            cout << "Thang: ";
            cin >> ngayNhapHang.thang;
            cout << "Nam : ";
            cin >> ngayNhapHang.nam;
        }
        date getNgayNhaphang(){
            return ngayNhapHang;
        }
};
class hangNgoaidia : public hangHoa{
    private:
    string nguonGoc;
    date ngayNhapHang;
    public:
    string getNguongoc(){
        return nguonGoc;
    }
    void setNguonGoc(const string& value) {
        nguonGoc = value;
    }
    void setNgayNhapHang(date ngayNhapHang){
        cout << "Nhap ngay nhap hang: \n";
        cout << "Ngay: ";
        cin >> ngayNhapHang.ngay;
        cout << "Thang: ";
        cin >> ngayNhapHang.thang;
        cout << "Nam : ";
        cin >> ngayNhapHang.nam;
    }
};
class myphamNoi : public hangNoidia{
    private:
        string congDung;
        string maHang;
        float triGia;
    public:
        void hienThiThongtin();
        void suaThongtin();
        void setThongtin();
};
void myphamNoi::setThongtin(){
    cout << "Nhap ma hang: ";
    // cin.ignore(); // Xóa bộ đệm đầu vào
    getline(cin, maHang);
    cout << "Nhap ten hang: ";
    getline(cin, tenHang);
    cout << "Nhap cong dung: ";
    getline(cin, congDung);
    cout << "Nhap tri gia san pham: ";
    cin >> triGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}
void myphamNoi::hienThiThongtin(){
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Nguon goc: " << getNguongoc() << endl;
    cout << "Cong dung: " << congDung << endl;
    cout << "Tri gia: VND" << triGia << endl;
    cout << "So luong: " << soLuong << endl;
}
void myphamNoi::suaThongtin(){
    int choice;
    cout << "Can sua thong tin gi: \n";
    cout << "1. Tat ca;\n"<< "2. Ma hang;\n" << "3. Ten hang;\n" << "4. Cong dung;\n" << "5. Tri gia;\n" << "6. So luong.\n";
    cout << "Chon: ";
    cin >> choice;
    switch(choice){
        case 1:{
            std::cout << "Ma hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, maHang);
            cout << "Ten hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, tenHang);
            cout << "Cong dung: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin,congDung);
            cout << "Tri gia (VND): " ;
            fflush(stdin);
            cin >> triGia;
            cout << "So luong: ";
            cin >> soLuong;
            break;
        }
        case 2:{
            cout << "Ma hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, maHang);
            break;
        }
        case 3:{
            cout << "Ten hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, tenHang);
            break;
        }
        case 4:{
            cout << "Cong dung: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin,congDung);
            break;
        }
        case 5:{
            cout << "Tri gia: VND" ;
            fflush(stdin);
            cin >> triGia;
            break;
        }
        case 6:{
            cout << "So luong: ";
            fflush(stdin);
            cin >> soLuong;
            break;
        }
        default:
        break;
    }
}
class myphamNgoai : public hangNgoaidia{
    private:
        string congDung;
        string maHang;
        float triGia;
        float thueNhapkhau = 10/100; //% thuế
    public:
        void setThue();
        float getThue();
        void hienThiThongtin();
        void suaThongtin();
        void setThongtin();
};
void myphamNgoai::setThue(){
    cout << "Nhap thue:";
    cin >> thueNhapkhau;
}
float myphamNgoai::getThue(){
    return thueNhapkhau;
}
void myphamNgoai::setThongtin(){
    cout << "Nhap ma hang: ";
    // cin.ignore(); // Xóa bộ đệm đầu vào
    getline(cin, maHang);
    cout << "Nhap ten hang: ";
    getline(cin, tenHang);
    cout << "Nhap cong dung: ";
    getline(cin, congDung);
    cout << "Nhap nguon goc: ";
    string ng_goc;
    getline(cin, ng_goc);
    setNguonGoc(ng_goc);
    cout << "Nhap tri gia san pham: ";
    cin >> triGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}
void myphamNgoai::hienThiThongtin(){
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Nguon goc: " << getNguongoc() << endl;
    cout << "Cong dung: " << congDung << endl;
    cout << "Tri gia: VND" << triGia << endl;
    cout << "So luong: " << soLuong << endl;
}
void myphamNgoai::suaThongtin(){
    int choice;
    cout << "Can sua thong tin gi: \n";
    cout << "1. Tat ca;\n"<< "2. Ma hang;\n" << "3. Ten hang;\n"<< "4. Nguon goc;\n" << "5. Cong dung;\n" << "6. Tri gia;\n" << "7. So luong.\n";
    cout << "Chon: ";
    cin >> choice;
    switch(choice){
        case 1:{
            std::cout << "Ma hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, maHang);
            cout << "Ten hang: ";
            cin.ignore();
            getline(cin, tenHang);
            cout << "Nguon goc: ";
            string ng_goc;
            getline(cin, ng_goc);
            setNguonGoc(ng_goc);
            cout << "Cong dung: ";
            cin.ignore();
            getline(cin, congDung);
            cout << "Tri gia (VND): " ;
            fflush(stdin);
            cin >> triGia;
            cout << "So luong: ";
            cin >> soLuong;
            break;
        }
        case 2:{
            cout << "Ma hang: ";
            cin.ignore();
            getline(cin, maHang);
            break;
        }
        case 3:{
            cout << "Ten hang: ";
            cin.ignore();
            getline(cin, tenHang);
            break;
        }
        case 4:{
            cout << "Nguon goc: ";
            string ng_goc;
            cin.ignore(); 
            getline(cin, ng_goc);
            setNguonGoc(ng_goc);
            break;
        }
        case 5:{
            cout << "Cong dung: ";
            cin.ignore(); 
            getline(cin,congDung);
            break;
        }
        case 6:{
            cout << "Tri gia: VND" ;
            fflush(stdin);
            cin >> triGia;
            break;
        }
        case 7:{
            cout << "So luong: ";
            fflush(stdin);
            cin >> soLuong;
            break;
        }
        default:
        break;
    }
}
class nguoi{
    private:
        string hoVaTen;
        date ngaysinh;
        string sodienthoai;
    public:
        void nhapNgaySinh(){
            cin >> ngaysinh.ngay;
        }
        void hiennNgaySinh(){
            cout << ngaysinh.ngay;
        }
        void nhapTen(){
            cin.ignore();
            getline(cin, hoVaTen);
        }
        void hienTen(){
            cout << hoVaTen;
        }

};
class khachHangThuong : public nguoi{
    private:
        date ngayMua;
    public:
        void chinhSua();
        float thanhToan();
};
class khachHangVip : public nguoi{
    private:
        string ID;
        date ngayThamgia;
    public:
        float phamTramGiamgia;
        int soSanphamDamua;
        void chinhSua();
        float thanhToan();
};
void khachHangVip::chinhSua(){
    cout << "1. Chinh sua tat ca thong tin;\n";
    cout << "2. Chinh sua Ho va Ten;\n";
    cout << "3. Chinh sua so dien thoai;\n";
    cout << "4. Chinh sua ngay tham gia\n";
    cout << "5. Chinh sua pham tram giam gia;\n";
    cout << "6. Chinh sua so san pham da mua.\n";
    cout << "Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1: {

        }
        case 2:{

        }
    }
}
float khachHangVip::thanhToan(){
    while(1){
        cout << "Nhap ma hang";
        string maHang;
        getline(cin, maHang);
        cout << "Nhap so luong";
        int soluong;
        cin >> soluong;
    }
}
class nhanvien : public nguoi{
    string maNhanvien;
    string chucVu;
    string noiO;
};
void setUp(myphamNoi list1[], myphamNgoai list2[], khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){

}
void thanhToan(myphamNoi list1[], myphamNgoai list2[], khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){

}
void menu(myphamNoi list1[], myphamNgoai list2[], khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int choice;
    cout << "1. Thanh toan;\n" << "2. Cai dat;\n" <<"3. Xem thong tin tat ca san pham;\n"<<"0. De thoat.\n"<<"Chon: ";
    cin >> choice;
    switch(choice){
        case 1:
        thanhToan(list1, list2, nguoimua1, nguoimua2);
        return 1;
        break;
        case 2:
        setUp(list1, list2, nguoimua1, nguoimua2);
        return 1;
        case 3:
        // xemThongTinTatCaSanpham(sanpham);
        return 1;
        break;
        case 0:
        return 0;
        default:
        break;
    }
}
int main(){
    khachHangVip* nguoimua1 = new khachHangVip[50];
    khachHangThuong* nguoimua2 = new khachHangThuong[50];
    myphamNoi* list1 = new myphamNoi[50];
    myphamNgoai* list2 = new myphamNgoai[50];
    while(1){
        menu(list1, list2, nguoimua1, nguoimua2);
    }
    return 0;
}