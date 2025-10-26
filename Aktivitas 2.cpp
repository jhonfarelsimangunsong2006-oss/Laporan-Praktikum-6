#include <iostream>
using namespace std;
struct Mahasiswa {
 string nama;
 int umur;
 string nik;
};
int main() {
 const int jumlahMahasiswa = 3;
 Mahasiswa mhs[jumlahMahasiswa];
 for (int i = 0; i < jumlahMahasiswa; i++) {
 cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
 getline(cin, mhs[i].nama);
 cout << "Masukkan umur: ";
 cin >> mhs[i].umur;
 cin.ignore();
 cout << "Masukkan NIK: " ;
 getline(cin, mhs[i].nik);
 cout << endl;
 }
 cout << "\nData Mahasiswa:" << endl;
 for (int i = 0; i < jumlahMahasiswa; i++) {
 cout << "Mahasiswa " << i + 1 << ":" << endl;
 cout << "Nama: " << mhs[i].nama << endl;
 cout << "Umur: " << mhs[i].umur << endl;
 cout << "NIK: " << mhs[i].nik << endl;
 cout << endl;
 }
 return 0;
}
