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
    public:
    // string NG = nguonGoc;
    date ngayNhapHang;
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
class hangNgoaidia : public hangHoa{
    public:
    string nguonGoc;
    date ngayNhapHang;
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
    void hienthithongtin();
    void suaThongtin();
    void setThongtin();
};
class myphamNgoai : public hangNgoaidia{
    private:
    string congDung;
    string maHang;
    float triGia;
    public:
    void hienthithongtin();
    void suaThongtin();
    void setThongtin();
};
void myphamNoi::hienthithongtin(){
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
    cout << "1. Tat ca;\n"<< "2. Ma hang;\n" << "3. Ten hang;\n" << "4. Nguon goc;\n" << "5. Cong dung;\n" << "6. Tri gia;\n" << "7. So luong.\n";
    cout << "Chon: ";
    cin >> choice;
    switch(choice){
        case 1:{
            std::cout << "Ma hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, maHang);
            cout << "Ten hang: ";
            getline(cin, tenHang);
            cout << "Nguon goc: ";
            string ng_goc;
            getline(cin, ng_goc);
            setNguonGoc(ng_goc);
            cout << "Cong dung: ";
            getline(cin,congDung);
            cout << "Tri gia: VND" ;
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
            cout << "Nguon goc: ";
            string ng_goc;
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, ng_goc);
            setNguonGoc(ng_goc);
            break;
        }
        case 5:{
            cout << "Cong dung: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
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

};
class khachHangVip : public nguoi{
    private:
    string ID;
    int ngayThamgia;
    public:
    float phamTramGiamgia;
    int soSanphamDamua;
    void chinhsua(string ID);
    // mypham 
    void thanhToan(int soSanphamDamua, float phamTramGiamgia, float tongGiatri){
        
    }
};
void khachHangVip::chinhsua(string ID){
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
class nhanvien : public nguoi{
    string maNhanvien;
    string chucVu;
    string noiO;
};
class chatluong{
    private:
    int sao; //1-5 sao
    string danhgia; //danh gia ve chat luong san pham
    public:
    void vietdanhgia(string maHang);
};
// class mypham_dadau : public mypham{
// };
// class mypham_dathuong : public mypham{
// };
// class mypham_dakho : public mypham{
// };

void chatluong::vietdanhgia(string maHang){
    cout << "Danh gia tu 1-5 sao: ";//Danh gia 1-5 sao
    cin >> sao;
    while(sao<1||sao>5){
        cout << "Danh gia tu 1-5 sao: ";
        cin >> sao;
    }
    cout << "Nhan xet ve san pham: \n"; //Viet danh gia
    cin.ignore();
    getline(cin, danhgia);
}
void myphamNoi::setThongtin(){
    fflush(stdin);
    cout << "Nhap ma hang: ";
    getline(cin, maHang);
    cout << "Nhap ten hang: ";
    cin.ignore(); // Xóa bộ đệm đầu vào
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
int main(){
    khachHangVip* nguoimua = new khachHangVip[10];
    myphamNoi* suaruamat = new myphamNoi[10];
    cout << "Nhap sua rua mat:\n";
    cout << suaruamat[0].getNguongoc();
    // nguoimua->thanhToan(nguoimua->soSanphamDamua,nguoimua->phamTramGiamgia)
    return 0;
}