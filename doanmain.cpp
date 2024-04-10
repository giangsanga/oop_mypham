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
    int soHangdaMua;
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
    void setSoHangdaMua(){
        cout << "Nhap so hang da mua: ";
        cin >> soHangdaMua;
    }
    void setSoHangdaMua(int shdm){
        this->soHangdaMua = shdm;
    }
    date getNgaymua(){
        return ngayMua;
    }
    int getSoHangdaMua(){
        return soHangdaMua;
    }
    void setThongtin(){
        cin.ignore();
        setHovaTen();
        setNgaysinh();
        cin.ignore();
        setSoDienthoai();
        setNgaymua();
        setSoHangdaMua();
    }
    void chinhSua(){
        cout << "1. Chinh sua tat ca thong tin;\n";
        cout << "2. Chinh sua Ho va Ten;\n";
        cout << "3. Chinh sua ngay sinh\n";
        cout << "4. Chinh sua so dien thoai;\n";
        cout << "5. Chinh sua so san pham da mua;\n";
        cout << "6. Ngay mua gan nhat.\n";
        cout << "Chon: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1: {
                setHovaTen();
                setSoDienthoai();
                setSoHangdaMua();
                break;
            }
            case 2:{
                setHovaTen();
                break;
            }
            case 3:{
                setNgaysinh();
            }
            case 4:{
                setSoDienthoai();
                break;
            }
            case 5:{
                setSoHangdaMua();
                break;
            }
            case 6:{
                setNgaymua();
            }
            default:
            break;
        }
    }
    float thanhToan(float giatri, int soluong){
        return giatri = giatri*soluong*(1);
    }
    float thanhToan(myphamNoi list1[], myphamNgoai list2[], int n1, int n2) {
        float total = 0;
        while (1) {
            cout << "Nhap ma hang: ";
            string maHang;
            cin.ignore();
            getline(cin, maHang);
            cout << "Nhap so luong: ";
            int soLuong;
            cin >> soLuong;
            // Check if the product is in the local cosmetics list
            for (int i = 0; i < n1; i++) {
                if (list1[i].getMahang() == maHang) {
                    float giaBan = list1[i].getTriGia();
                    total += giaBan * soLuong;
                    break;
                }
            }

            // Check if the product is in the imported cosmetics list
            for (int i = 0; i < n2; i++) {
                if (list2[i].getMahang() == maHang) {
                    float giaBan = list2[i].getTriGia();
                    float thueNhapKhau = list2[i].getThueNhapkhau();
                    giaBan += giaBan * thueNhapKhau;
                    total += giaBan * soLuong;
                    break;
                }
            }
            cout << "Nhap 0 de ket thuc thanh toan, nhap 1 de tiep tuc: ";
            int choice;
            cin >> choice;
            if (choice == 0) {
                break;
            }
        }
        return total;
    }
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
                    fout <<"So san pham da mua " << khachhang[i].getSoHangdaMua() << endl;
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
                khachhang[i].setSoHangdaMua(stoi(line.substr(19)));
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
};
class khachHangVip : public nguoi{
    private:
    string ID;
    date ngayThamgia;
    float phanTramGiamgia;
    int soSanphamdaMua;
    date ngayMua;
    string noiO;
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
    int getSoSanphamdaMua(){
        return soSanphamdaMua;
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
    void setSoSanphamdaMua(){
        cout << "Nhap so san pham da mua: ";
        cin >> soSanphamdaMua;
    }
    void setSoSanphamdaMua(int sspdm){
        this -> soSanphamdaMua = sspdm;
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
    }
    void setThongtin(){
        cin.ignore();
        setIDkhachVip();
        setHovaTen();
        setNgaysinh();
        cin.ignore();
        setSoDienthoai();
        setNgayThamgia();
        setPhantramGiamgia();
        setSoSanphamdaMua();
        setNgaymua();
    }
    void chinhSua(){
        cout << "1. Chinh sua tat ca thong tin;\n";
        cout << "2. Chinh sua ID;\n";
        cout << "3. Chinh sua Ho va Ten;\n";
        cout << "4. Chinh sua ngay sinh;";
        cout << "5. Chinh sua so dien thoai;\n";
        cout << "6. Chinh sua ngay tham gia\n";
        cout << "7. Chinh sua pham tram giam gia;\n";
        cout << "8. Chinh sua so san pham da mua.\n";
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
                setSoSanphamdaMua();
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
                setSoSanphamdaMua();
                break;
            }
            case 9:{
                setNgaymua();
            }
            default:
            break;
        }
    }
    float thanhToan(float giatri, int soluong){
        return giatri = giatri*soluong*(1-getPhantramGiamgia());
    }
    float thanhToan(myphamNoi list1[], myphamNgoai list2[], int n1, int n2) {
        float total = 0;
        while (1) {
            cout << "Nhap ma hang: ";
            string maHang;
            cin.ignore();
            getline(cin, maHang);
            cout << "Nhap so luong: ";
            int soLuong;
            cin >> soLuong;
            // Check if the product is in the local cosmetics list
            for (int i = 0; i < n1; i++) {
                if (list1[i].getMahang() == maHang) {
                    total += list1[i].getTriGia() * soLuong * (1 - getPhantramGiamgia());
                    break;
                }
            }
            // Check if the product is in the imported cosmetics list
            for (int i = 0; i < n2; i++) {
                if (list2[i].getMahang() == maHang) {
                    total += list2[i].getTriGia() * soLuong * (1 - getPhantramGiamgia());
                    break;
                }
            }
            cout << "Nhap 0 de ket thuc thanh toan, nhap 1 de tiep tuc: ";
            int choice;
            cin >> choice;
            if (choice == 0) {
                break;
            }
        }
        return total;
    }
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
                //         setIDkhachVip();
            // setHovaTen();
            // setNgaysinh();
            // setSoDienthoai();
            // setNgayThamgia();
            // setPhantramGiamgia();
            // setSoSanphamdaMua();
            // setNgaymua();
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
                    fout <<"So san pham da mua: " << khachhang[i].getSoSanphamdaMua() << endl;
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
                khachhang[i].setSoSanphamdaMua(stoi(line.substr(20)));
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
        this -> ngayVaolam = date(ngay, thang, nam);
    }
    void setNgayvaolam(int ngay, int thang, int nam){
        this -> ngayVaolam = date(ngay, thang, nam);
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
};
class quanly : public nhanvien{
    
};
int timSanpham(string maHang, myphamNoi list1[],
 myphamNgoai list2[], int n1, int n2, string& nguonGoc) {// Tìm sản phẩm thuộc mỹ phẩm nội hay ngoại, thông qua mã hàng;
    //trả ra vị trí i phần tử + ma (nguồn gốc), với ma là chuỗi string;
    for(int i = 0; i < n1; i++){
        if(list1[i].getMahang() == maHang){
            nguonGoc = "myphamNoi";
            return i;
        }
    }
    for(int i = 0; i < n2; i++){
        if(list2[i].getMahang() == maHang){
            nguonGoc = "myphamNgoai";
            return i;
        }
    }
    cout << "Khong tim thay Hang";
    return 0;
}
int timKhachhangVip(string ID, khachHangVip nguoi[], int n){// Tìm thông tin khách hàng Vip, thông qua ID;
//Trả ra vị trí i phần tử trong mảng nguoi[];
    for(int i = 0; i < n; i++){
        if(nguoi[i].getIDkhachVip() == ID){
            return i;
        }
    }
}
void menuThemSp(myphamNoi list1[], myphamNgoai list2[]){
    int exit = 1;
    do{
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

}
void menuChinhsuaSp(myphamNoi list1[], myphamNgoai list2[]){

}
void menuQuanlySp(myphamNoi list1[], myphamNgoai list2[]){
    cout << "1. Them san pham;\n" 
    << "2. Xoa san pham;\n" 
    << "3. Chinh sua san pham.\n"
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
    }
}
void menuThanhtoanKhachVip(myphamNoi list1[], myphamNgoai list2[], khachHangVip nguoimua[]){
    cout << "Nhap ID:";
    cin.ignore();
    string ID;
    getline(cin, ID);
    // cout << ID\n;
    timKhachhangVip(ID, nguoimua, Soluong::KhachVip);
}
void menuThanhtoanKhachthuong(myphamNoi list1[], 
myphamNgoai list2[], khachHangThuong nguoimua[]){

}
void menuThanhtoan(myphamNoi list1[], myphamNgoai list2[], 
khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    cout <<"----------------------Menu Thanh toan-----------------------------\n";
    cout << "1. Thanh toan danh cho Khach hang Vip;\n"
    <<"2. Thanh toan danh cho Khach hang thuong.\n"
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
    }
}
// void xemThongTinTatCaSanpham(myphamNoi list1[], myphamNgoai list2[]){

// }
void menuQuanlyNhanvien(nhanvien nv[]){

}
void menuThemKh(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int exit = 1;
    do{
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

}
void menuChinhsuaKh(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){

}
void menuQuanlyKhachhang(khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    cout << "1. Them thong tin khach hang;\n" 
    << "2. Xoa thong tin khach hang;\n" 
    << "3. Chinh sua thong tin khach hang.\n"
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
    }
}
int menu(myphamNoi list1[], myphamNgoai list2[], 
khachHangThuong nguoimua1[], khachHangVip nguoimua2[], nhanvien nv[]){
    cout << "------------------------Menu------------------------------\n";
    int choice;
    cout << "1. Thanh toan;\n" 
    << "2. Quan ly danh sach my pham;\n" 
    <<"3. Quan ly danh sach nhan vien;\n"
    <<"4. Quan ly danh sach khach hang\n"
    <<"0. De thoat.\n"
    <<"Chon: ";
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
    // nv->docFile(nv);
    // Soluong::Nhanvien = nv->kiemTraTxt();
    Soluong::KhachVip = nguoimua2->kiemTraTxt();
    Soluong::KhachThuong = nguoimua1->kiemTraTxt();
    Soluong::myphamNoi = list1->kiemTraTxt();
    Soluong::myphamNgoai = list2->kiemTraTxt();
    // list1[0].setMaHang("ma hang");
    // list1[0].setTenHang("ten hang");
    // list1[0].setCongDung("cong dung");
    // list1[0].setSoluong(3330);
    // list1[0].setTrigia(333.333);
    // list1[0].setNgayNhapHang(3,3,3);
    // Soluong::myphamNoi = Soluong::myphamNoi + 1;
    // list1[1].setMaHang("ma hang1");
    // list1[1].setTenHang("ten hang1");
    // list1[1].setCongDung("cong dung1");
    // list1[1].setSoluong(33301);
    // list1[1].setTrigia(333.331);
    // list1[1].setNgayNhapHang(3,3,3);
    // Soluong::myphamNoi = Soluong::myphamNoi + 1;
    // list1[2].setMaHang("ma hang1");
    // list1[2].setTenHang("ten hang1");
    // list1[2].setCongDung("cong dung1");
    // list1[2].setSoluong(33301);
    // list1[2].setTrigia(333.331);
    // list1[2].setNgayNhapHang(3,3,3);
    // Soluong::myphamNoi = Soluong::myphamNoi + 1;
    // list1->ghiFile(list1, Soluong::myphamNoi);
    // cout << Soluong::myphamNoi <<endl;
    while(1){
        if(menu(list1, list2, nguoimua1, nguoimua2, nv) == 0){
            break;
        }
    }
    return 0;
}