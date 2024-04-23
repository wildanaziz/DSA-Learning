/* ASD Kelompok 5 Stack
Anggota:
1. Hanna Lailatul Islamiyah (235150301111024)
2. Nisrina Indriani Jatmiko (235150307111022)
3. Wildan Aziz Hidayat (235150301111028)
*/

#include<iostream>
#include<string>
using namespace std;

struct Node {
    Node *next = NULL, *prev = NULL;
};

struct antri {
    antri *next = NULL, *prev = NULL;
    string nama;
    int uang;
    int priority;
};

antri *head, *tail, *temp;
int safe = 0, not_safe = 0;
const int maxMasuk = 100;
antri *arrayMasuk[maxMasuk];

void tambah() {
    string nama;
    int uang;
    cin.ignore(1000, '\n');
    cout << "Masukkan nama: ";
    getline(cin, nama);
    cout << "Masukkan jumlah pembayaran: ";
    cin >> uang;
    antri *nAntri = new antri;
    nAntri->nama = nama;
    nAntri->uang = uang;
    nAntri->priority = uang;
    nAntri->next = NULL;
    nAntri->prev = NULL;

    if (head == NULL || uang > head->priority) {
        nAntri->next = head;
        if (head != NULL) {
            head->prev = nAntri;
        }
        head = nAntri;
        if (tail == NULL) {
            tail = nAntri;
        }
    } else {
        antri *temp = head;
        while (temp->next != NULL && nAntri->priority <= temp->next->priority) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = nAntri;
        }
        nAntri->next = temp->next;
        temp->next = nAntri;
        nAntri->prev = temp;
        if (nAntri->next == NULL) {
            tail = nAntri;
        }
    }
    not_safe++;
}

void masuk() {
    if (head == NULL) {
        cout << "Antrian kosong." << endl;
        return;
    }
    antri *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    temp->prev = NULL;
    if (safe < maxMasuk) {
        arrayMasuk[safe++] = temp;
        not_safe--;
    } else {
        delete temp;
    }
}

void antrian() {
    antri *temp = head;
    int i = 1;
    while (temp != NULL) {
        cout << i << ". ";
        cout << temp->nama;
        cout << ", " << temp->uang << endl;
        temp = temp->next;
        i++;
    }
    return;
}

void duar() {
    cout << "Selamat = " << safe << endl;
    for(int i = 0; i < safe; i++) {
        cout << arrayMasuk[i]->nama << ", ";
    }
    cout <<endl;
    cout << "Tidak selamat = " << not_safe << endl;
    antri *temp = head;
    while(temp != NULL) {
        cout << temp->nama << ", ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    while (true){
        int pilih;
        cout << "Masukkan pilihan: " << endl;
        cout << "1. Menambahkan antrian" << endl;
        cout << "2. Memasukkan satu orang ke dalam bunker" << endl;
        cout << "3. Menampilkan isi antrian" << endl;
        cout << "4. Bom meledak" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilih;
        switch(pilih){
            case 1:
            tambah();
            break;

            case 2:
            masuk();
            break;

            case 3:
            antrian();
            break;

            case 4:
            duar();
            return 0;
            
            case 5:
            return 0;

            default:
            cout << "Pilihan tidak valid" << endl;
        }
    }
}
