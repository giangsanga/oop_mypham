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
class khachhang{
    private:
    string hovaTen;
    date ngaysinh;
    string sodienthoai;
    public:
    void nhapngaysinh(){
        cin >> ngaysinh.ngay;
    }
    void hienngaysinh(){
        cout << ngaysinh.ngay;
    }
};
class khachhangVip : public khachhang{
    string ID;
    float giamGia;// phan tram giam gia
    int soSanphamDamua;
    int ngayThamgia;
};
class mypham{
    private:
    string maHang;
    string tenHang;
    string nguonGoc;
    string congDung;
    float triGia;
    int soLuong;
    public:
    void hienthithongtin(string maHang);
    void suathongtin(string maHang);
    void themthongtin();
};
class mypham_dadau : public mypham{

};
class mypham_dathuong : public mypham{

};
class mypham_dakho : public mypham{

};
// class date : public mypham{
//     private:
//     int ngay;
//     int thang;
//     int nam;
//     public:
//     date();
//     date(int ngay, int thang, int nam);
//     void thongtindate();
//     void nsx();
//     void hsd();
// };
class chatluong : public mypham{
    private:
    int sao; //1-5 sao
    string danhgia; //danh gia ve chat luong san pham
    public:
    void vietdanhgia(string maHang);
};
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
void mypham::hienthithongtin(string mahang){
    cout << "Ma hang: " << maHang << endl;
    cout << "Ten hang: " << tenHang << endl;
    cout << "Nguon goc: " << nguonGoc << endl;
    cout << "Cong dung: " << congDung << endl;
    cout << "Tri gia: VND" << triGia << endl;
    cout << "So luong: " << soLuong << endl;
}
void mypham::suathongtin(string mahang){
    int choice;
    cout << "Can sua thong tin gi ve: \n";
    hienthithongtin(maHang);
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
            getline(cin, nguonGoc);
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
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, nguonGoc);
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
void mypham::themthongtin(){
    fflush(stdin);
    cout << "Nhap ma hang: ";
    getline(cin, maHang);
    cout << "Nhap ten hang: ";
    cin.ignore(); // Xóa bộ đệm đầu vào
    getline(cin, tenHang);
    cout << "Nhap cong dung: ";
    getline(cin, congDung);
    cout << "Nhap nguon goc: ";
    getline(cin, nguonGoc);
    cout << "Nhap tri gia san pham: ";
    cin >> triGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}
int main(){
    mypham* sanpham = new mypham[100];
    khachhang mangnguoi[10];
    mangnguoi[0].nhapngaysinh();
    mangnguoi[0].hienngaysinh();
    return 0;
}z