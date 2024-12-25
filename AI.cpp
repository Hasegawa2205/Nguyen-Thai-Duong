//Bai 1
/*
#include <iostream>
#include <stack>
#include <map>
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;
bool laToanTu(char kyTu) {
    return kyTu == '?' || kyTu == '?' || kyTu == '¬' || kyTu == '?';
}
bool laBien(char kyTu) {
    return isalpha(kyTu);
}
bool bieuThucHopLe(const string &bieuThuc) {
    stack<char> dauNgoac;
    for (size_t i = 0; i < bieuThuc.length(); ++i) {
        char kyTu = bieuThuc[i];
        if (kyTu == '(') {
            dauNgoac.push(kyTu);
        } else if (kyTu == ')') {
            if (dauNgoac.empty()) return false;
            dauNgoac.pop();
        } else if (!laBien(kyTu) && !laToanTu(kyTu) && kyTu != ' ' && kyTu != '(' && kyTu != ')') {
            return false;
        }
    }
    return dauNgoac.empty();
}
bool thucHienToanTu(char toanTu, bool giaTri1, bool giaTri2 = false) {
    if (toanTu == '?') return giaTri1 && giaTri2;
    if (toanTu == '?') return giaTri1 || giaTri2;
    if (toanTu == '¬') return !giaTri1;
    if (toanTu == '?') return !giaTri1 || giaTri2;
    throw invalid_argument("Toan tu khong hop le");
}
bool tinhBieuThuc(const string &bieuThuc, const map<char, bool> &giaTriBien) {
    stack<bool> toanHang;
    stack<char> toanTu;

    for (size_t i = 0; i < bieuThuc.length(); ++i) {
        char kyTu = bieuThuc[i];
        if (kyTu == ' ') continue;

        if (laBien(kyTu)) {
            if (giaTriBien.find(kyTu) == giaTriBien.end()) {
                throw invalid_argument("Gia tri cua bien chua duoc xac dinh");
            }
            toanHang.push(giaTriBien.at(kyTu));
        } else if (laToanTu(kyTu)) {
            toanTu.push(kyTu);
        } else if (kyTu == '(') {
            toanTu.push(kyTu);
        } else if (kyTu == ')') {
            while (!toanTu.empty() && toanTu.top() != '(') {
                char toanTuHienTai = toanTu.top();
                toanTu.pop();

                bool giaTri1 = toanHang.top();
                toanHang.pop();

                if (toanTuHienTai == '¬') {
                    toanHang.push(thucHienToanTu(toanTuHienTai, giaTri1));
                } else {
                    bool giaTri2 = toanHang.top();
                    toanHang.pop();
                    toanHang.push(thucHienToanTu(toanTuHienTai, giaTri2, giaTri1));
                }
            }
            if (!toanTu.empty() && toanTu.top() == '(') {
                toanTu.pop();
            }
        }
    }

    while (!toanTu.empty()) {
        char toanTuHienTai = toanTu.top();
        toanTu.pop();

        bool giaTri1 = toanHang.top();
        toanHang.pop();

        if (toanTuHienTai == '¬') {
            toanHang.push(thucHienToanTu(toanTuHienTai, giaTri1));
        } else {
            bool giaTri2 = toanHang.top();
            toanHang.pop();
            toanHang.push(thucHienToanTu(toanTuHienTai, giaTri2, giaTri1));
        }
    }

    return toanHang.top();
}

int main() {
    string bieuThuc;
    cout << "Nhap bieu thuc logic: ";
    getline(cin, bieuThuc);

    if (!bieuThucHopLe(bieuThuc)) {
        cout << "Bieu thuc khong hop le!" << endl;
        return 1;
    }

    map<char, bool> giaTriBien;
    cout << "Nhap cac gia tri cho cac bien (vi du: A True B False): ";
    char bien;
    string giaTri;
    while (cin >> bien >> giaTri) {
        giaTriBien[bien] = (giaTri == "True" || giaTri == "true");
    }

    try {
        bool ketQua = tinhBieuThuc(bieuThuc, giaTriBien);
        cout << "Ket qua bieu thuc: " << (ketQua ? "True" : "False") << endl;
    } catch (const exception &e) {
        cout << "Loi: " << e.what() << endl;
    }

    return 0;
}
*/
//Bai 2
/*
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <algorithm>  
using namespace std;

bool laToanTu(char kyTu) {
    return kyTu == '?' || kyTu == '¬';
}

bool laBien(char kyTu) {
    return isalpha(kyTu);
}

bool thucHienToanTu(char toanTu, bool giaTri1, bool giaTri2 = false) {
    if (toanTu == '?') return giaTri1 && giaTri2;
    if (toanTu == '?') return giaTri1 || giaTri2;
    if (toanTu == '¬') return !giaTri1;
    throw invalid_argument("Toan tu khong hop le");
}

bool tinhBieuThuc(const string &bieuThuc, const map<char, bool> &giaTriBien) {
    stack<bool> toanHang;
    stack<char> toanTu;
    
    for (size_t i = 0; i < bieuThuc.length(); ++i) {  
        char kyTu = bieuThuc[i];
        if (kyTu == ' ') continue;
        
        if (laBien(kyTu)) {
            if (giaTriBien.find(kyTu) == giaTriBien.end()) {
                throw invalid_argument("Gia tri cua bien chua duoc xac dinh");
            }
            toanHang.push(giaTriBien.at(kyTu));
        } else if (laToanTu(kyTu)) {
            toanTu.push(kyTu);
        } else if (kyTu == '(') {
            toanTu.push(kyTu);
        } else if (kyTu == ')') {
            while (!toanTu.empty() && toanTu.top() != '(') {
                char toanTuHienTai = toanTu.top();
                toanTu.pop();
                
                bool giaTri1 = toanHang.top(); toanHang.pop();
                if (toanTuHienTai == '¬') {
                    toanHang.push(thucHienToanTu(toanTuHienTai, giaTri1));
                } else {
                    bool giaTri2 = toanHang.top(); toanHang.pop();
                    toanHang.push(thucHienToanTu(toanTuHienTai, giaTri2, giaTri1));
                }
            }
            toanTu.pop(); 
        }
    }
    
    while (!toanTu.empty()) {
        char toanTuHienTai = toanTu.top();
        toanTu.pop();
        bool giaTri1 = toanHang.top(); toanHang.pop();
        
        if (toanTuHienTai == '¬') {
            toanHang.push(thucHienToanTu(toanTuHienTai, giaTri1));
        } else {
            bool giaTri2 = toanHang.top(); toanHang.pop();
            toanHang.push(thucHienToanTu(toanTuHienTai, giaTri2, giaTri1));
        }
    }
    
    return toanHang.top();
}

void sinhBangChantTri(const string &bieuThuc, vector<char> &bien, map<char, bool> &giaTriBien, size_t index) {
    if (index == bien.size()) {
        for (size_t i = 0; i < bien.size(); ++i) {  
            cout << (giaTriBien[bien[i]] ? "T " : "F ");
        }
        try {
            cout << (tinhBieuThuc(bieuThuc, giaTriBien) ? "T" : "F") << endl;
        } catch (const exception &e) {
            cout << "Loi: " << e.what() << endl;
        }
        return;
    }
    
    giaTriBien[bien[index]] = false;
    sinhBangChantTri(bieuThuc, bien, giaTriBien, index + 1);
    giaTriBien[bien[index]] = true;
    sinhBangChantTri(bieuThuc, bien, giaTriBien, index + 1);
}

int main() {
    string bieuThuc;
    cout << "Nhap bieu thuc logic (su dung ?, ¬, ...): ";
    getline(cin, bieuThuc);
    
    vector<char> bien;
    for (size_t i = 0; i < bieuThuc.length(); ++i) { 
        char kyTu = bieuThuc[i];
        if (laBien(kyTu) && find(bien.begin(), bien.end(), kyTu) == bien.end()) {
            bien.push_back(kyTu);
        }
    }
    
    if (bien.empty()) {
        cout << "Khong tim thay bien nao trong bieu thuc!" << endl;
        return 1;
    }
    
    for (size_t i = 0; i < bien.size(); ++i) {  
        cout << bien[i] << " ";
    }
    cout << "Ket qua\n";
    
    map<char, bool> giaTriBien;
    sinhBangChantTri(bieuThuc, bien, giaTriBien, 0);
    
    return 0;
}
*/
//Bai 3
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <sstream>
using namespace std;
bool P(int x) {
    return x > 1;
}
bool Q(int x) {
    return x % 2 == 0;
}
bool forall(const vector<int>& domain) {
    for (size_t i = 0; i < domain.size(); ++i) {
        int x = domain[i];
        if (P(x) && !Q(x)) {
            return false; 
        }
    }
    return true;
}
bool exists(const vector<int>& domain) {
    for (size_t i = 0; i < domain.size(); ++i) {
        int y = domain[i];
        if (P(y)) {
            return true; 
        }
    }
    return false;
}

int main() {
    string formula;
    string domainInput;
    vector<int> domain;
    cout << "Nhap cong thuc logic vi tu: ";
    getline(cin, formula);
    cout << "Nhap mien gia tri (vd: 1 2 3): ";
    getline(cin, domainInput);
    stringstream ss(domainInput);
    int value;
    while (ss >> value) {
        domain.push_back(value);
    }
    if (forall(domain) && exists(domain)) {
        cout << "Công th?c dúng!" << endl;
    } else {
        cout << "Công th?c sai!" << endl;
    }

    return 0;
}




