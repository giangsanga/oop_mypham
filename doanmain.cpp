#include <iostream>
#include <string>
#include <fstream>
using namespace std;
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
        cin.ignore(); // Xóa bộ đệm đầu vào
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
        setMaHang();
        setTenHang();
        setCongDung();
        setTrigia();
        setSoluong();
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
        cout << "1. Tat ca;\n"<< "2. Ma hang;\n" << "3. Ten hang;\n" << "4. Cong dung;\n" << "5. Tri gia;\n" << "6. So luong.\n";
        cout << "Chon: ";
        cin >> choice;
        switch(choice){
            case 1:{
                setMaHang();
                setTenHang();
                setCongDung();
                setTrigia();
                setSoluong();
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
            default:
            break;
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
        setMaHang();
        setTenHang();
        setCongDung();
        setTrigia();
        setSoluong();
        setThueNhapkhau();
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
        cout << "1. Tat ca;\n"<< "2. Ma hang;\n" << "3. Ten hang;\n"<< "4. Nguon goc;\n" << "5. Cong dung;\n" << "6. Tri gia;\n" << "7. So luong.\n" <<"8. Thue.\n";
        cout << "Chon: ";
        cin >> choice;
        switch(choice){
            case 1:{
                // std::cout << "Ma hang: ";
                // cin.ignore(); // Xóa bộ đệm đầu vào
                // getline(cin, maHang);
                // cout << "Ten hang: ";
                // cin.ignore();
                // getline(cin, tenHang);
                // cout << "Nguon goc: ";
                // string ng_goc;
                // getline(cin, ng_goc);
                // setNguonGoc(ng_goc);
                // cout << "Cong dung: ";
                // cin.ignore();
                // getline(cin, congDung);
                // cout << "Tri gia (VND): " ;
                // fflush(stdin);
                // cin >> triGia;
                // cout << "So luong: ";
                // cin >> soLuong;
                setMaHang();
                setTenHang();
                setNguongoc();
                setCongDung();
                setTrigia();
                setSoluong();
                setThueNhapkhau();
                break;
            }
            case 2:{
                // cout << "Ma hang: ";
                // cin.ignore();
                // getline(cin, maHang);
                setMaHang();
                break;
            }
            case 3:{
                // cout << "Ten hang: ";
                // cin.ignore();
                // getline(cin, tenHang);
                setTenHang();
                break;
            }
            case 4:{
                // cout << "Nguon goc: ";
                // string ng_goc;
                // cin.ignore(); 
                // getline(cin, ng_goc);
                // setNguonGoc(ng_goc);
                setNguongoc();
                break;
            }
            case 5:{
                // cout << "Cong dung: ";
                // cin.ignore(); 
                // getline(cin,congDung);
                setCongDung();
                break;
            }
            case 6:{
                // cout << "Tri gia: VND" ;
                // fflush(stdin);
                // cin >> triGia;
                setTrigia();
                break;
            }
            case 7:{
                // cout << "So luong: ";
                // fflush(stdin);
                // cin >> soLuong;
                setSoluong();
                break;
            }
            case 8:{
                setThueNhapkhau();
                break;
            }
            default:
            break;
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
    void chinhSua(){
        cout << "1. Chinh sua tat ca thong tin;\n";
        cout << "2. Chinh sua Ho va Ten;\n";
        cout << "3. Chinh sua so dien thoai;\n";
        // cout << "4. Chinh sua ngay tham gia\n";
        // cout << "5. Chinh sua pham tram giam gia;\n";
        cout << "4. Chinh sua so san pham da mua.\n";
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
                setSoDienthoai();
                break;
            }
            case 4:{
                setSoHangdaMua();
                break;
            }
            default:
            break;
        }
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
};
class khachHangVip : public nguoi{
    private:
    string ID;
    date ngayThamgia;
    float phanTramGiamgia;
    int soSanphamdaMua;
    public:
    khachHangVip(){};
    string getIDkhachVip(){
        return ID;
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
    void chinhSua(){
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
                setHovaTen();
                setSoDienthoai();
                setNgayThamgia();
                setNgayThamgia();
                setPhantramGiamgia();
                setSoSanphamdaMua();
                break;
            }
            case 2:{
                setHovaTen();
                break;
            }
            case 3:{
                setSoDienthoai();
                break;
            }
            case 4:{
                setNgayThamgia();
                break;
            }
            case 5:{
                setPhantramGiamgia();
                break;
            }
            case 6:{
                setSoSanphamdaMua();
                break;
            }
        }
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
};
class nhanvien : public nguoi{
    string maNhanvien;
    string chucVu;
    string noiO;
    float luong;
    public:
    nhanvien(){};
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
int checkSanpham(string maHang, myphamNoi list1[], myphamNgoai list2[], int n1, int n2) {
    for(int i = 0; i < n1; i++){
        if(list1[i].getMahang() == maHang){
            return i;
        }
    }
}
int kiemTraSoSanpham(string f_txt){//Kiểm tra mảng sanpham đã chứa bao nhiêu sản phẩm, f_txt <- data.txt;
    int n = 0;
    string line;
    ifstream file(f_txt);
    while(getline(file, line)){
        n++;
    }
    n = n/7;
    return n;
}

void setUp(myphamNoi list1[], myphamNgoai list2[], khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    cout << "1. Them san pham;\n" << "2. Xoa san pham;\n" << "3. Xem tat ca san pham\n"<<"Chon: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:{

        }
    }
}
void thanhToan(myphamNoi list1[], myphamNgoai list2[], khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    
}
int menu(myphamNoi list1[], myphamNgoai list2[], khachHangThuong nguoimua1[], khachHangVip nguoimua2[]){
    int choice;
    cout << "1. Thanh toan;\n" << "2. Quan ly danh sach my pham;\n" <<"3. Xem thong tin tat ca san pham;\n"<<"0. De thoat.\n"<<"Chon: ";
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
    
    return 0;
}