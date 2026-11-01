#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <conio.h>
#define ll long long
using namespace std;

void garis(){
    cout << "======================================================\n";
}
//C(n,r)=n!/(n-r)!r!
ll kombin(ll n, ll r){
    ll hasil = 1;
    if(r < 0 || r > n) return 0;
    if(r == 0 || r == n) return 1;
    if(r > n-r) r = n-r;
    for(int i=1; i<=r; i++){
        hasil *= (n-r+i);
        hasil /= i;
    }
    return hasil;
}

//Prosedur untuk menampilkan bentuk kombinasi
void kombinbentuk(ll n, ll r){ //contohnya n=10, r=3; 
    cout << "(" << n << "! / ( " << n-r << "! * " << r <<"!))";
}

//Prosedur untuk menyelesaikan soal dengan 1 kombinasi
void satuKombin(string soal){ //contohnya: C(n,r)
    ll n, r, cara;
    garis();
    cout << soal << endl;
    cout << "Masukkan n: "; cin >> n;
    cout << "\nMasukkan r: "; cin >> r;
    cout << endl; 
    garis();
    cara = kombin(n, r);
    cout << "Jawab:\n";
    kombinbentuk(n, r);
    cout << " = " << cara << endl;
    _getch();
}

//Prosedur untuk menyelesaikan soal-soal yang menggunakan 2 kombinasi
void duaKombin(string soal){ //contohnya: C(n1,r1)*C(n2,r2)
    ll n1, n2, r1, r2, cara;
    char opr;
    garis();
    cout << soal << endl;
    cout << "Masukkan n1: "; cin >> n1;
    cout << "Masukkan n2: "; cin >> n2;
    cout << "Masukkan r1: "; cin >> r1;
    cout << "Masukkan r2: "; cin >> r2;
    cout << "Masukkan operator(+,-,*,/): "; cin >> opr;
    switch(opr){
        case '+':
        cara = kombin(n1, r1) + kombin(n2, r2);
        break;
        case '-':
        cara = kombin(n1, r1) - kombin(n2, r2);
        break;
        case '*':
        cara = kombin(n1, r1) * kombin(n2, r2);
        break;
        case '/':
        if(kombin(n2, r2) == 0){
            cout << "Tidak bisa dibagi nol\n"; 
            _getch(); 
            return;
        }
        cara = kombin(n1, r1) / kombin(n2, r2);
        break;
    }

    cout << "C("<<n1<<"," << r1 << ") " << opr << " C(" << n2 << "," << r2 << ")" << " = "; 
    kombinbentuk(n1,r1);
    cout << " " << opr << " "; 
    kombinbentuk(n2,r2);
    cout << " = " << cara << endl;
    _getch();
}

//
void jumlahKombin(string soal){
    garis();
    cout << soal << endl;
}

//Prosedur untuk menginput tipe soal
void inputJawab(string soal){
    int piltipe;
    cout << "Tipe soal yang ada:\n"
    << "1. Satu Kombinasi\n"
    << "2. Dua Kombinasi\n"
    << "3. Jumlah Kombinasi\n";
    cout << "\nTipe soal anda (1-3): ";
    cin >> piltipe;
    switch(piltipe){
        case 1:
        satuKombin(soal);
        break;
        case 2:
        duaKombin(soal);
        break;
        case 3:
        jumlahKombin(soal);
    }
}

//Prosedur untuk menginput soal
void inputSoal(){
    string soal;
    bool keluar = true;
    char yn;
    while(keluar){
        garis();
        cout << "Masukkan Soal:\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,soal);
        cout << endl;
        inputJawab(soal);
        cout << "\nApakah anda ingin mengulangi (y/n): ";
        cin >> yn;
        if(yn=='n'||yn=='N') keluar = false;
        else if(yn=='y'||yn=='Y')continue;
    }

}

//Program Utama
int main() {
    system("cls");
    int pilatas, pilcontoh;
    bool keluar1 = true ,keluar2 = true;

    do{
        string soal;
        system("cls");
        garis();
        cout << setw(12) << "" << "Kombinasi tanpa Perulangan\n";
        garis();
        cout << "Apa yang anda mau lakukan?\n"
        << "1. Contoh soal\n" << "2. Input soal\n" << "3. Keluar\n";
        cout << "Pilihan anda: "; cin >> pilatas;
        
        switch(pilatas){
            case 1:
            garis();
            do{
                cout << "Pilihan Soal:\n"
                << "1. Soal 1:\n2. Soal 2:\n3. Soal 3:\n4. Keluar\n";
                cout << "Soal yang anda pilih: "; cin >> pilcontoh;
                switch(pilcontoh){
                    case 1:{
                    ll mhs = 100, panit = 10, cara;
                    soal = "1. Didalam sebuah kelas terdapat 100 mahasiswa, 40 diantara orangnya adalah laki-laki. Berapa banyak cara dapat dibentuk sebuah panitia 10-orang\n";
                    satuKombin(soal);
                    break;
                    }
                    case 2:{
                    ll mhs = 100, panit = 10;
                    soal = "2. Didalam sebuah kelas terdapat 100 mahasiswa, 40 diantara orangnya adalah laki-laki. Berapa banyak cara dapat dibentuk sebuah panitia 10-orang jika banyaknya laki-laki yang dipilih sama banyak dengan yang perempuan.";
                    duaKombin(soal);
                    break;
                    }
                    case 3:{
                    ll mhs = 100, panit = 10;
                    soal = "3. Didalam sebuah kelas terdapat 100 mahasiswa, 40 diantara orangnya adalah laki-laki. Berapa banyak cara dapat dibentuk sebuah panitia 10-orang jika laki-laki yang dipilih 6 dan perempuannya 4.";
                    duaKombin(soal);
                    break;
                    }
                    case 4:{
                        keluar2 = false;
                        break;
                    }
                }
            } while(keluar2);
            system("pause");
            break;
            case 2:
            inputSoal();
            break;
            case 3:
            cout << "\nTerima kasih sudah menggunakan program kami\n";
            _getch();
            return 0;
        }
    } while(keluar1);
    return 0;
}

