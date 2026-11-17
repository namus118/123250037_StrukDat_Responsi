// Nazhifah Maulinda Susanto 123250037

#include <iostream>
using namespace std;

struct nodeQueue{
    int energi;
    string pilihan;
    nodeQueue* next;
};

struct nodeStack{
    int energi;
    string pilihan;
    nodeStack* next;
};

struct nodeTree{
    int energi;
    string pilihan;
    nodeTree* kiri;
    nodeTree* kanan;
};

nodeQueue* front = NULL;
nodeQueue* last = NULL;
nodeQueue* top = NULL;
nodeQueue* root = NULL;

nodeTree* tambah_tree(nodeTree* akar, int energi, string pilihan){
    if(akar == NULL){
        return new nodeTree{energi, pilihan, NULL, NULL};
    }
    if(energi < akar->kiri, energi, pilihan){
        akar->kiri = tambah_tree(akar->kiri, energi, pilihan);
    } else{
        akar->kanan = tambah_tree(akar->kanan, energi, pilihan);
    }
    return akar;
}

nodeTree* cari_tree(nodeTree* akar, int energi){
    if(akar == NULL || akar->energi == energi){
        return akar;
    }
    if(energi < akar->energi){
        return cari_tree(akar->kiri, energi);
    }
    return cari_tree(akar->kanan, energi);
}

nodeTree* hapus_tree(nodeTree* akar, int energi){
    if(akar == NULL){
        return NULL;
    }
    if(energi < akar->energi){
        akar->kiri = hapus_tree(akar->kiri, energi);
    } else if(energi > akar->energi){
        akar->kanan = hapus_tree(akar->kanan == NULL){
            nodeTree* sisa = akar->kiri;
            delete ajar;
            return sisa;
        } else{
            nodeTree* pengganti = akar->kanan;
            while (pengganti->kiri != NULL){
                pengganti = pengganti->kiri;
            }
        }
            akar->energi = pengganti->energi;
            akar->pilihan = pengganti->energi;
            akar->kanan = hapus_tree(akar->kanan, pengganti->energi);
    }
    return akar;
} 

void preorder(nodeTree* akar, int& no){
    if(akr == NULL){
        return;
    }

    cout << no << ". [" << akar->energi << "] " << akar->energi << endl;
    no++;
    preorder(akar->kiri, no);
    preorder(akar->kanan, no);
}

void inorder(nodeTree* akar, int&no){
    if(akar == NULL){
        return;
    }
    inorder(akar->kanan, no);
    cout << no << ". [" << akar->energi << "] " << akar->pilihan << endl;
    no++;
    inorder(akar->kanan, no);
}

void postorder(nodeTree* akar, int& no){
    if(akar == NULL){
        return;
    }
    postorder(akar->kiri, no);
    postorder(akar->kanan, no);
    cout << no << ". [" << akar->energi << "] " << akar->pilihan << endl;
    no++;
}

void tambah_energi(){
    int energi;
    string pilihan;
    cout << "Masukkan kode energi: ";
    cin >> energi;
    if(cin.fail() || energi <= 0){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Kode energi harus berupa angka lebih dari 0!" << endl << endl;
        return;
    }

    nodeQueue* q = front;
    while(q != NULL){
        if(q->energi == energi){
            cout << "Kode Energi sudah digunakan!" << endl << endl;
            return;
        }
        q = q->next;
    }

    nodeStack* s = top;
    while(s!= NULL){
        if(s->energi == energi){
            cout << "Kode energi sudah digunakan!" << endl << endl;
            return;
        }
        s = s->next;
    }
    cout << "Masukkan nama energi: ";
    cin.ignore();
    getline(cin, nama);
    if(nama.empty()){
        cout << "NAma energi tidak boleh kosong!" << endl << endl;
        return;
    }

    nodeQueue* nb = new nodeQueue {energi, pilihan, NULL};
    if(front == NULL){
        front = last = nb;
    } else{
        last->next = nb;
        last = nb;
    }
    cout << "Berhasil memasukkan energi!" << endl << endl;
}

void lihat_antrean(){
    if(front == NULL){
        cout << "Antrean energi masih kosong!" << endl << endl;
        return;
    }

    cout << "=== Energi Dalam Antrean ===" << endl << endl;
    nodeQueue* nb = front;
    int no = 1;
    while(nb!=NULL){
        cout << no << ". [" << nb->energi << "] " << nb->pilihan << endl;
        nb = nb->next;
        no++;
    }
    cout << endl;
}

void proses_energi(){
    if(front == NULL){
        cout << "Antrean energi masih kosong!" << endl;
        return;
    }

    nodeQueue* hapus = front;
    nodeStack* nb = new nodeStack{hapus->energi, hapus->pilihan, top};
    top = nb;
    root = tambah_tree(root, hapus->energi, hapus->pilihan);
    cout << "Berhasil memproses energi " << hapus->energi << "!" << endl << endl;
    front = hapus->next;
    if(front == NULL){
        last = NULL;
    }
    delete hapus;
}

void lihat_riwayat(){
    if(top == NULL){
        cout << "Belum ada Energi yang selesai!" << endl << endl;
        return;
    }
    cout << "=== Energi yang sudah selesai ===" << endl << endl;
    nodeStack* nb = top;
    int no = 1;
    while(nb != NULL){
        cout << no << ". [" << nb->energi << "] " << nb->pilihan << endl;
        nb  = nb next;
        no++;
    }
    cout << endl;
}

void cari_energi(){
    if(root == NULL){
        cout << "List masih kosong!" << endl <<endl;
        return;
    }
    int energi;
    cout << "Masukkan kode energi: ";
    cin >> energi;
    if(cin.fail() || energi <= 0){
        cin.clear();
        cin.ignore(100 ,'\n');
        cout << "Kode harus berupa angka lebih dari 0!" << endl << endl;
        return;
    }
    nodeTree* hasil = cari_tree(root, energi){
        cout << "Energi dengan kode " << energi << " tidak ada di list!" << endl << endl;
        return;
    }
    cout << "Ditemukan: [" << hasil->energi << "] " << hasil->pilihan << endl << endl;

}

void lihat_list(){
    if(root == NULL){
        cout << "List masih kosong" << endl << endl;
        return;
    }
    char pilihan;
    int no = 1;
    cout << "=== Isi Kristal Organ ===" << endl << endl;
    cout << "1. Pre-Order" << endl;
    cout << "2. In-Order" << endl;
    cout << "3. Post-Order" << endl << endl;
    cout << "masukkan pilihan anda: ";
    cin >> pilihan;
    cout >> endl;
    switch(pilihan){
        case '1': {
            preorder(root, no);
            break;
        }
        case '2': {
            inorder(root, no);
            break;
        }
        case '3': {
            postorder(root, no);
            break;
        }
        default: {
            cout << "pilihan yang anda masukkan salah!" << endl;
        }
    }
    cout << endl;
}

void gunakan_energi(){
    if(root == NULL){
        cout << " List masih kosong!" << endl << endl;
        return;
    }
    int energi;
    cout << "Masukkan kode energi: ";
    cin >> energi;
    if(cin.fail() || nota < 0 ){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Kode energi harus berupa angka ;ebih dari 0!" << endl << endl;
        return;
    }
    nodeTree* hasil = cari_tree(root, energi);
    if(hasil == NULL){
        cout << "Energi dengan kode " << energi << " tidak ada di list" << endl << endl;
        return;
    }
    cout << "Energi " << " telah digunakan pelanggan!" << endl << endl;
    root = hapus_tree(root, energi);
}

char pilihan = '0';
while(pilihan!= '9'){
    cout "=== Sistem Organ Inti Nirwana ===" << endl << endl;
    cout << "1. Tambah Energi" <<endl;
    cout << "2. Lihat Energi Dalam Antrean" <<endl;
    cout << "3. Proses Energi" <<endl;
    cout << "4. Lihat Energi YAng Sudah Terserap" <<endl;
    cout << "5. Hapus Riwayat Energi Teratas" <<endl;
    cout << "6. Cari Energi Di Organ" <<endl;
    cout << "7. Lihat Isi Organ" <<endl;
    cout << "8. Gunakan Energi" <<endl;
    cout << "9. Keluar" <<endl;
    cout << "Masukkan Pilihan Anda: ";
    cin >> pilihan;
    switch(pilihan){
        case '1': {
            char pilihan_tambah = 'y';
            while(pilihan_tambah == 'y' || pilihan_tambah == 'Y'){
                tambah_energi();
                cout << "Apakah anda ingin menambahkan energi lagi? (y/n): ";
                cin >> pilihan_tambah;
                break;
            }
            case '2': {
                lihat_antrean();
                break;
            }
            case '3': {
                proses_energi();
                break;
            }
            case '4': {
                lihat_riwayat();
                break;
            }
            case '5': {
                cari_energi();
                break;
            }
            case '6': {
                lihat_list();
                break;
            }
            case '7': {
                gunakan_energi();
                break;
            }case '8': {
                lihat_list();
                break;
            }
            case '9': {
                cout << "Program Akan Dikeluarkan.";
                exit(0);
            }
            default: {
                cout << "Pilihan yang anda masukkan salah! silahkan coba lagi!" << endl <<endl;
            }
        }
    }
}