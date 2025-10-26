#include <iostream>
using namespace std;
struct Mahasiswa {
 string nama;
 int umur;
 string nik;
};
int main() {
 Mahasiswa mhs1;
 mhs1.nama = "Andi";
 mhs1.umur = 20;
 mhs1.nik = "1234567890123456";

 cout << "Nama: " << mhs1.nama << endl;
 cout << "Umur: " << mhs1.umur << endl;
 cout << "Nilai: " << mhs1.nik << endl;
 return 0;
}
