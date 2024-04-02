#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_NARAPIDANA = 3;
const int MAX_LOGIN_ATTEMPTS = 3;

struct Narapidana {
  string nama;
  string nomor_identifikasi;
  string jenis_kejahatan;
  string tanggal_masuk_penjara;
  string jangka_waktu_hukuman;
  string status_kesehatan;
};

struct DataNarapidana {
  int jumlah_narapidana = 0; 
  Narapidana* narapidana[MAX_NARAPIDANA];
};

DataNarapidana data_narapidana;

bool login() {
  int i = 0;
  string nama, NIM;

  while (i < MAX_LOGIN_ATTEMPTS) {
    system("cls");
    cout << "Masukkan nama: ";
    getline(cin, nama); 
    cout << "Masukkan NIM: ";
    getline(cin, NIM); 

    if (nama.empty() || NIM.empty()) { 
      cout << "Nama dan NIM tidak boleh kosong!" << endl;
      continue;
    }

    if (nama == "Novita" && NIM == "2309106134") {
      cout << "Selamat, login berhasil!" << endl;
      return true;
    } else {
      int remainingAttempts = MAX_LOGIN_ATTEMPTS - i - 1;
      if (remainingAttempts > 0) {
        cout << "Maaf, login gagal. Nama atau NIM salah." << endl;
        cout << "Anda memiliki " << remainingAttempts << " kesempatan login tersisa." << endl;
      } else {
        cout << "Maaf, login gagal. Batas percobaan login tercapai." << endl;
        return false;
      }
      i++;
    }
  }

  return false;
}

bool empty() {
  return data_narapidana.jumlah_narapidana == 0;
}

void add(Narapidana* &ptrNarapidana) {
  char loop;
  do {
    system("cls");
    if (data_narapidana.jumlah_narapidana < MAX_NARAPIDANA) {
      ptrNarapidana = new Narapidana;

      cin.ignore(); 
      cout << "Masukkan nama narapidana: ";
      getline(cin, ptrNarapidana->nama);
      cout << "Masukkan nomor identifikasi narapidana: ";
      getline(cin, ptrNarapidana->nomor_identifikasi);
      cout << "Masukkan jenis kejahatan: ";
      getline(cin, ptrNarapidana->jenis_kejahatan);
      cout << "Masukkan tanggal masuk penjara: ";
      getline(cin, ptrNarapidana->tanggal_masuk_penjara);
      cout << "Masukkan jangka waktu hukuman: ";
      getline(cin, ptrNarapidana->jangka_waktu_hukuman);
      cout << "Masukkan status kesehatan: ";
      getline(cin, ptrNarapidana->status_kesehatan);

      data_narapidana.narapidana[data_narapidana.jumlah_narapidana++] = ptrNarapidana;
    } else {
      cout << "==DATA NARAPIDANA SUDAH PENUH==" << endl;
    }

    cout << "Tambahkan data narapidana lain (y/t): ";
    cin >> loop;
  } while (loop == 'y');
}

void display() {
  if (!empty()) {
    for (int i = 0; i < data_narapidana.jumlah_narapidana; ++i) {
      cout << "== Data Narapidana " << i + 1 << " ==" << endl;
      cout << "Nama: " << data_narapidana.narapidana[i]->nama << endl;
      cout << "Nomor Identifikasi: " << data_narapidana.narapidana[i]->nomor_identifikasi << endl;
      cout << "Jenis Kejahatan: " << data_narapidana.narapidana[i]->jenis_kejahatan << endl;
      cout << "Tanggal Masuk Penjara: " << data_narapidana.narapidana[i]->tanggal_masuk_penjara << endl;
      cout << "Jangka Waktu Hukuman: " << data_narapidana.narapidana[i]->jangka_waktu_hukuman << endl;
      cout << "Status Kesehatan: " << data_narapidana.narapidana[i]->status_kesehatan << endl;
    }
  } else {
    cout << "==DATA NARAPIDANA KOSONG==" << endl;
  }
}

void edit() {
  if (!empty()) {
    char loop;
    do {
      system("cls");
      int index;
      bool found = false;

      cout << "Masukkan nomor narapidana yang ingin diubah: ";
      cin >> index;

      if (index > 0 && index <= data_narapidana.jumlah_narapidana) {
        index--; 

        Narapidana* ptrNarapidana = data_narapidana.narapidana[index];

        cin.ignore(); 
        cout << "Masukkan nama baru : ";
        getline(cin, ptrNarapidana->nama);
        cout << "Masukkan nomor identifikasi baru : ";
        getline(cin, ptrNarapidana->nomor_identifikasi);
        cout << "Masukkan jenis kejahatan baru : ";
        getline(cin, ptrNarapidana->jenis_kejahatan);
        cout << "Masukkan tanggal masuk penjara baru : ";
        getline(cin, ptrNarapidana->tanggal_masuk_penjara);
        cout << "Masukkan jangka waktu hukuman baru : ";
        getline(cin, ptrNarapidana->jangka_waktu_hukuman);
        cout << "Masukkan status kesehatan baru : ";
        getline(cin, ptrNarapidana->status_kesehatan);

        cout << "==Data narapidana berhasil diubah==" << endl;
        found = true;
      } else {
        cout << "Nomor narapidana tidak ditemukan." << endl;
      }

      cout << "Ubah data narapidana lain (y/t): ";
      cin >> loop;
    } while (loop == 'y');
  } else {
    system("cls");
    cout << "==Data Narapidana kosong==" << endl ;
	}
}
    
void del() {
  if (!empty()) {
    char loop;
    do {
      system("cls");
      int index;
      bool found = false;

      cout << "Masukkan nomor narapidana yang ingin dihapus: ";
      cin >> index;

      if (index > 0 && index <= data_narapidana.jumlah_narapidana) {
        index--; 

        delete data_narapidana.narapidana[index];

        for (int i = index; i < data_narapidana.jumlah_narapidana - 1; ++i) {
          data_narapidana.narapidana[i] = data_narapidana.narapidana[i + 1];
        }

        
        data_narapidana.jumlah_narapidana--;

        cout << "==Data narapidana berhasil dihapus==" << endl;
        found = true;
      } else {
        cout << "Nomor narapidana tidak ditemukan." << endl;
      }

      cout << "Hapus data narapidana lain (y/t): ";
      cin >> loop;
    } while (loop == 'y');
  } else {
    system("cls");
    cout << "==DATA NARAPIDANA KOSONG==" << endl;
  }
}

int main() {
  bool isLoggedIn = false;
  while (!isLoggedIn) {
    isLoggedIn = login();
  }

  do {
    system("cls");
    cout << "=== DATA NARAPIDANA ===\n";
    cout << "1. Tambah Data Narapidana" << endl;
    cout << "2. Lihat Data Narapidana" << endl;
    cout << "3. Ubah Data Narapidana" << endl;
    cout << "4. Hapus Data Narapidana" << endl;
    cout << "5. Keluar" << endl;

    int pilihan;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        add(data_narapidana.narapidana[data_narapidana.jumlah_narapidana]);
        break;
      case 2:
        display();
        break;
      case 3:
        edit();
        break;
      case 4:
        del();
        break;
      case 5:
        cout << "Keluar dari program." << endl;
        return 0;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }

    cout << "Tekan enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
  } while (true);

  return 0;
}

