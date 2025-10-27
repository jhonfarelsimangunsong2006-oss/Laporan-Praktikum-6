#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Karyawan {
    string nama;
    int umur;
    string nik;
    string jabatan;
};

int main() {
    Karyawan kry[100];
    int jumlahData = 0;
    ifstream fileIn("karyawan.txt");
    if (fileIn.is_open()) {
        while (fileIn >> kry[jumlahData].nama >> kry[jumlahData].umur >> kry[jumlahData].nik >> kry[jumlahData].jabatan) {
            jumlahData++;
        }
        fileIn.close();
    } else {
        cout << "File tidak ditemukan. File baru akan dibuat."<<endl;
    }

    int pilihan;
    do {
        cout << "MENU MANAJEMEN DATA KARYAWAN"<<endl;
        cout << "1. Tampilkan semua data"<<endl;
        cout << "2. Tambah data karyawan"<<endl;
        cout << "3. Edit data berdasarkan NIK"<<endl;
        cout << "4. Hapus data berdasarkan NIK"<<endl;
        cout << "5. Keluar"<<endl;
        cout << "Pilih menu:";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "Data Karyawan"<<endl;
                if (jumlahData == 0) {
                    cout << "Belum ada data"<<endl;
                } else {
                    for (int i = 0; i < jumlahData; i++) {
                        cout << i + 1 << ". Nama:" << kry[i].nama
                             << ", Umur:" << kry[i].umur
                             << ", NIK: " << kry[i].nik
                             << ", Jabatan: " << kry[i].jabatan << endl;
                    }
                }
                break;
            }

            case 2: {
                if (jumlahData < 100) {
                    cout << "Masukkan nama: ";
                    cin >> kry[jumlahData].nama;
                    cout << "Masukkan umur: ";
                    cin >> kry[jumlahData].umur;
                    cout << "Masukkan NIK: ";
                    cin >> kry[jumlahData].nik;
                    cout << "Masukkan jabatan: ";
                    cin >> kry[jumlahData].jabatan;
                    jumlahData++;
                    cout << "Data berhasil ditambahkan!"<<endl;
                } else {
                    cout << "Data penuh! Tidak bisa menambah lagi"<<endl;
                }
                break;
            }

            case 3: {
                string edit;
                cout << "Masukkan NIK yang akan diedit: ";
                cin >> edit;
                bool ditemukan = false;
                for (int i = 0; i < jumlahData; i++) {
                    if (kry[i].nik == nikEdit) {
                        cout << "Masukkan nama baru: ";
                        cin >> kry[i].nama;
                        cout << "Masukkan umur baru: ";
                        cin >> kry[i].umur;
                        cout << "Masukkan jabatan baru: ";
                        cin >> kry[i].jabatan;
                        cout << "Data berhasil diperbarui!"<<endl;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) cout << "NIK tidak ditemukan!"<<endl;
                break;
            }

            case 4: {
                string hapus;
                cout << "Masukkan NIK yang akan dihapus: ";
                cin >> hapus;
                bool ditemukan = false;
                for (int i = 0; i < jumlahData; i++) {
                    if (kry[i].nik == nikHapus) {
                        for (int j = i; j < jumlahData - 1; j++) {
                            kry[j] = kry[j + 1];
                        }
                        jumlahData--;
                        cout << "Data berhasil dihapus!"<<endl;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) cout << "NIK tidak ditemukan!"<<endl;
                break;
            }

            case 5:
                cout << "Menyimpan data dan keluar"<<endl;
                break;

            default:
                cout << "Pilihan tidak valid!"<<endl;
        }

    } while (pilihan != 5);

    ofstream fileOut("karyawan.txt");
    for (int i = 0; i < jumlahData; i++) {
        fileOut << kry[i].nama << " "
                << kry[i].umur << " "
                << kry[i].nik << " "
                << kry[i].jabatan << endl;
    }
    fileOut.close();

    return 0;
}

