#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class mypham{
    private:
    std::string maHang;
    std::string tenHang;
    std::string nguonGoc;
    std::string congDung;
    float triGia;
    int soLuong;
    public:
    void hienthithongtin(string maHang);
    void suathongtin(string maHang);
    void themthongtin();
    // int kiemTraArr(string f_txt);
    // int timKiem(mypham sanpham[], string mahang, int n);
    // void thanhToan(mypham sanpham[]);
    // void xemThongTinTatCaSanpham(mypham sanpham[]);
};
void mypham::hienthithongtin(string mahang){
    std::cout << "Ma hang: " << maHang << std::endl;
    std::cout << "Ten hang: " << tenHang << std::endl;
    std::cout << "Nguon goc: " << nguonGoc << std::endl;
    std::cout << "Cong dung: " << congDung << std::endl;
    std::cout << "Tri gia: VND" << triGia << std::endl;
    std::cout << "So luong: " << soLuong << std::endl;
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
            std::cout << "Ten hang: ";
            getline(cin, tenHang);
            std::cout << "Nguon goc: ";
            getline(cin, nguonGoc);
            std::cout << "Cong dung: ";
            getline(cin,congDung);
            std::cout << "Tri gia: VND" ;
            fflush(stdin);
            cin >> triGia;
            std::cout << "So luong: ";
            cin >> soLuong;
            break;
        }
        case 2:{
            std::cout << "Ma hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, maHang);
            break;
        }
        case 3:{
            std::cout << "Ten hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, tenHang);
            break;
        }
        case 4:{
            std::cout << "Nguon goc: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin, nguonGoc);
            break;
        }
        case 5:{
            std::cout << "Cong dung: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            getline(cin,congDung);
            break;
        }
        case 6:{
            std::cout << "Tri gia: VND" ;
            fflush(stdin);
            cin >> triGia;
            break;
        }
        case 7:{
            std::cout << "So luong: ";
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
    sanpham[0].themthongtin();
    sanpham[1].themthongtin();
    sanpham->hienthithongtin("haha");
    return 0;
}
// int main(){
//     mypham* sanpham = new mypham[100];
//     // mypham::docFile(sanpham, "data.txt");
//     while(1){//Vòng lặp chương trình;
//         system("cls");
//         int exitchoice = menuchinh(sanpham);
//         if(exitchoice == 0) break;
//     }
//     delete[] sanpham;
//     return 0;
// }