#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
namespace Soluong{
    int Nhanvien = 0;
    int KhachVip = 0;
    int KhachThuong = 0;
    int myphamNoi = 0;
    int myphamNgoai = 0;
}
class date{
    public:
    int ngay;
    int thang;
    int nam;
    date(){};
    date(int ngay, int thang, int nam){
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
};
class hangHoa{
    private:
    string tenHang;
    int soLuong;
    date ngayNhapHang;
    public:
    hangHoa(){};
    void setTenHang(){
        cout << "Nhap ten hang: ";
        getline(cin, tenHang);
    }
    void setTenHang(string tenHang){
        this->tenHang = tenHang;
    }
    void setSoluong(){
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }
    void setSoluong(int soLuong){
        this->soLuong = soLuong;
    }
    void setNgayNhapHang(int ngay, int thang, int nam){
        ngayNhapHang = date(ngay, thang, nam);
    }
    void setNgayNhapHang(){
        cout << "Nhap ngay nhap hang: \n";
        cout << "Ngay: ";
        cin >> ngayNhapHang.ngay;
        cout << "Thang: ";
        cin >> ngayNhapHang.thang;
        cout << "Nam: ";
        cin >> ngayNhapHang.nam;
    }
    string getTenHang(){
        return tenHang;
    }
    int getSoluong(){
        return soLuong;
    }
    date getNgayNhaphang(){
        return ngayNhapHang;
    }
};
class hangNoidia : public hangHoa{
    private:
    string nguonGoc = "Viet Nam";
    public:
    hangNoidia(){};
    string getNguongoc(){
        return nguonGoc;
    }
};
class hangNgoaidia : public hangHoa{
    private:
    string nguonGoc;
    float thueNhapkhau = 10/100; //% thuế
    public:
    hangNgoaidia(){};
    string getNguongoc(){
        return nguonGoc;
    }
    float getThueNhapkhau(){
        return thueNhapkhau;
    }
    void setNguongoc(){
        cout << "Nhap nguon goc: ";
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, nguonGoc);
    }
    void setNguongoc(string ng_goc){
        this->nguonGoc = ng_goc;
    }
    void setThueNhapkhau(){
        cout << "Nhap phan tram thue nhap khau: ";
        cin >> thueNhapkhau;
    }
    void setThueNhapkhau(int thue){
        this->thueNhapkhau = thue;
    }
};
class myphamNoi : public hangNoidia{
    private:
    string congDung;
    string maHang;
    float triGia;
    public:
    myphamNoi(){};
    string getCongDung(){
        return congDung;
    }
    string getMahang(){
        return maHang;
    }
    float getTriGia(){
        return triGia;
    }
    void setMaHang(){
        cout << "Nhap ma hang: ";
        getline(cin,maHang);
    }
    void setMaHang(string mH){
        this->maHang = mH;
    }
    void setCongDung(){
        cout << "Nhap cong dung: ";
        getline(cin, congDung);
    }
    void setCongDung(string cD){
        this->congDung = cD;
    }
    void setTrigia(){
        cout<<"Nhap tri gia: ";
        cin >> triGia;
    }
    void setTrigia(float tG){
        this->triGia = tG;
    }
    void setThongtin(){
        cin.ignore();
        setMaHang();
        setTenHang();
        setCongDung();
        setTrigia();
        setSoluong();
        setNgayNhapHang();
    }
    void hienThiThongtin(){
        cout << "Ma hang: " << getMahang() << endl;
        cout << "Ten hang: " << getTenHang() << endl;
        cout << "Nguon goc: " << getNguongoc() << endl;
        cout << "Cong dung: " << getCongDung() << endl;
        cout << "Tri gia: VND" << getTriGia() << endl;
        cout << "So luong: " << getSoluong() << endl;
    }
    void suaThongtin(){
        int choice;
        cout << "Can sua thong tin gi: \n";
        cout << "1. Tat ca;\n"
        << "2. Ma hang;\n" 
        << "3. Ten hang;\n" 
        << "4. Cong dung;\n" 
        << "5. Tri gia;\n" 
        << "6. So luong;\n"
        << "7. Ngay nhap hang.";
        cout << "Chon: ";
        cin >> choice;
        switch(choice){
            case 1:{
                setMaHang();
                setTenHang();
                setCongDung();
                setTrigia();
                setSoluong();
                setNgayNhapHang();
                break;
            }
            case 2:{
                setMaHang();
                break;
            }
            case 3:{
                setTenHang();
                break;
            }
            case 4:{
                setCongDung();
                break;
            }
            case 5:{
                setTrigia();
                break;
            }
            case 6:{
                setSoluong();
                break;
            }
            case 7:{
                setNgayNhapHang();
                break;
            }
            default:
            break;
        }
    }
    ///////
    string f_txt = "data_sanpham_noidia.txt";
    int kiemTraTxt(){//Kiểm tra file đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
        int n = 0;
        string line;
        ifstream file("data_sanpham_noidia.txt");
        while(getline(file, line)){
            n++;
        }
        n = n/8;
        return n;
        file.close();
    }
    void ghiFile(myphamNoi sanpham[], int soluongsanpham){
        // int n = kiemTraTxt();
        while(1){
            ifstream infile("data_sanpham_noidia.txt");
            // Kiểm tra file có mở thành công hay không
            if (infile.is_open()) {
                // File tồn tại, thực hiện thao tác
                ofstream fout(f_txt);
                for(int i = 0; i < soluongsanpham; i++){
                    fout <<"Ma hang: "<< sanpham[i].getMahang() << endl;
                    fout <<"Ten hang: " << sanpham[i].getTenHang() << endl;
                    fout <<"Cong dung: " << sanpham[i].getCongDung() << endl;
                    fout <<"Tri gia: " <<sanpham[i].getTriGia() << endl;
                    fout <<"So luong: "<<sanpham[i].getSoluong() << endl;
                    fout <<"Ngay: " <<sanpham[i].getNgayNhaphang().ngay << endl;
                    fout <<"Thang: " <<sanpham[i].getNgayNhaphang().thang << endl;
                    fout <<"Nam: " <<sanpham[i].getNgayNhaphang().nam << endl;
                }
                fout.close();
                infile.close();
                break;
            } else {
                //Tạo file mới;
                ofstream outfile(f_txt);
                // Đóng file
                outfile.close();
            }
        }
    }
    void docFile(myphamNoi sanpham[]){
        ifstream file(f_txt);
        if(file.is_open()){
            int n = kiemTraTxt();
            int sosanpham = n + 1;
            string line;
            int i = 0;
            while(n != 0 && i < n){
                getline(file,line);
                sanpham[i].setMaHang(line.substr(9));
                getline(file,line);
                sanpham[i].setTenHang(line.substr(10));
                getline(file,line);
                sanpham[i].setCongDung(line.substr(11));
                getline(file,line);
                sanpham[i].setTrigia(stof(line.substr(9)));
                getline(file,line);
                sanpham[i].setSoluong(stoi(line.substr(10)));
                getline(file,line);
                int ngay;
                ngay = stoi(line.substr(6));
                getline(file,line);
                int thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                int nam;
                nam = stoi(line.substr(5));
                sanpham[i].setNgayNhapHang(ngay, thang, nam);     
                i++;
            }
            file.close();
        }
    }
    int timKiem(myphamNoi sanpham[], string mahang, int n){//Tìm kiếm sản phẩm nằm ở phần tử số bao nhiêu trong mảng sanpham[];
        for(int i = 0; i < n; i++){
            if(sanpham[i].getMahang() == mahang) return i;
        }
        return -1;
    }
    void Xoa(myphamNoi sanpham[]){//Ham xoa thong tin
        int n = kiemTraTxt();
        cout << "Nhap ma hang can xoa! Ma hang: ";
        string mahang;
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, mahang);
        int vitriXoa = timKiem(sanpham, mahang, n);
        for(int i = vitriXoa; i < n - 1; i++){
            sanpham[i] = sanpham[i+1];
        }
        cout << "Da xoa thanh cong!\n";
        int sosanpham = n - 1;
        ghiFile(sanpham, sosanpham);
        int choice;
    }
};
class myphamNgoai : public hangNgoaidia{
    private:
    string congDung;
    string maHang;
    float triGia;
    public:
    myphamNgoai(){};
    string getCongDung(){
        return congDung;
    }
    string getMahang(){
        return maHang;
    }
    float getTriGia(){
        return triGia;
    }
    void setMaHang(){
        cout << "Nhap ma hang: ";
        getline(cin, maHang);
    }
    void setMaHang(string mH){
        this->maHang = mH;
    }
    void setCongDung(){
        cout << "Nhap cong dung: ";
        getline(cin, congDung);
    }
    void setCongDung(string cD){
        this->congDung = cD;
    }
    void setTrigia(){
        cout<<"Nhap tri gia: ";
        cin >> triGia;
    }
    void setTrigia(float tG){
        this->triGia = tG;
    }
    void setThongtin(){
        cin.ignore();
        setMaHang();
        setTenHang();
        setCongDung();
        setTrigia();
        setSoluong();
        setThueNhapkhau();
        setNgayNhapHang();
        setNguongoc();
    }
    void hienThiThongtin(){
        cout << "Ma hang: " << getMahang() << endl;
        cout << "Ten hang: " << getTenHang() << endl;
        cout << "Nguon goc: " << getNguongoc() << endl;
        cout << "Cong dung: " << getCongDung() << endl;
        cout << "Tri gia: VND" << getTriGia() << endl;
        cout << "So luong: " << getSoluong() << endl;
        cout << "Thue nhap khau: "<< getThueNhapkhau() <<endl;
    }
    void suaThongtin(){
        int choice;
        cout << "Can sua thong tin gi: \n";
        cout << "1. Tat ca;\n"
        << "2. Ma hang;\n" 
        << "3. Ten hang;\n"
        << "4. Nguon goc;\n" 
        << "5. Cong dung;\n" 
        << "6. Tri gia;\n" 
        << "7. So luong;\n" 
        <<"8. Thue;\n"
        <<"9. Ngay nhap hang;";
        cout << "Chon: ";
        cin >> choice;
        switch(choice){
            case 1:{
                setMaHang();
                setTenHang();
                setNguongoc();
                setCongDung();
                setTrigia();
                setSoluong();
                setThueNhapkhau();
                setNgayNhapHang();
                break;
            }
            case 2:{
                setMaHang();
                break;
            }
            case 3:{
                setTenHang();
                break;
            }
            case 4:{
                setNguongoc();
                break;
            }
            case 5:{
                setCongDung();
                break;
            }
            case 6:{
                setTrigia();
                break;
            }
            case 7:{
                setSoluong();
                break;
            }
            case 8:{
                setThueNhapkhau();
                break;
            }
            case 9:{
                setNgayNhapHang();
                break;
            }
            default:
            break;
        }
    }
    ///////
    string f_txt = "data_sanpham_ngoaidia.txt";
    int kiemTraTxt(){//Kiểm tra file đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
        int n = 0;
        string line;
        ifstream file("data_sanpham_ngoaidia.txt");
        while(getline(file, line)){
            n++;
        }
        n = n/10;
        return n;
        file.close();
    }
    void ghiFile(myphamNgoai sanpham[], int soluongsanpham){
        // int n = kiemTraTxt();
        while(1){
            ifstream infile("data_sanpham_ngoaidia.txt");
            // Kiểm tra file có mở thành công hay không
            if (infile.is_open()) {
                // File tồn tại, thực hiện thao tác
                ofstream fout(f_txt);
                for(int i = 0; i < soluongsanpham; i++){
                    fout <<"Ma hang: "<< sanpham[i].getMahang() << endl;
                    fout <<"Ten hang: " << sanpham[i].getTenHang() << endl;
                    fout <<"Cong dung: " << sanpham[i].getCongDung() << endl;
                    fout <<"Tri gia: " <<sanpham[i].getTriGia() << endl;
                    fout <<"So luong: "<<sanpham[i].getSoluong() << endl;
                    fout <<"Ngay: " <<sanpham[i].getNgayNhaphang().ngay << endl;
                    fout <<"Thang: " <<sanpham[i].getNgayNhaphang().thang << endl;
                    fout <<"Nam: " <<sanpham[i].getNgayNhaphang().nam << endl;
                    fout <<"Thue nhap khau: "<<sanpham[i].getThueNhapkhau() <<endl;
                    fout <<"Nguon goc: "<<sanpham[i].getNguongoc()<<endl;
                }
                fout.close();
                infile.close();
                break;
            } else {
                //Tạo file mới;
                ofstream outfile(f_txt);
                // Đóng file
                outfile.close();
            }
        }

    }
    void docFile(myphamNgoai sanpham[]){
        ifstream file(f_txt);
        if(file.is_open()){
            int n = kiemTraTxt();
            int sosanpham = n + 1;
            string line;
            int i = 0;
            while(n != 0 && i < n){
                getline(file,line);
                sanpham[i].setMaHang(line.substr(9));
                getline(file,line);
                sanpham[i].setTenHang(line.substr(10));
                getline(file,line);
                sanpham[i].setCongDung(line.substr(11));
                getline(file,line);
                sanpham[i].setTrigia(stof(line.substr(9)));
                getline(file,line);
                sanpham[i].setSoluong(stoi(line.substr(10)));
                getline(file,line);
                int ngay;
                ngay = stoi(line.substr(6));
                getline(file,line);
                int thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                int nam;
                nam = stoi(line.substr(5));
                sanpham[i].setNgayNhapHang(ngay, thang, nam);   
                getline(file,line);
                sanpham[i].setThueNhapkhau(stoi(line.substr(16)));
                getline(file,line);
                sanpham[i].setNguongoc(line.substr(11));
                i++;
            }
            file.close();
        }
    }
    int timKiem(myphamNgoai sanpham[], string mahang, int n){//Tìm kiếm sản phẩm nằm ở phần tử số bao nhiêu trong mảng sanpham[];
    for(int i = 0; i < n; i++){
        if(sanpham[i].getMahang() == mahang) return i;
    }
    return -1;
}
    void Xoa(myphamNgoai sanpham[]){//Ham xoa thong tin
        int n = kiemTraTxt();
        cout << "Nhap ma hang can xoa! Ma hang: ";
        string mahang;
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, mahang);
        int vitriXoa = timKiem(sanpham, mahang, n);
        for(int i = vitriXoa; i < n - 1; i++){
            sanpham[i] = sanpham[i+1];
        }
        cout << "Da xoa thanh cong!\n";
        int sosanpham = n - 1;
        ghiFile(sanpham, sosanpham);
        int choice;
    }
};

class nguoi{
    private:
    string hoVaTen;
    date ngaySinh;
    string soDienthoai;
    public:
    nguoi(){};
    string getHovaTen(){
        return hoVaTen;
    }
    date getNgaySinh(){
        return ngaySinh;
    }
    string getsoDienthoai(){
        return soDienthoai;
    }
    void setHovaTen(){
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, hoVaTen);
    }
    void setHovaTen(string HvT){
        this->hoVaTen = HvT;
    }
    void setNgaysinh(){
        cout << "Nhap ngay sinh: ";
        cout << "Ngay: ";
        int ngay;
        cin >> ngay;
        cout << "Thang: ";
        int thang;
        cin >> thang;
        cout << "Nam :";
        int nam;
        cin >> nam;
        this->ngaySinh = date(ngay, thang, nam);
    }
    void setNgaysinh(int ngay, int thang, int nam){
        this -> ngaySinh = date(ngay, thang, nam);
    }
    void setSoDienthoai(){
        cout << "Nhap so dien thoai: ";
        getline(cin, this->soDienthoai);
    }
    void setSoDienthoai(string sdt){
        this->soDienthoai = sdt;
    }
};

class khachHangThuong : public nguoi{
    private:
    date ngayMua;
    int diemTichLuy;
    public:
    khachHangThuong(){};
    void setNgaymua(){
        cout << "Nhap ngay mua hang: ";
        cout << "Ngay: ";
        int ngay;
        cin >> ngay;
        cout << "Thang: ";
        int thang;
        cin >> thang;
        cout << "Nam :";
        int nam;
        cin >> nam;
        this -> ngayMua = date(ngay, thang, nam);
    }
    void setNgaymua(int ngay, int thang, int nam){
        this -> ngayMua = date(ngay, thang, nam);
    }
    void setDiemtichluy(){
        cout << "Nhap diem tich luy: ";
        cin >> diemTichLuy;
    }
    void setDiemtichluy(int dtl){
        this->diemTichLuy = dtl;
    }
    date getNgaymua(){
        return ngayMua;
    }
    int getDiemtichluy(){
        return diemTichLuy;
    }
    void setThongtin(){
        setHovaTen();
        setNgaysinh();
        cin.ignore();
        setSoDienthoai();
        setNgaymua();
        setDiemtichluy();
    }
    void chinhSua(khachHangThuong khachhang[]){
        int n = kiemTraTxt();
        cout << "Nhap so dien thoai de sua thong tin\n";
        string sdt;
        cin.ignore();
        getline(cin,sdt);
        int vitri = timKiem(khachhang, sdt, n);
        cout << "1. Chinh sua tat ca thong tin;\n";
        cout << "2. Chinh sua Ho va Ten;\n";
        cout << "3. Chinh sua ngay sinh\n";
        cout << "4. Chinh sua so dien thoai;\n";
        cout << "5. Chinh sua so diem tich luy;\n";
        cout << "6. Ngay mua gan nhat.\n";
        cout << "Chon: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1: {
                khachhang[vitri].setThongtin();
                break;
            }
            case 2:{
                khachhang[vitri].setHovaTen();
                break;
            }
            case 3:{
                khachhang[vitri].setNgaysinh();
            }
            case 4:{
                khachhang[vitri].setSoDienthoai();
                break;
            }
            case 5:{
                khachhang[vitri].setDiemtichluy();
                break;
            }
            case 6:{
                khachhang[vitri].setNgaymua();
            }
            default:
            break;
        }
    }
    // float thanhToan(float giatri, int soluong){
    //     return giatri = giatri*soluong*(1);
    // }
    ///////
    ///////////////////////////////////////////////////////////////////////////////////////
    void thanhToan(khachHangThuong khach[], myphamNoi list1[], myphamNgoai list2[]) {
        int slmpnoi = list1->kiemTraTxt();
        int slmpngoai = list2->kiemTraTxt(); 
        // cout << "slmpngoai " << slmpngoai << endl;
        int slkh = khach->kiemTraTxt();
        float total = 0;
        float giamgia = 1;// giam 5%
        int soLuong = 0;
        int thanhtien = 0;
        int exit = 0;
        if(slmpngoai == 0 && slmpnoi == 0){
            cout << "Hien tai cua hang chua co san pham nao!!!\n";
        }else if(slkh == 0){
            cout << "Hien tai cua hang chua co khach hang vip nao!!!\n";
        }
        if(slkh != 0){
            int error = 0;
            while(1){
                if(exit == 1) break;
                cout << "Nhap ID: ";
                string iid;
                cin.ignore();
                getline(cin, iid);
                int vitri = timKiem(khach, iid, slkh);
                if(vitri == -1){
                    cout << "Khong tim thay khach hang!!!\n";
                }else{
                    cout << "Chao mung khach hang: " << khach[vitri].getHovaTen() << endl;
                    cout << "So dien thoai: " << khach[vitri].getsoDienthoai() << endl;
                    cout << "Diem tich luy: " << khach[vitri].getDiemtichluy() << endl;
                    while(1){
                        total = 0;
                        string mahang;
                        fflush(stdin);
                        cout << "Nhap ma hang: ";
                        getline(cin, mahang);
                        for(int i = 0; i < slmpnoi; i++){
                            if(mahang == list1[i].getMahang()){
                                cout << "San pham: " << list1[i].getTenHang() << endl;
                                cout <<" so luong : "<< list1[i].getSoluong() << endl;
                                cout <<" Gia tien : "<< list1[i].getTriGia() << endl;
                                if (list1[i].getSoluong() == 0){
                                    cout << "San pham da het hang!!!\n";
                                    break;
                                }
                                cout << "Nhap so luong muon mua: ";
                                cin >> soLuong;     
                                float giaBan = list1[i].getTriGia();
                                total += giaBan * soLuong;
                                list1[i].setSoluong(list1[i].getSoluong() - soLuong);
                                list1->ghiFile(list1, slmpnoi);
                                // break;
                            }
                        }
                        for(int i = 0; i < slmpngoai; i++){
                            if(mahang == list2[i].getMahang()){
                                cout << "San pham: " << list2[i].getTenHang() << endl;
                                cout <<" so luong : "<< list2[i].getSoluong() << endl;
                                cout <<" Gia tien : "<< list2[i].getTriGia() << endl;
                                if (list2[i].getSoluong() == 0){
                                    cout << "San pham da het hang!!!\n";
                                    break;
                                }
                                cout << "Nhap so luong muon mua: ";
                                cin >> soLuong;     
                                float giaBan = list2[i].getTriGia();
                                total += giaBan * soLuong;
                                list2[i].setSoluong(list2[i].getSoluong() - soLuong);
                                list2->ghiFile(list2, slmpngoai);
                                // break;
                            }
                        }
                        thanhtien = thanhtien + total*giamgia;
                        cout << "Nhap 0 de ket thuc thanh toan cho khach hang " << khach[vitri].getHovaTen()
                        << "\nNhap 1 de tiep tuc thanh toan\n";
                        int choice;
                        cin >> choice;
                        if (choice == 0) {
                            exit = 1;
                            if( thanhtien >= 500000 && thanhtien < 1000000){
                                giamgia  = 0.85; //giam 15%
                            }else if (thanhtien >= 1000000 && thanhtien < 2000000){
                                giamgia = 0.8 ;// giam 20%
                            }else if (thanhtien >= 2000000){
                                giamgia = 0.7; // giam 30%
                            }
                            cout << "Tong tien: " << thanhtien*giamgia <<" VND"<<endl;
                            ///////////////////
                            cout << "Nhan phim bat ky de ket thuc!!!";
                            cin.ignore();
                            cin.get();
                            ////////////////
                            break;// này là break vòng while hả// đsung k, ddr may
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
        }
    }
    ///////
    string f_txt = "data_khachhang_thuong.txt";
    int kiemTraTxt(){//Kiểm tra file đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
        int n = 0;
        string line;
        ifstream file(f_txt);
        while(getline(file, line)){
            n++;
        }
        n = n/9;
        return n;
        file.close();
    }
    void ghiFile(khachHangThuong khachhang[], int soluongkhachhang){
        // int n = kiemTraTxt();
        while(1){
            ifstream infile(f_txt);
            // Kiểm tra file có mở thành công hay không
            if (infile.is_open()) {
                // File tồn tại, thực hiện thao tác
                ofstream fout(f_txt);
                for(int i = 0; i < soluongkhachhang; i++){
                    fout <<"Ho va ten: "<< khachhang[i].getHovaTen() << endl;
                    fout <<"So dien thoai: " << khachhang[i].getsoDienthoai() << endl;
                    fout <<"Ngay sinh: "<<khachhang[i].getNgaySinh().ngay << endl;
                    fout <<"Thang: "<<khachhang[i].getNgaySinh().thang << endl;
                    fout <<"Nam: "<<khachhang[i].getNgaySinh().nam << endl; 
                    fout <<"Diem tich luy: " << khachhang[i].getDiemtichluy() << endl;
                    fout <<"Ngay: " <<khachhang[i].getNgaymua().ngay << endl;
                    fout <<"Thang: " <<khachhang[i].getNgaymua().thang << endl;
                    fout <<"Nam: " <<khachhang[i].getNgaymua().nam << endl;
                }
                fout.close();
                infile.close();
                break;
            } else {
                //Tạo file mới;
                ofstream outfile(f_txt);
                // Đóng file
                outfile.close();
            }
        }

    }
    void docFile(khachHangThuong khachhang[]){
        ifstream file(f_txt);
        if(file.is_open()){
            int n = kiemTraTxt();
            int sosanpham = n + 1;
            string line;
            int i = 0;
            while(n != 0 && i < n){
                getline(file,line);
                khachhang[i].setHovaTen(line.substr(11));
                getline(file,line);
                khachhang[i].setSoDienthoai(line.substr(15));
                getline(file,line);
                int ngay;
                ngay = stoi(line.substr(11));
                getline(file,line);
                int thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                int nam;
                nam = stoi(line.substr(5));
                khachhang[i].setNgaysinh(ngay, thang, nam);
                getline(file,line);
                khachhang[i].setDiemtichluy(stoi(line.substr(15)));
                getline(file,line);
                ngay;
                ngay = stoi(line.substr(6));
                getline(file,line);
                thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                nam;
                nam = stoi(line.substr(5));
                khachhang[i].setNgaymua(ngay, thang, nam);     
                i++;
            }
            file.close();
        }
    }
    int timKiem(khachHangThuong khachhang[], string sdt, int n){//Tìm kiếm sản phẩm nằm ở phần tử số bao nhiêu trong mảng sanpham[];
        for(int i = 0; i < n; i++){
            if(khachhang[i].getsoDienthoai() == sdt) return i;
        }
        return -1;
    }
    void Xoa(khachHangThuong khachhang[]){//Ham xoa thong tin
        int n = kiemTraTxt();
        cout << "Nhap so dien thoai de xoa thong tin khach hang can xoa! do dien thoai: ";
        string sdt;
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, sdt);
        int vitriXoa = timKiem(khachhang, sdt, n);
        for(int i = vitriXoa; i < n - 1; i++){
            khachhang[i] = khachhang[i+1];
        }
        cout << "Da xoa thanh cong!\n";
        int sokhach = n - 1;
        ghiFile(khachhang, sokhach);
        int choice;
    }
};
class khachHangVip : public nguoi{
    private:
    string ID;
    date ngayThamgia;
    float phanTramGiamgia;
    int diemTichLuy;
    date ngayMua;
    string noiO;
    float tongTien;
    public:
    khachHangVip(){};
    string getNoio(){
        return noiO;
    }
    string getIDkhachVip(){
        return ID;
    }
    date getNgaymua(){
        return ngayMua;
    }
    date getNgayThamgia(){
        return ngayThamgia;
    }
    float getPhantramGiamgia(){
        return phanTramGiamgia;
    }
    int getDiemtichluy(){
        return diemTichLuy;
    }
    void setIDkhachVip(){
        cout << "Nhap ID: ";
        getline(cin, ID);
    }
    void setIDkhachVip(string id){
        this->ID = id;
    }
    void setNgayThamgia(){
        cout << "Nhap ngay mua hang: ";
        cout << "Ngay: ";
        int ngay;
        cin >> ngay;
        cout << "Thang: ";
        int thang;
        cin >> thang;
        cout << "Nam :";
        int nam;
        cin >> nam;
        this -> ngayThamgia = date(ngay, thang, nam);
    }
    void setNgayThamgia(int ngay, int thang, int nam){
        this -> ngayThamgia = date(ngay, thang, nam);
    }
    void setPhantramGiamgia(){
        cout << "Nhap giam gia: ";
        cin >> phanTramGiamgia;
    }
    void setPhantramGiamgia(float ptgg){
        this->phanTramGiamgia = ptgg;
    }
    void setDiemtichluy(){
        cout << "Nhap so san pham da mua: ";
        cin >> diemTichLuy;
    }
    void setDiemtichluy(int dtl){
        this -> diemTichLuy = dtl;
    }
    void setNgaymua(){
        cout << "Nhap ngay mua hang: ";
        cout << "Ngay: ";
        int ngay;
        cin >> ngay;
        cout << "Thang: ";
        int thang;
        cin >> thang;
        cout << "Nam :";
        int nam;
        cin >> nam;
        this -> ngayMua = date(ngay, thang, nam);
    }
    void setNgaymua(int ngay, int thang, int nam){
        this -> ngayMua = date(ngay, thang, nam);
    }
    void setNoio(){
        cout << "Noi o";
        getline(cin, noiO);
    }
    void setThongtin(){
        cin.ignore();
        setIDkhachVip();
        cin.ignore();
        setHovaTen();
        setNgaysinh();
        cin.ignore();
        setSoDienthoai();
        setNgayThamgia();
        setPhantramGiamgia();
        setDiemtichluy();
        setNgaymua();

    }
    void chinhSua(khachHangVip khachhang[]){
        int n = kiemTraTxt();
        cout << "Nhap so ID de sua thong tin\n";
        string id;
        cin.ignore();
        getline(cin,id);
        int vitri = timKiem(khachhang, id, n);
        cout << "1. Chinh sua tat ca thong tin;\n";
        cout << "2. Chinh sua ID;\n";
        cout << "3. Chinh sua Ho va Ten;\n";
        cout << "4. Chinh sua ngay sinh;";
        cout << "5. Chinh sua so dien thoai;\n";
        cout << "6. Chinh sua ngay tham gia\n";
        cout << "7. Chinh sua pham tram giam gia;\n";
        cout << "8. Chinh sua diem tich luy.\n";
        cout << "Chon: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1: {
                setIDkhachVip();
                setHovaTen();
                setSoDienthoai();
                setNgayThamgia();
                setPhantramGiamgia();
                setDiemtichluy();
                break;
            }
            case 2:{
                setIDkhachVip();
                break;
            }
            case 3:{
                setHovaTen();
                break;
            }
            case 4:{
                setNgaysinh();
                break;
            }
            case 5:{
                setSoDienthoai();
                break;
            }
            case 6:{
                setNgayThamgia();
                break;
            }
            case 7:{
                setPhantramGiamgia();
                break;
            }
            case 8:{
                setDiemtichluy();
                break;
            }
            case 9:{
                setNgaymua();
            }
            default:
            break;
        }
    }
///////////////////////////////////////////////////////////////////////////////////////
    void thanhToan(khachHangVip khach[], myphamNoi list1[], myphamNgoai list2[]) {
        int slmpnoi = list1->kiemTraTxt();
        int slmpngoai = list2->kiemTraTxt(); 
        // cout << "slmpngoai " << slmpngoai << endl;
        int slkh = khach->kiemTraTxt();
        float total = 0;
        float giamgia = 0.95;// giam 5%
        int soLuong = 0;
        int thanhtien = 0;
        int exit = 0;
        if(slmpngoai == 0 && slmpnoi == 0){
            cout << "Hien tai cua hang chua co san pham nao!!!\n";
        }else if(slkh == 0){
            cout << "Hien tai cua hang chua co khach hang vip nao!!!\n";
        }
        if(slkh != 0){
            int error = 0;
            string iid;
            string mahang;
            cin.ignore();
            while(1){
                if(exit == 1) break;
                cout << "Nhap ID: ";
                getline(cin, iid);
                int vitri = timKiem(khach, iid, slkh);
                if(vitri == -1){
                    cout << "Khong tim thay khach hang!!!\n";
                }else{
                    cout << "Chao mung khach hang: " << khach[vitri].getHovaTen() << endl;
                    cout << "So dien thoai: " << khach[vitri].getsoDienthoai() << endl;
                    cout << "Diem tich luy: " << khach[vitri].getDiemtichluy() << endl;
                    while(1){
                        total = 0;
                        fflush(stdin);
                        cout << "Nhap ma hang: ";
                        getline(cin, mahang);
                        for(int i = 0; i < slmpnoi; i++){
                            if(mahang == list1[i].getMahang()){
                                cout << "San pham: " << list1[i].getTenHang() << endl;
                                cout <<" so luong : "<< list1[i].getSoluong() << endl;
                                cout <<" Gia tien : "<< list1[i].getTriGia() << endl;
                                if (list1[i].getSoluong() == 0){
                                    cout << "San pham da het hang!!!\n";
                                    break;
                                }
                                cout << "Nhap so luong muon mua: ";
                                cin >> soLuong;     
                                float giaBan = list1[i].getTriGia();
                                total += giaBan * soLuong;
                                list1[i].setSoluong(list1[i].getSoluong() - soLuong);
                                list1->ghiFile(list1, slmpnoi);
                                // break;
                            }
                        }
                        for(int i = 0; i < slmpngoai; i++){
                            if(mahang == list2[i].getMahang()){
                                cout << "San pham: " << list2[i].getTenHang() << endl;
                                cout <<" so luong : "<< list2[i].getSoluong() << endl;
                                cout <<" Gia tien : "<< list2[i].getTriGia() << endl;
                                if (list2[i].getSoluong() == 0){
                                    cout << "San pham da het hang!!!\n";
                                    break;
                                }
                                cout << "Nhap so luong muon mua: ";
                                cin >> soLuong;     
                                float giaBan = list2[i].getTriGia();
                                total += giaBan * soLuong;
                                list2[i].setSoluong(list2[i].getSoluong() - soLuong);
                                list2->ghiFile(list2, slmpngoai);
                                // break;
                            }
                        }
                        thanhtien = thanhtien + total*giamgia;
                        cout << "Nhap 0 de ket thuc thanh toan cho khach hang " << khach[vitri].getHovaTen()
                        << "\nNhap 1 de tiep tuc thanh toan\n";
                        int choice;
                        cin >> choice;
                        if (choice == 0) {
                            exit = 1;
                            if( thanhtien >= 500000 && thanhtien < 1000000){
                                giamgia  = 0.85; //giam 15%
                                cout << "Giam gia 15%\n";
                            }else if (thanhtien >= 1000000 && thanhtien < 2000000){
                                giamgia = 0.8 ;// giam 20%
                                cout << "Giam gia 20%\n";
                            }else if (thanhtien >= 2000000){
                                giamgia = 0.7; // giam 30%
                                cout << "Giam gia 30%\n";
                            }
                            cout << "Tong tien: " << thanhtien*giamgia <<" VND"<<endl;
                            ///////////////////
                            cout << "Nhan phim bat ky de ket thuc!!!";
                            cin.ignore();
                            cin.get();
                            ////////////////
                            break;// này là break vòng while hả// đsung k, ddr may
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
        }
    }
///////////////////////////////////////////////////////////////////////////////////////
    string f_txt = "data_khachhang_vip.txt";
    int kiemTraTxt(){//Kiểm tra file đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
        int n = 0;
        string line;
        ifstream file(f_txt);
        while(getline(file, line)){
            n++;
        }
        n = n/14;
        return n;
        file.close();
    }
    void ghiFile(khachHangVip khachhang[], int soluongkhachhang){
        // int n = kiemTraTxt();
        while(1){
            ifstream infile(f_txt);
            // Kiểm tra file có mở thành công hay không
            if (infile.is_open()) {
                // File tồn tại, thực hiện thao tác
                ofstream fout(f_txt);
                for(int i = 0; i < soluongkhachhang; i++){
                    fout <<"ID: "<< khachhang[i].getIDkhachVip()<<endl;
                    fout <<"Ho va ten: "<< khachhang[i].getHovaTen() << endl;
                    fout <<"So dien thoai: " << khachhang[i].getsoDienthoai() << endl;
                    fout <<"Ngay sinh: " <<khachhang[i].getNgaySinh().ngay << endl;
                    fout <<"Thang: " <<khachhang[i].getNgaySinh().thang << endl;
                    fout <<"Nam: " <<khachhang[i].getNgaySinh().nam << endl;
                    fout <<"Ngay tham gia: "<<khachhang[i].getNgayThamgia().ngay << endl;
                    fout <<"Thang: "<<khachhang[i].getNgayThamgia().thang << endl;
                    fout <<"Nam: "<<khachhang[i].getNgayThamgia().nam << endl; 
                    fout <<"Diem tich luy: " << khachhang[i].getDiemtichluy() << endl;
                    fout <<"Phan tram giam gia: " << khachhang[i].getPhantramGiamgia() << endl;
                    fout <<"Ngay: " <<khachhang[i].getNgaymua().ngay << endl;
                    fout <<"Thang: " <<khachhang[i].getNgaymua().thang << endl;
                    fout <<"Nam: " <<khachhang[i].getNgaymua().nam << endl;
                }
                fout.close();
                infile.close();
                break;
            } else {
                //Tạo file mới;
                ofstream outfile(f_txt);
                // Đóng file
                outfile.close();
            }
        }

    }
    void docFile(khachHangVip khachhang[]){
        ifstream file(f_txt);
        if(file.is_open()){
            int n = kiemTraTxt();
            int sosanpham = n + 1;
            string line;
            int i = 0;
            while(n != 0 && i < n){
                getline(file,line);
                khachhang[i].setIDkhachVip(line.substr(4));
                getline(file,line);
                khachhang[i].setHovaTen(line.substr(11));
                getline(file,line);
                khachhang[i].setSoDienthoai(line.substr(15));
                getline(file,line);
                int ngay;
                ngay = stoi(line.substr(11));
                getline(file,line);
                int thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                int nam;
                nam = stoi(line.substr(5));
                khachhang[i].setNgaysinh(ngay, thang, nam);
                getline(file,line);
                ngay;
                ngay = stoi(line.substr(15));
                getline(file,line);
                thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                nam;
                nam = stoi(line.substr(5));
                khachhang[i].setNgayThamgia(ngay, thang, nam);
                getline(file,line);
                khachhang[i].setDiemtichluy(stoi(line.substr(15)));
                getline(file,line);
                khachhang[i].setPhantramGiamgia(stoi(line.substr(20)));
                getline(file,line);
                ngay;
                ngay = stoi(line.substr(6));
                getline(file,line);
                thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                nam;
                nam = stoi(line.substr(5));
                khachhang[i].setNgaymua(ngay, thang, nam);
                i++;
            }
            file.close();
        }
    }
    int timKiem(khachHangVip khachhang[], string id, int n){//Tìm kiếm sản phẩm nằm ở phần tử số bao nhiêu trong mảng sanpham[];
        for(int i = 0; i < n; i++){
            if(khachhang[i].getIDkhachVip() == id) return i;
        }
        return -1;
    }
    void Xoa(khachHangVip khachhang[]){//Ham xoa thong tin
        int n = kiemTraTxt();
        cout << "Nhap ID de xoa thong tin khach hang can xoa! ID: ";
        string id;
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, id);
        int vitriXoa = timKiem(khachhang, id, n);
        for(int i = vitriXoa; i < n - 1; i++){
            khachhang[i] = khachhang[i+1];
        }
        cout << "Da xoa thanh cong!\n";
        int sokhach = n - 1;
        ghiFile(khachhang, sokhach);
        int choice;
    }
};
class nhanvien : public nguoi{
    string maNhanvien;
    string chucVu;
    string noiO;
    date ngayVaolam;
    float luong;
    public:
    nhanvien(){};
    void setNgayvaolam(){
        cout << "Nhap ngay vao lam: ";
        cout << "Ngay: ";
        int ngay;
        cin >> ngay;
        cout << "Thang: ";
        int thang;
        cin >> thang;
        cout << "Nam :";
        int nam;
        cin >> nam;
        this -> ngayVaolam = date(ngay, thang, nam);
    }
    void setNgayvaolam(int ngay, int thang, int nam){
        this -> ngayVaolam = date(ngay, thang, nam);
    }
    date getNgayvaolam(){
        return ngayVaolam;
    }
    string getMaNhanvien(){
        return maNhanvien;
    }
    string getChucvu(){
        return chucVu;
    }
    string getNoiO(){
        return noiO;
    }
    float getLuong(){
        return luong;
    }
    void setMaNhanvien(){
        cout << "Nhap ma: ";
        getline(cin, this->maNhanvien);
    }
    void setMaNhanvien(string mnv){
        this->maNhanvien = mnv;
    }
    void setChucvu(){
        cout << "Nhap chuc vu:";
        getline(cin, chucVu);
    }
    void setChucvu(string cv){
        this->chucVu = cv;
    }
    void setLuong(){
        cout << "Nhap luong: ";
        cin >> luong;
    }
    void setLuong(float luong){
        this->luong = luong;
    }
    void setNoio(){
        cout << "Nhap noi o: ";
        getline(cin, noiO);
    }
    void setNoio(string noio){
        this->noiO = noio;
    }
    void setThongtin(){
        cin.ignore();
        setMaNhanvien();
        setHovaTen();
        setNgaysinh();
        cin.ignore();
        setSoDienthoai();
        setChucvu();
        setNgayvaolam();
        cin.ignore();
        setNoio();
        setLuong();
    }
    string f_txt = "data_nhanvien.txt";
    int kiemTraTxt(){//Kiểm tra file đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
        int n = 0;
        string line;
        ifstream file(f_txt);
        while(getline(file, line)){
            n++;
        }
        n = n/12;
        return n;
        file.close();
    }
    void ghiFile(nhanvien nv[], int soluongnv){
        // int n = kiemTraTxt();
        while(1){
            ifstream infile(f_txt);
            // Kiểm tra file có mở thành công hay không
            if (infile.is_open()) {
                // File tồn tại, thực hiện thao tác
                ofstream fout(f_txt);
                for(int i = 0; i < soluongnv; i++){
                    fout << "Ma nhan vien: "<< nv[i].getMaNhanvien() << endl;
                    fout << "Ho va ten: "<<nv[i].getHovaTen() << endl;
                    fout << "So dien thoai: "<<nv[i].getsoDienthoai() <<endl;
                    fout << "Chuc vu: " << nv[i].getChucvu() <<endl;
                    fout << "Ngay sinh: "<<nv[i].getNgaySinh().ngay <<endl;
                    fout << "Thang: "<<nv[i].getNgaySinh().thang <<endl;
                    fout << "Nam: "<<nv[i].getNgaySinh().nam<<endl;
                    fout << "Noi o: "<<nv[i].getNoiO()<<endl;
                    fout << "Ngay tham gia: "<<nv[i].getNgayvaolam().ngay<<endl;
                    fout <<"Thang: "<<nv[i].getNgayvaolam().thang<<endl;
                    fout <<"Nam: "<<nv[i].getNgayvaolam().nam<<endl;
                    fout << "Luong: "<<nv[i].luong<<endl;
                }
                fout.close();
                infile.close();
                break;
            } else {
                //Tạo file mới;
                ofstream outfile(f_txt);
                // Đóng file
                outfile.close();
            }
        }

    }
    void docFile(nhanvien nv[]){
        ifstream file(f_txt);
        if(file.is_open()){
            int n = kiemTraTxt();
            int sosanpham = n + 1;
            string line;
            int i = 0;
            while(n != 0 && i < n){
                getline(file,line);
                nv[i].setMaNhanvien(line.substr(14));
                getline(file,line);
                nv[i].setHovaTen(line.substr(11));
                getline(file,line);
                nv[i].setSoDienthoai(line.substr(15));
                getline(file, line);
                nv[i].setChucvu(line.substr(9));
                getline(file,line);
                int ngay;
                ngay = stoi(line.substr(11));
                getline(file,line);
                int thang;
                thang = stoi(line.substr(7));
                getline(file,line);
                int nam;
                nam = stoi(line.substr(5));
                nv[i].setNgaysinh(ngay, thang, nam);
                getline(file,line);
                nv[i].setNoio(line.substr(7));
                getline(file,line);
                ngay = stoi(line.substr(15));
                getline(file,line);
                thang = stoi(line.substr(7));
                getline(file,line);
                nam = stoi(line.substr(5));
                nv[i].setNgayvaolam(ngay, thang, nam);
                getline(file,line);
                nv[i].setLuong(stof(line.substr(7)));
                i++;
            }
            file.close();
        }
    }
    int timKiem(nhanvien nv[], string mnv, int n){//Tìm kiếm sản phẩm nằm ở phần tử số bao nhiêu trong mảng sanpham[];
        for(int i = 0; i < n; i++){
            if(nv[i].getMaNhanvien() == mnv) return i;
            return -1;
        }
    }
    void Xoa(nhanvien nv[]){//Ham xoa thong tin
        int n = kiemTraTxt();
        cout << "Nhap ID de xoa thong tin khach hang can xoa! ID: ";
        string id;
        cin.ignore(); // Xóa bộ đệm đầu vào
        getline(cin, id);
        int vitriXoa = timKiem(nv, id, n);
        for(int i = vitriXoa; i < n - 1; i++){
            nv[i] = nv[i+1];
        }
        cout << "Da xoa thanh cong!\n";
        int sonhanvien = n - 1;
        ghiFile(nv, sonhanvien);
        int choice;
    }
    void chinhSua(nhanvien nv[]){
        int n = kiemTraTxt();
        cout << "Nhap so ma nhan vien de sua thong tin\n";
        string id;
        cin.ignore();
        getline(cin,id);
        int vitri = timKiem(nv, id, n);
        cout << "1. Chinh sua tat ca thong tin;\n";
        cout << "2. Chinh sua Ma nhan vien;\n";
        cout << "3. Chinh sua Ho va Ten;\n";
        cout << "4. Chinh sua ngay sinh;";
        cout << "5. Chinh sua so dien thoai;\n";
        cout << "6. Chinh sua chuc vu\n";
        cout << "7. Chinh sua ngay vao lam;\n";
        cout << "8. Chinh sua noi o;\n";
        cout << "9. Chinh sua luong;\n";
        cout << "Chon: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1: {
                setMaNhanvien();
                setHovaTen();
                setNgaysinh();
                setSoDienthoai();
                setChucvu();
                setNgayvaolam();
                setNoio();
                setLuong();
                break;
            }
            case 2:{
                setMaNhanvien();
                break;
            }
            case 3:{
                setHovaTen();
                break;
            }
            case 4:{
                setNgaysinh();
                break;
            }
            case 5:{
                setSoDienthoai();
                break;
            }
            case 6:{
                setChucvu();
                break;
            }
            case 7:{
                setNgayvaolam();
                break;
            }
            case 8:{
                setNoio();
                break;
            }
            case 9:{
                setLuong();
                break;
            }
            default:
            break;
        }
    }
};
void menuThemSp(myphamNoi list1[], myphamNgoai list2[]){
    int exit = 1;
    do{
        system("cls");
        cout << "1. Them my pham noi;\n" << "2. Them my pham ngoai.\n";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                list1[Soluong::myphamNoi].setThongtin();
                Soluong::myphamNoi++;
                list1->ghiFile(list1, Soluong::myphamNoi);
                break;
            }
            case 2:{
                list2[Soluong::myphamNgoai].setThongtin();
                Soluong::myphamNgoai++;
                list2->ghiFile(list2, Soluong::myphamNgoai);
                break;
            }
        } 
        cout << "Muon tiep tuc them ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
        cin >> exit;
    }while(exit == 1);
}
void menuXoaSp(myphamNoi list1[], myphamNgoai list2[]){
    int exit = 1;
    do{
        system("cls");
        cout << "1. Xoa my pham noi;\n" << "2. Xoa my pham ngoai.\n";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                list1[Soluong::myphamNoi].Xoa(list1);
                Soluong::myphamNoi--;
                list1->ghiFile(list1, Soluong::myphamNoi);
                break;
            }
            case 2:{
                list2[Soluong::myphamNgoai].Xoa(list2);
                Soluong::myphamNgoai--;
                list2->ghiFile(list2, Soluong::myphamNgoai);
                break;
            }
        } 
        cout << "Muon tiep tuc them ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
        cin >> exit;
    }while(exit == 1);
}
void xemTatcaSanpham(myphamNoi list1[], myphamNgoai list2[]){
    system("cls");
    if(Soluong::myphamNoi == 0 && Soluong::myphamNgoai == 0){
        cout << "Khong co san pham nao trong danh sach!";
    }else{
        for(int i = 0; i < Soluong::myphamNoi; i++){
            cout << "San pham noi dia " << i+1 << endl;
            cout << "Ma san pham: " << list1[i].getMahang() << endl;
            cout << "Ten san pham: " << list1[i].getTenHang() << endl;
            cout << "Tri gia: " << list1[i].getTriGia() << endl;
            cout << endl;
        }
        for(int i = 0; i < Soluong::myphamNgoai; i++){
            cout << "San pham ngoai dia " << i+1 << endl;
            cout << "Ma san pham: " << list2[i].getMahang() << endl;
            cout << "Ten san pham: " << list2[i].getTenHang() << endl;
            cout << "Tri gia: " << list2[i].getTriGia() << endl;
            cout << endl;
        }
    }
    cout << "Nhan phim bat ky de tiep tuc!";
    cin.ignore();
    cin.get();
}
void timKiemSanpham(myphamNoi list1[], myphamNgoai list2[]){
    system("cls");
    cout << "Nhap ma san pham can tim: ";
    string maHang;
    cin.ignore();
    getline(cin, maHang);
    int n1 = list1->kiemTraTxt();
    int n2 = list2->kiemTraTxt();
    if(n1 == 0 && n2 == 0){
        cout << "Khong tim thay san pham!";
    }else{
        if(n1 != 0){
            for(int i = 0; i < n1; i++){
                if(list1[i].getMahang() == maHang){
                    cout << "San pham thuoc my pham noi dia: " << endl;
                    cout << "Ma san pham: " << list1[i].getMahang() << endl;
                    cout << "Ten san pham: " << list1[i].getTenHang() << endl;
                    cout << "Tri gia: " << list1[i].getTriGia() << endl;
                    cout << "";
                    break;
                }
            }
        }
        if(n2 != 0){
            for(int i = 0; i < n2; i++){
                if(list2[i].getMahang() == maHang){
                    cout << "San pham thuoc my pham ngoai dia: " << endl;
                    cout << "Ma san pham: " << list2[i].getMahang() << endl;
                    cout << "Ten san pham: " << list2[i].getTenHang() << endl;
                    cout << "Tri gia: " << list2[i].getTriGia() << endl;
                    break;
                }
            }
        }
    }
    cout << "Nhan phim bat ky de tiep tuc!";
    cin.ignore();
    cin.get();

}
void menuChinhsuaSp(myphamNoi list1[], myphamNgoai list2[]){
    int exit = 1;
    do{
        system("cls");
        cout << "1. Xoa my pham noi;\n" << "2. Xoa my pham ngoai.\n";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                list1[Soluong::myphamNoi].Xoa(list1);
                Soluong::myphamNoi--;
                list1->ghiFile(list1, Soluong::myphamNoi);
                break;
            }
            case 2:{
                list2[Soluong::myphamNgoai].Xoa(list2);
                Soluong::myphamNgoai--;
                list2->ghiFile(list2, Soluong::myphamNgoai);
                break;
            }
        } 
        cout << "Muon tiep tuc them ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
        cin >> exit;
    }while(exit == 1);
}
void menuQuanlySp(myphamNoi list1[], myphamNgoai list2[]){
    system("cls");
    cout << "--------Menu Quan ly san pham------\n";
    cout << "|1. Them san pham;\t\t  |\n" 
    << "|2. Xoa san pham;\t\t  |\n" 
    << "|3. Chinh sua san pham;\t\t  |\n"
    << "|4. Xem thong tin tat ca san pham;|\n"
    << "|5. Tim kiem san pham;\t\t  |\n"
    << "|0. Thoat\t\t\t  |\n"
    <<"-----------------------------------\n"
    <<"Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            menuThemSp(list1, list2);
            break;
        }
        case 2:{
            menuXoaSp(list1, list2);
            break;
        }
        case 3:{
            menuChinhsuaSp(list1, list2);
            break;
        }
        case 4:{
            xemTatcaSanpham(list1, list2);
            break;
        }
        case 5:{
            timKiemSanpham(list1, list2);
            break;
        }
        case 0:{
            break;
        }
        default:
        break;
    }
}
void menuThanhtoanKhachVip(myphamNoi list1[], myphamNgoai list2[], 
khachHangVip nguoimua[]){
    nguoimua->thanhToan(nguoimua , list1, list2);
}
void menuThanhtoanKhachthuong(myphamNoi list1[], 
myphamNgoai list2[], khachHangThuong nguoimua[]){
    nguoimua->thanhToan(nguoimua, list1, list2);
}
void menuThanhtoan(myphamNoi list1[], myphamNgoai list2[], 
khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    system("cls");
    cout <<"--------------Menu Thanh toan--------------\n";
    cout << "|1. Thanh toan danh cho Khach hang Vip;   |\n"
    <<"|2. Thanh toan danh cho Khach hang thuong.|\n"
    <<"|0. Thoat\t\t\t\t  |\n"
    <<"-------------------------------------------\n"
    <<"Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            menuThanhtoanKhachVip(list1, list2, nguoimua2);
            break;
        }
        case 2:{
            menuThanhtoanKhachthuong(list1, list2, nguoimua1);
            break;
        }
        case 3:{
            break;
        }
        default:
        break;
    }
}
void xemThongTinTatCaNhanvien(nhanvien nv[]){
    if(nv->kiemTraTxt() == 0){
        cout << "Khong co nhan vien nao trong danh sach!";
    }else{
        for(int i = 0; i < Soluong::Nhanvien; i++){
            cout << "Nhan vien thu " << i+1 << endl;
            cout << "Ma nhan vien: " << nv[i].getMaNhanvien() << endl;
            cout << "Ho va ten: " << nv[i].getHovaTen() << endl;
            cout << "Nam sinh " << nv[i].getNgaySinh().nam << endl;
            cout << "Chuc vu: " << nv[i].getChucvu() << endl;
            cout << "Ngay vao lam:  " << nv[i].getNgayvaolam().ngay <<"/"<< nv[i].getNgayvaolam().thang << "/" <<nv[i].getNgayvaolam().nam << endl;
            cout << endl;
        }
    }
    cout << "Nhan phim bat ky de tiep tuc!";
    cin.ignore();
    cin.get();
}
void timKiemnhanvien(nhanvien nv[]){
    string id;
    cout << "Nhap ma nhan vien can tim: ";
    cin.ignore();
    getline(cin, id);
    int n = nv->kiemTraTxt();
    int vitri = nv->timKiem(nv, id, n);
    cout << "Ma nhan vien: " << nv[vitri].getMaNhanvien() << endl;
    cout << "Ho va ten: " << nv[vitri].getHovaTen() << endl;
    cout << "Ngay sinh " << nv[vitri].getNgaySinh().nam <<"/"<< nv[vitri].getNgaySinh().thang <<"/"<< nv[vitri].getNgaySinh().ngay << endl;
    cout << "Chuc vu: " << nv[vitri].getChucvu() << endl;
    cout << "Noi o: " << nv[vitri].getNoiO() << endl;
    cout << "Ngay vao lam:  " << nv[vitri].getNgayvaolam().ngay <<"/"<< nv[vitri].getNgayvaolam().thang << "/" <<nv[vitri].getNgayvaolam().nam << endl;
    cout << "Luong: " << nv[vitri].getLuong() << endl;
    cout << "-----------------------------------\n";
}
void menuQuanlyNhanvien(nhanvien nv[]){
    system("cls");
    int exit = 1;
    cout << "------Menu Quan ly nhan vien------\n";
    cout << "|1. Them thong tin nhan vien;\t  |\n" 
    << "|2. Xoa thong tin nhan vien;\t  |\n" 
    << "|3. Chinh sua thong tin nhan vien.|\n"
    << "|4. Xem thong tin tat ca nhan vien|\n"
    << "|5. Tim kiem nhan vien;\t\t  |\n"
    <<"|0. Thoat\t\t\t  |\n"
    <<"----------------------------------\n"
    <<"Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            do{
                nv[Soluong::Nhanvien].setThongtin();
                Soluong::Nhanvien++;
                nv->ghiFile(nv, Soluong::Nhanvien);
                cout << "Muon tiep tuc them ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
                cin >> exit;
            }while(exit == 1);
            break;
        }
        case 2:{
            do{
                nv[Soluong::Nhanvien].Xoa(nv);
                Soluong::Nhanvien--;
                nv->ghiFile(nv, Soluong::Nhanvien);
                cout << "Muon tiep tuc xoa ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
                cin >> exit;
            }while(exit == 1);
            break;
        }
        case 3:{
            do{
                nv[Soluong::Nhanvien].chinhSua(nv);
                cout << "Muon tiep tuc sua ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
                cin >> exit;
            }while(exit == 1);
            break;
        }
        case 4:{
            xemThongTinTatCaNhanvien(nv);
            break;
        }
        case 5:{
            do{
                timKiemnhanvien(nv);
                cout << "Muon tiep tuc kiem ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
                cin >> exit;
            }while(exit == 1);
            break;
        }
        case 0:{
            break;
        }
        default:
        break;
    }
}
void menuThemKh(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int exit = 1;
    do{
        system("cls");
        cout << "1. Them khach hang thuong;\n" << "2. Them khach hang vip.\n";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                nguoimua1[Soluong::KhachThuong].setThongtin();
                Soluong::KhachThuong++;
                nguoimua1->ghiFile(nguoimua1, Soluong::KhachThuong);
                break;
            }
            case 2:{
                nguoimua2[Soluong::KhachVip].setThongtin();
                Soluong::KhachVip++;
                nguoimua2->ghiFile(nguoimua2, Soluong::KhachVip);
                break;
            }
        } 
        cout << "Muon tiep tuc them ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
        cin >> exit;
    }while(exit == 1);
}
void menuXoaKh(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int exit;
    do{
        system("cls");
        cout << "1. Xoa thong tin khach hang thuong;\n" << "2. Xoa thong tin khach hang vip.\n";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                nguoimua1[Soluong::KhachThuong].Xoa(nguoimua1);
                Soluong::KhachThuong--;
                nguoimua1->ghiFile(nguoimua1, Soluong::KhachThuong);
                break;
            }
            case 2:{
                nguoimua2[Soluong::KhachVip].Xoa(nguoimua2);
                Soluong::KhachVip--;
                nguoimua2->ghiFile(nguoimua2, Soluong::KhachVip);
                break;
            }
        } 
        cout << "Muon tiep tuc xoa ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
        cin >> exit;
    }while(exit == 1);
}
void menuChinhsuaKh(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int exit;
    do{
        system("cls");
        cout << "1. Chinh sua thong tin khach hang thuong;\n" << "2. Chinh sua thong tin khach hang vip.\n";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:{
                nguoimua1[Soluong::KhachThuong].chinhSua(nguoimua1);
                nguoimua1->ghiFile(nguoimua1, Soluong::KhachThuong);
                break;
            }
            case 2:{
                nguoimua2[Soluong::KhachVip].chinhSua(nguoimua2);
                nguoimua2->ghiFile(nguoimua2, Soluong::KhachVip);
                break;
            }
        } 
        cout << "Muon tiep tuc xoa ?\n" << "Chon 0 de exit, 1 de tiep tuc: ";
        cin >> exit;
    }while(exit == 1);
}
void xemThongtintatcaKhachhang(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    if(nguoimua1->kiemTraTxt() == 0 && nguoimua2->kiemTraTxt() == 0){
        cout << "Khong co khach hang nao trong danh sach!";
    }else{
        if(nguoimua1->kiemTraTxt()!=0){
            for(int i = 0; i < Soluong::KhachThuong; i++){
                cout << "Khach hang" << i + 1 << endl;
                cout << "Ho va ten: " << nguoimua1[i].getHovaTen() << endl;
                cout << "So dien thoai: " << nguoimua1[i].getsoDienthoai() << endl;
                cout << "Ngay sinh: " << nguoimua1[i].getNgaySinh().ngay << "/" << nguoimua1[i].getNgaySinh().thang << "/" << nguoimua1[i].getNgaySinh().nam << endl;
                cout << "Ngay mua gan nhat: " << nguoimua1[i].getNgaymua().ngay << "/" << nguoimua1[i].getNgaymua().thang << "/" << nguoimua1[i].getNgaymua().nam << endl;
                cout << endl;
            }
        }
        if(nguoimua2->kiemTraTxt()!=0){
            for(int i = 0; i < Soluong::KhachVip; i++){
                cout << "khach vip" << i + 1 << "\n";
                cout << "ID: " << nguoimua2[i].getIDkhachVip() << endl;
                cout << "Ho va ten: " << nguoimua2[i].getHovaTen() << endl;
                cout << "So dien thoai: " << nguoimua2[i].getsoDienthoai() << endl;
                cout << "Ngay sinh: " << nguoimua2[i].getNgaySinh().ngay << "/" << nguoimua2[i].getNgaySinh().thang << "/" << nguoimua2[i].getNgaySinh().nam << endl;
                cout << "Ngay mua gan nhat: " << nguoimua2[i].getNgaymua().ngay << "/" << nguoimua2[i].getNgaymua().thang << "/" << nguoimua2[i].getNgaymua().nam << endl;
                cout << endl;
            }
        }
    }
    cout << "Nhan phim bat ky de tiep tuc!";
    cin.ignore();
    cin.get();
}
void timKiemKhachhang(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int choice;
    cout << "1. Nhap ID \n" 
    <<"2. So dien thoai\n";
    cin >> choice;
    switch(choice){
        case 1:{
            string id;
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, id);
            int n = nguoimua2->kiemTraTxt();
            if(n == 0){
                cout << "Khong co khach hang nao trong danh sach!\n";
                cout << "Thu nhap so dien thoai de tim kiem\n";
            }else{
                int vitri = nguoimua2->timKiem(nguoimua2, id, n);
                if(vitri != -1){
                    cout << "ID: " << nguoimua2[vitri].getIDkhachVip() << endl;
                    cout << "Ho va ten: " << nguoimua2[vitri].getHovaTen() << endl;
                    cout << "So dien thoai: " << nguoimua2[vitri].getsoDienthoai() << endl;
                    cout << "Ngay sinh: " << nguoimua2[vitri].getNgaySinh().ngay << "/" << nguoimua2[vitri].getNgaySinh().thang << "/" << nguoimua2[vitri].getNgaySinh().nam << endl;
                    cout << "Ngay mua gan nhat: " << nguoimua2[vitri].getNgaymua().ngay << "/" << nguoimua2[vitri].getNgaymua().thang << "/" << nguoimua2[vitri].getNgaymua().nam << endl;
                    cout << "Diem tich luy: " << nguoimua2[vitri].getDiemtichluy() << endl;
                    cout << "Phan tram giam gia: " << nguoimua2[vitri].getPhantramGiamgia() << endl;
                    cout << "Loai the VIP \n";
                }
                else{
                    cout << "Khong tim thay khach hang!\n";
                    cout << "Thu nhap so dien thoai de tim kiem";
                }
            }
            
            break;
        }
        case 2:{
            string sdt;
            cout << "Nhap so dien thoai: ";
            cin.ignore();
            getline(cin, sdt);
            int n = nguoimua1->kiemTraTxt();
            if(n == 0){
                cout << "Khong co khach hang nao trong danh sach!\n";
                cout << "Thu nhap ID de tim kiem\n";
            }else{
                int vitri = nguoimua1->timKiem(nguoimua1, sdt, n);
                cout << "Ho va ten: " << nguoimua1[vitri].getHovaTen() << endl;
                cout << "So dien thoai: " << nguoimua1[vitri].getsoDienthoai() << endl;
                cout << "Ngay sinh: " << nguoimua1[vitri].getNgaySinh().ngay << "/" << nguoimua1[vitri].getNgaySinh().thang << "/" << nguoimua1[vitri].getNgaySinh().nam << endl;
                cout << "Ngay mua gan nhat: " << nguoimua1[vitri].getNgaymua().ngay << "/" << nguoimua1[vitri].getNgaymua().thang << "/" << nguoimua1[vitri].getNgaymua().nam << endl;
                cout << "Diem tich luy: " << nguoimua1[vitri].getDiemtichluy() << endl;
                cout << "Loai the thuong\n";

            }
        }
    }
    cout << "Nhan phim bat ky de tiep tuc!";
    cin.ignore();
    cin.get();
    
}
void menuQuanlyKhachhang(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    system("cls");
    cout <<"-----Menu Quan ly khach hang---------\n";
    cout << "|1. Them thong tin khach hang;\t    |\n" 
    << "|2. Xoa thong tin khach hang;\t    |\n" 
    << "|3. Chinh sua thong tin khach hang; |\n"
    << "|4. Xem thong tin tat ca khach hang;|\n"
    << "|5. Tim kiem khach hang;\t    |\n"
    << "|0. Thoat\t\t\t    |\n"
    <<"-------------------------------------\n"
    <<"Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{
            menuThemKh(nguoimua1, nguoimua2);
            break;
        }
        case 2:{
            menuXoaKh(nguoimua1, nguoimua2);
            break;
        }
        case 3:{
            menuChinhsuaKh(nguoimua1, nguoimua2);
            break;
        }
        case 4:{
            xemThongtintatcaKhachhang(nguoimua1, nguoimua2);
            break;
        }
        case 5:{
            timKiemKhachhang(nguoimua1, nguoimua2);
            break;
        }
        case 0:{
            break;  
        }
    }
}
int menu(myphamNoi list1[], myphamNgoai list2[], 
khachHangThuong nguoimua1[], khachHangVip nguoimua2[], nhanvien nv[]){
    system("cls");
    cout << "---------------Menu---------------\n";
    int choice;
    cout << "|1. Thanh toan;\t\t\t |\n"
        << "|2. Quan ly danh sach my pham;\t |\n"
        << "|3. Quan ly danh sach nhan vien; |\n"
        << "|4. Quan ly danh sach khach hang;|\n"
        << "|0. De thoat.\t\t\t |\n";
    cout << "----------------------------------\n";
    cout <<"Chon: ";
    fflush(stdin);
    cin >> choice;
    switch(choice){
        case 1:
        menuThanhtoan(list1, list2, nguoimua1, nguoimua2);
        return 1;
        break;
        case 2:
        menuQuanlySp(list1, list2);
        return 1;
        break;
        case 3:
        menuQuanlyNhanvien(nv);
        return 1;
        break;
        case 4:
        menuQuanlyKhachhang(nguoimua1, nguoimua2);
        return 1;
        break;
        case 0:
        return 0;
        default:
        break;
    }
    list1->ghiFile(list1, Soluong::myphamNoi);
    list2->ghiFile(list2, Soluong::myphamNgoai);
    nguoimua1->ghiFile(nguoimua1, Soluong::KhachThuong);
    nguoimua2->ghiFile(nguoimua2, Soluong::KhachVip);
    nv->ghiFile(nv, Soluong::Nhanvien);
}
int main(){
    khachHangThuong* nguoimua1 = new khachHangThuong[50];
    khachHangVip* nguoimua2 = new khachHangVip[50];
    myphamNoi* list1 = new myphamNoi[50];
    myphamNgoai* list2 = new myphamNgoai[50];
    nhanvien* nv = new nhanvien[50];
    list1->docFile(list1);
    list2->docFile(list2);
    nguoimua1->docFile(nguoimua1);
    nguoimua2->docFile(nguoimua2);
    nv->docFile(nv);
    Soluong::myphamNoi = list1->kiemTraTxt();
    Soluong::myphamNgoai = list2->kiemTraTxt();
    Soluong::KhachThuong = nguoimua1->kiemTraTxt();
    Soluong::KhachVip = nguoimua2->kiemTraTxt();
    Soluong::Nhanvien = nv->kiemTraTxt();
    while(1){
        if(menu(list1, list2, nguoimua1, nguoimua2, nv) == 0){
            break;
        }
    }
    return 0;
}