#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class mypham{
    public:
    std::string maHang;
    std::string tenHang;
    std::string nguonGoc;
    std::string congDung;
    float triGia;
    int soLuong;
    // mypham(std::string ma, std::string ten, std::string nguon, std::string cong, float gia) {
    //     maHang = ma;
    //     tenHang = ten;
    //     nguonGoc = nguon;
    //     chucNang = cong;
    //     triGia = gia;
    // }
    void hienthithongtin(string maHang);
};
int kiemTraArr(string f_txt){//Kiểm tra mảng sanpham đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
    int n = 0;
    string line;
    ifstream file(f_txt);
    while(getline(file, line)){
        n++;
    }
    n = n/7;
    return n;
}
void ghiFile(mypham sanpham[], int n){
    ofstream fout("data.txt");
    for(int i = 0; i < n; i++){
        fout << "Ma hang: " << sanpham[i].maHang << std::endl;
        fout << "Ten hang: " << sanpham[i].tenHang << std::endl;
        fout << "Cong dung: " << sanpham[i].congDung << std::endl;
        fout << "Nguon goc: " << sanpham[i].nguonGoc << std::endl;
        fout << "Tri gia san pham: "<< sanpham[i].triGia << std::endl;
        fout << "So luong: "<< sanpham[i].soLuong << std::endl;
        fout << endl;

    }
    fout.close();
}
void docFile(mypham sanpham[], const string& f_txt){
    ifstream file("data.txt");
    int n = kiemTraArr("data.txt");
    int sosanpham = n + 1;
    string line;
    for(int i = 0; i < sosanpham; i++){
        getline(file,line);
        sanpham[i].maHang  = line.substr(9); //Loại bỏ 9 kí tự đầu tiên 
        getline(file,line);
        sanpham[i].tenHang = line.substr(10); //Loại bỏ 10 kí tự đầu tiên
        getline(file,line);
        sanpham[i].nguonGoc = line.substr(11); //Loại bỏ 9 kí tự đầu tiên
        getline(file,line);
        sanpham[i].congDung = line.substr(11); //Loại bỏ 9 kí tự đầu tiên
        getline(file,line);
        sanpham[i].triGia = stoi(line.substr(18)); //Loại bỏ 9 kí tự đầu tiên
        getline(file,line);
        sanpham[i].soLuong = stoi(line.substr(10));
        getline(file,line);
    }
    file.close();
}
void mypham::hienthithongtin(string mahang){
    std::cout << "Ma hang: " << maHang << std::endl;
    std::cout << "Ten hang: " << tenHang << std::endl;
    std::cout << "Nguon goc: " << nguonGoc << std::endl;
    std::cout << "Cong dung: " << congDung << std::endl;
    std::cout << "Tri gia: VND" << triGia << std::endl;
    std::cout << "So luong: " << soLuong << std::endl;
}
void Them(mypham sanpham[]){
    int n = kiemTraArr("data.txt");
    fflush(stdin);
    cout << "Nhap ma hang: ";
    cin >> sanpham[n].maHang;
    cout << "Nhap ten hang: ";
    cin.ignore(); // Xóa bộ đệm đầu vào
    getline(cin, sanpham[n].tenHang);;
    cout << "Nhap cong dung: ";
    getline(cin, sanpham[n].congDung);
    cout << "Nhap nguon goc: ";
    getline(cin, sanpham[n].nguonGoc);
    cout << "Nhap tri gia san pham: ";
    cin >> sanpham[n].triGia;
    cout << "Nhap so luong: ";
    cin >> sanpham[n].soLuong;
    int sosanpham = n + 1;
    ghiFile(sanpham, sosanpham);
    cout << "Da them thanh cong!";
    int choice;
    do{
        cout << "Chon 0 de thoat: ";
        cin >> choice;
    }while(choice != 0);
}
int timKiem(mypham sanpham[], string mahang, int n){//Tìm kiếm sản phẩm nằm ở phần tử số bao nhiêu trong mảng sanpham[];
    for(int i = 0; i < n; i++){
        if(sanpham[i].maHang == mahang) return i;
    }
}
void Xoa(mypham sanpham[]){//Ham xoa thong tin
    int n = kiemTraArr("data.txt");
    cout << "Nhap ma hang can xoa! Ma hang: ";
    string mahang;
    cin.ignore(); // Xóa bộ đệm đầu vào
    getline(cin, mahang);
    int vitriXoa = timKiem(sanpham, mahang, n);
    for(int i = vitriXoa; i < n - 1; i++){
        sanpham[i] = sanpham[i+1];
    }
    cout << "Da xoa thanh cong!";
    int sosanpham = n - 1;
    ghiFile(sanpham, sosanpham);
    int choice;
    do{
        cout << "Chon 0 de thoat: ";
        cin >> choice;
    }while(choice != 0);
}
void Chinh(mypham sanpham[]){//
    cout << "----------------------Chinh sua----------------------------\n";
    cout << "1. Nhap ma san pham de chinh sua;\n" <<"2. Nhap STT san pham de chinh sua;\n"<<"0. De thoat.\n"<<"Chon: ";
    int choice;
    cin >> choice;
    string mahang;
    int n = kiemTraArr("data.txt");
    switch(choice){
        case 0:
        break;
        case 1:{
            fflush(stdin);
            cout << "Nhap ma hang: ";
            getline(cin, mahang);
            int a = timKiem(sanpham, mahang, n);
            fflush(stdin);
            cout << "Nhap ma hang: ";
            sanpham[a].maHang = "";
            cin >> sanpham[a].maHang;
            cout << "Nhap ten hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            sanpham[a].tenHang = "";
            getline(cin, sanpham[a].tenHang);;
            cout << "Nhap cong dung: ";
            sanpham[a].congDung = "";
            getline(cin, sanpham[a].congDung);
            cout << "Nhap nguon goc: ";
            sanpham[a].nguonGoc = "";
            getline(cin, sanpham[a].nguonGoc);
            cout << "Nhap tri gia san pham: ";
            sanpham[a].triGia = 0;
            cin >> sanpham[a].triGia;
            cout << "Nhap so luong: ";
            sanpham[a].soLuong = 0;
            cin >> sanpham[a].soLuong;
            ghiFile(sanpham, n);
            cout << "Da chinh sua thanh cong!\n";
            break;
        }
        case 2:{
            int a;
            cout << "Nhap STT san pham: ";
            cin >> a;
            fflush(stdin);
            cout << "Nhap ma hang: ";
            sanpham[a].maHang = "";
            cin >> sanpham[a].maHang;
            cout << "Nhap ten hang: ";
            cin.ignore(); // Xóa bộ đệm đầu vào
            sanpham[a].tenHang = "";
            getline(cin, sanpham[a].tenHang);;
            cout << "Nhap cong dung: ";
            sanpham[a].congDung = "";
            getline(cin, sanpham[a].congDung);
            cout << "Nhap nguon goc: ";
            sanpham[a].nguonGoc = "";
            getline(cin, sanpham[a].nguonGoc);
            cout << "Nhap tri gia san pham: ";
            sanpham[a].triGia = 0;
            cin >> sanpham[a].triGia;
            cout << "Nhap so luong: ";
            sanpham[a].soLuong = 0;
            cin >> sanpham[a].soLuong;
            ghiFile(sanpham, n);
            cout << "Da chinh sua thanh cong!\n";
        break;
        }
        default:
        break;
    }
    do{
        cout << "Chon 0 de thoat: ";
        cin >> choice;
    }while(choice != 0);
}
void matKhau(){

}
void caiDat(mypham sanpham[]){
    matKhau();
    cout << "-------------------Cai dat---------------------";
    cout << "Chon: \n" << "1. Them thong tin san pham;\n" << "2. Chinh sua thong tin san pham;\n" << "3. Xoa thong tin san pham;\n"<<"Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
        Them(sanpham);
        break;
        case 2:
        Chinh(sanpham);
        break;
        case 3:
        Xoa(sanpham);
        break;
        default:
        break;
    }
}
void thanhToan(mypham sanpham[]){
    cout << "-------------------Thanh toan----------------------\n";
    int choice = 1;
    do{
        cout << "Nhap ma hang: ";
        string mahang;
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, mahang);
        int n = kiemTraArr("data.txt");
        int a = timKiem(sanpham, mahang, n);
        sanpham[a].hienthithongtin(mahang);
        cout << "1. Bam phim bat ki de tiep tuc\n" << "0. Thoat\n" << "Chon: ";
        cin >> choice;
    }while(choice != 0);
}
void xemThongTinTatCaSanpham(mypham sanpham[]){
    cout << "---------------Xem thong tin tat ca san pham-----------------\n";
    int n = kiemTraArr("data.txt");
    cout << "Co " << n + 1 << " loai mat hang;\n";
    for(int i = 0; i < n + 1; i++){
        cout << "---------------------------------------------------------------\n";
        cout << "Ma hang: " << sanpham[i].maHang << endl;
        cout << "Ten hang: "<<sanpham[i].tenHang << endl;
        cout <<"Nguon goc:"<< sanpham[i].nguonGoc << endl;
        cout << "Cong dung:" << sanpham[i].congDung << endl;
        cout << "Gia tri san pham: " <<sanpham[i].triGia << endl;
        cout << "So luong san pham: " << sanpham[i].soLuong <<endl;
    }
    int choice;
    do{
        cout << "Chon 0 de thoat: ";
        cin >> choice;
    }while(choice != 0);
    
}
int menuchinh(mypham sanpham[]){
    int choice;
    cout << "1. Thanh toan;\n" << "2. Cai dat;\n" <<"3. Xem thong tin tat ca san pham;\n"<<"0. De thoat.\n"<<"Chon: ";
    cin >> choice;
    switch(choice){
        case 1:
        thanhToan(sanpham);
        return 1;
        break;
        case 2:
        caiDat(sanpham);
        return 1;
        case 3:
        xemThongTinTatCaSanpham(sanpham);
        return 1;
        break;
        case 0:
        return 0;
        default:
        break;
    }
    // sanpham->hienthithongtin()
}
int main(){
    mypham* sanpham = new mypham[100];
    docFile(sanpham, "data.txt");
    while(1){//Vòng lặp chương trình;
        system("cls");
        int exitchoice = menuchinh(sanpham);
        if(exitchoice == 0) break;
    }
    delete[] sanpham;
    return 0;
}