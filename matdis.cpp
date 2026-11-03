#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <conio.h>
#define ll long long
#define maks numeric_limits<streamsize>::max()
using namespace std;

//Prosedur untuk menampilkan garis
void garis(){
    cout << "======================================================\n";
}

//cek input valid angka
ll inputValid(string kalimat, string error, ll a = 0, ll b = maks){
    ll x;
    while(true){
        cout << kalimat; cin >> x;
        bool salah = cin.fail() || cin.peek() != '\n' || x < a || x > b;
        cin.clear(); 
        cin.ignore(maks, '\n');
        if(!salah) return x;
        cout << error << endl;
    }
}

char inputOperator(string kalimat){
    char c;
    while(true){
        cout << kalimat; cin >> c;
        bool salah = cin.peek() != '\n' || (c != '+' && c != '*');
        cin.clear(); 
        cin.ignore(maks, '\n');
        if(!salah) return c;
        cout << "Operator yang anda pilih tidak tersedia\n";
    }
}

char inputValidator(string kalimat){
    char c;
    while(true){
        cout << kalimat; cin >> c;
        bool salah = cin.peek() != '\n' || (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
        cin.clear();
        cin.ignore(maks, '\n');
        if(!salah) return c;
        cout << "Masukkan y atau n\n";
    }
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

string kombinNotasi(ll n, ll r){
    string notasi;
    notasi = "C(" + to_string(n) + "," + to_string(r) + ")";
    return notasi;
}

//Prosedur untuk menampilkan bentuk kombinasi
string kombinBentuk(ll n, ll r){ //contohnya n=10, r=3; hasilnya (10!/(7!*3!)) 
    string bentuk;
    bentuk = "(" + to_string(n) + "! / ( " + to_string(n-r) + "! * " + to_string(r) + "!))";
    return bentuk;
}

//Fungsi untuk mengecek apakah kombinasi itu valid atau tidak
bool validKombin(ll n, ll r){
    if(n < 0 || r < 0){
        cout << "n dan r tidak boleh negatif.\n";
        return false;
    }
    if(r > n){
        cout << "r tidak boleh lebih besar dari n.\n";
        return false;
    }
    return true;
}

//Prosedur untuk mengerjakan beberapa soal-soal kombinasi
void Kombinasi(string soal){
    int banyak, jenis;
    ll n1, r1, dn1 = 0, dr1 = 0, n2 = 0, r2 = 0, dn2 = 0, dr2 = 0;
    ll nilai, nilai2, jumlah = 0, suku = 0, total;
    char opr = '+', oprDalam = '*';
    string rumus = "", Ckombin = "", teks, notasi;
    garis();
    cout << soal << endl;
    cout << "Pilihan tipe soal:\n";
    cout << "1. Satu kombinasi\n2. Dua kombinasi\n";
    jenis = inputValid("Pilihan (1-2): ", "Pilihan tidak ada", 1, 2);
    banyak = inputValid("Banyak suku: ", "Masukkan bilangan bulat dan > 0", 1);
    garis();
    if(banyak > 1){
        opr = inputOperator("Operator antar suku (+,*): ");
    }
    cout << "-- Kombinasi pertama (di suku pertama) --\n";
    n1 = inputValid("Masukkan n1: ", "Masukkan bilangan bulat dan > 0", 0);
    r1 = inputValid("Masukkan r1: ", "Masukkan bilangan bulat dan berada di antara 0 dan n1", 0, n1);
    if(banyak>1){
        dn1 = inputValid("n1 berubah tiap suku sebesar (mis. -1, 0, 1): ", "Masukkan bilangan bulat", -n1, n1);
        dr1 = inputValid("r1 berubah tiap suku sebesar: ", "Masukkan bilangan bulat yang valid", -r1, n1 - r1);
    }
    if(jenis == 2){
        oprDalam = inputOperator("Operator di dalam suku (+,*): ");
        cout << "-- Kombinasi kedua (di suku pertama) --\n";
        n2 = inputValid("Masukkan n2: ", "Masukkan bilangan bulat dan > 0", 0);
        r2 = inputValid("Masukkan r2: ", "Masukkan bilangan bulat dan berada di antara 0 dan n2", 0, n2);
        if(banyak>1){
            dn2 = inputValid("n2 berubah tiap suku sebesar: ", "Masukkan bilangan bulat", -n2, n2);
            dr2 = inputValid("r2 berubah tiap suku sebesar: ", "Masukkan bilangan bulat yang valid", -r2, n2 - r2);
        }
    }

    for(int i=1; i<=banyak; i++){
        if(!validKombin(n1, r1)){
            cout << "(terjadi pada suku ke-" << i << ")\n";
            _getch();
            return;
        }
        nilai = kombin(n1, r1);
        notasi = (jenis == 2 ? "(" + kombinNotasi(n1, r1) : kombinNotasi(n1,r1));
        teks = (jenis == 2 ? "(" + kombinBentuk(n1, r1) : kombinBentuk(n1,r1));

        if(jenis == 2){
            if(!validKombin(n2, r2)){
                cout << "(terjadi pada suku ke-" << i << ")\n";
                _getch();
                return;
            }
            nilai2 = kombin(n2, r2);
            notasi += oprDalam + kombinNotasi(n2, r2) + ")";;
            teks += oprDalam + kombinBentuk(n2, r2) + ")";
            if(oprDalam == '+'){
                nilai += nilai2;
            } else if(oprDalam == '*'){
                nilai *= nilai2;
            }
        }

        if(i == 1){
            suku = nilai;
            Ckombin = notasi;
            rumus = teks;
        } else {
            rumus += opr + teks;
            Ckombin += opr + notasi;
            if(opr == '+'){
                jumlah += suku;
                suku = nilai;
            } else if (opr == '*'){
                suku *= nilai;
            }
        }
        n1 += dn1; r1 += dr1;   // maju ke suku berikutnya
        n2 += dn2; r2 += dr2;
    }
    total = jumlah + suku;
    garis();
    cout << "Jawab:\n" << Ckombin << "\n=" << rumus << "\n= " << total << endl;
    _getch();
}

//Prosedur untuk menginput soal
void inputSoal(){
    string soal;
    bool ulang = true;
    char yn;
    while(ulang){
        garis();
        cout << "Masukkan Soal:\n";
        getline(cin,soal);
        cout << endl;
        garis();
        Kombinasi(soal);
        yn = inputValidator("\nApakah anda ingin mengulangi (y/n): ");
        if(yn=='n'||yn=='N') ulang = false;
        else if(yn=='y'||yn=='Y')continue;
    }

}

//Program Utama
int main() {
    system("cls");
    int pilatas, pilcontoh;
    bool lanjut = true;
    do{
        string soal;
        system("cls");
        garis();
        cout << setw(12) << "" << "Kombinasi tanpa Perulangan\n";
        garis();
        cout << "Apa yang anda mau lakukan?\n"
        << "1. Contoh soal\n" << "2. Input soal\n" << "3. Keluar\n";
        pilatas = inputValid("Pilihan anda: ", "Pilihan tidak ada", 1, 3);
        
        switch(pilatas){
            case 1:{
            bool lanjutContoh = true;
            garis();
            do{
                cout << "Pilihan Soal:\n"
                << "1. Soal 1:\n2. Soal 2:\n3. Soal 3:\n4. Keluar\n";
                pilcontoh = inputValid("Soal yang anda pilih: ", "Pilihan tidak ada", 1, 4);
                switch(pilcontoh){
                    case 1:{
                    ll mhs = 100, panit = 10, cara;
                    soal = "1. Didalam sebuah kelas terdapat 100 mahasiswa, 40 diantara orangnya adalah laki-laki. Berapa banyak cara dapat dibentuk sebuah panitia 10-orang\n";
                    Kombinasi(soal);
                    break;
                    }
                    case 2:{
                    ll mhs = 100, panit = 10;
                    soal = "2. Didalam sebuah kelas terdapat 100 mahasiswa, 40 diantara orangnya adalah laki-laki. Berapa banyak cara dapat dibentuk sebuah panitia 10-orang jika banyaknya laki-laki yang dipilih sama banyak dengan yang perempuan.";
                    Kombinasi(soal);
                    break;
                    }
                    case 3:{
                    ll mhs = 100, panit = 10;
                    soal = "3. Berapa banyak cara membentuk sebuah panitia yang beranggotakan 5 orang yang dipilih dari 7 orang pria dan 5 orang wanita, jika di dalam panitia tersebut paling sedikit beranggotakan 2 orang wanita?";
                    Kombinasi(soal);
                    break;
                    }
                    case 4:{
                    lanjutContoh = false;
                    break;
                    }
                }
            } while(lanjutContoh);
            system("pause");
            break;
            }
            case 2:{
            inputSoal();
            break;
            }
            case 3:{
            cout << "\nTerima kasih sudah menggunakan program kami\n";
            _getch();
            return 0;
            }
        }
    } while(lanjut);
    return 0;
}