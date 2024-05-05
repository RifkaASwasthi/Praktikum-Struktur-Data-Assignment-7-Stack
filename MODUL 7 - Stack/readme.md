# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Rifka Annisa Swasthi</p>

## Dasar Teori
Stack adalah struktur data linear yang bekerja berdasarkan pada data terakhir yang dimasukkan ke dalam stack akan menjasi data yang pertama kali diambil atau dikeluarkan dari stack dengan menggunakan prinsip Last In First Out (LIFO). Bayangkan ada tumpukan buku lalu kita mengambil tumpukan dari bawah.

Jenis Struktur data Stack yaitu

1. stack yang diimplemantasikan menggunakan Array
2. Stack diimplemantasikan menggunakan Linked List
3. Double-Ended Stack
4. Circular Stack
5. Dynamic Stack
6. Undo-Redo Stack [1]

Struktur data stack menggunakan prinsip LIFO dimana data yang terakhir dimasukkan ke Stack akan menjadi data pertama yang diambil dan dikeluarkan di stack. Stack memiliku dua operasi utama yaitu push dan pop, push untuk memasukkan data ke dalam stack dan pop digunakan untuk mengeluarkan data dari stack. Semetara operasi lain yang digunakan yaitu Peek untuk melihat posisi nilai data, size untuk menghitung jumlah data, isEmpty untuk mengecheck stack kosong atau tidak, isFull untuk mengecheck stack penuh atau tidak, clear untuk menghapus, Search untuk mencari nilai atau data dan conversation untk convert menjadi struktur data lain seperti Queue atau Linked List. [2]

Data pada stack dapat diakses dari urutan atas ke bawah dan tidak bisa diacak. Stack pada Linked List atau Dynamic stack tidak terbatas pada ukuran tertentu sehingga bisa menampung banyak data tapi pada Array atau circular Stack dibatasi dengan kapasitas tertentu, jika ukuran array terlalu besar maka memori tidak cukup.

Algoritme Stacking antara Decision Tree C4.5 dan Support Vector Machine dapat menjadi solusi untuk
mengatasi permasalahan distribusi kelas yang tidak seimbang pada dataset.Algoritme Stacking mampu menghasilkan kinerja yang lebih
baik dibandingkan algoritme single classifier seperti C4.5, K-NN, dan SVM. Selain itu algoritme Stacking juga
menghasilkan kinerja yang lebih baik dibandingkan algoritme Random Forest yang juga merupakan algoritme
bertipe meta classifier. [3]

Stack menggunakan prinsip Rekrusi dimana setiap fungsi dipanggil, data disimpan di stack dan diambil kembali setelah fungsi selesai dieksekusi.Dalam pengaplikasiannya stack digunakan untuk menyelesaikan masalah yang membutuhkan urutan eksekusi, seperti pengecekan sintaks pada kode program dll.




## Guided 

### 1. Contoh kode

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else{
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpty()){
        cout << "Tidak ada data yang dihapus" << endl;
    }else{
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else{
        int index = top; 
        for (int i = 1; i <= posisi; i ++){
            index--;
        }
        cout << "Posisi ke " << posisi << "adalah" << arrayBuku[index] << endl; 
    }
}

int countStack(){
    return top;
}
void changeArrayBuku (int posisi, string data){
    if (posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku() {
    for (int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArraybuku () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}
int main(){
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArraybuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout <<"Apakah data stack kosong?" << isEmpty () << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data =" << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArraybuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;

    cetakArraybuku();
    return 0;
}

```
Kode diatas adalah conoth dari penggunaan struktur data stack yang menggunakan array, diawal didefinisikan data yang disimpan data stack dengan kapasitas 5 elemen, maksimal menunjukkan kapasitas maksimal dan top untuk menunjukkan indeks posisi teratas. Seperti yang dijelaskan pada Dasar teori terdapat operasi isFull untuk mengembalikan true jika stack sudah penuh dan isEmpty mengembalikan true jika stack kosong. Push arraybuku untuk menambahkan data jika data sudah dimasukkan maka fungsi cout untuk mengembalikan jumlah data yang ada dalam stack kemudian jika ingin mengganti dituliskan change untuk mengubah posisi ke dalam stack dengan data baru dan destroy jika ingin menhapus data dan cetak array buku jika seluruh data sudah sesuai dari atas sampai bawah.


## Unguided 

### 1.	Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;
    string formattedStr;

    // Menghapus karakter non-alfabetik dan mengubah huruf kecil menjadi huruf besar
    for (char c : str) {
        if (isalpha(c)) {
            formattedStr += toupper(c);
            charStack.push(toupper(c));
        }
    }

    // Membandingkan kalimat dari depan dan belakang
    while (!charStack.empty()) {
        if (charStack.top() != formattedStr.front()) {
            return false;
        }
        charStack.pop();
        formattedStr.erase(0, 1);
    }

    return true;
}

int main() {
    string input;

    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-05-05 203514](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-7-Stack/assets/162097297/1188bd77-423c-4d46-9f0b-87b5fc552d04)

Kode tersebut digunakan untuk mengecheck apakah kalimat ayng dimasukkan termasuk polindrom atau bukan. Dengan mendeklarasikan isPolindrome yang mengambalikan nilai bolean true atau false berdasarkan dataa yang dimasukkan caranya dengan di fungsi isPoli digunakan utnuk menyimpan karakter string kemudian data yang dimasukkan yang daiwal sudah di formattedStr untuk menyesuaikan polindron ketika data dimasukkan maka jika ditemukan perbedaan karekter di stack dengan karekter pertama dari formattedStr, maka akan mengembalikan nilai false. begitu juga sebaliknya jika stack cocok dengan karekter dan stack kosong maka akan mengembalikan nilai true alias polindrom.contoh memasukkan kalimat rifka senang mengerjakan laporan bukan polindrom karena jika dibalik nggak sesuai jadi naropal nakajregnem gnanes akfir, kan tidak sesuai karena tidak urut.

#### Full code Screenshot:
![Screenshot 2024-05-05 204102](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-7-Stack/assets/162097297/87551c65-70c2-4ba4-86c5-c0bef3b5e0ad)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseSentence(string sentence) {
    stack<string> wordStack;
    string word;
    size_t pos = 0;

    // Membagi kalimat menjadi kata-kata dan memasukkan ke dalam stack
    while ((pos = sentence.find(" ")) != string::npos) {
        word = sentence.substr(0, pos);
        wordStack.push(word);
        sentence.erase(0, pos + 1);
    }
    wordStack.push(sentence); // Memasukkan kata terakhir

    // Mencetak kata-kata dalam stack untuk membentuk kalimat terbalik
    cout << "Kalimat terbalik: ";
    while (!wordStack.empty()) {
        cout << wordStack.top() << " ";
        wordStack.pop();
    }
    cout << endl;
}

int main() {
    string input;

    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, input);

    reverseSentence(input);

    return 0;
}

```
#### Output:
![Screenshot 2024-05-05 204237](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-7-Stack/assets/162097297/dd42e03d-849f-4f35-9d58-9456a2c3b2de)

Kode diatas digunakan untuk membalik sebuah kalimat, saia masukkan minimal 3 dengan fungsi main getline cin input dan tentunya mendeklarasikan berupa string  dari reverseSentence untuk membelik kelimat yang dimasukkan. Dalam kalimat rifka suka tidur dipisahkan dulu dengan sentence.find dan dimasukkan ke stack menggunakan wordStack.push, setelah itu akan dihapus dengan sentence.erase supaya kata berikutnya diproses. kata yang dihasilkan adalah tidur suka rifka karena wordStack.top mengeluarkan kata teratas dan menghapusnya dengan wordStack.pop, proses diulangi sampai stack kosong atau proses terakhir.

#### Full code Screenshot:
![Screenshot 2024-05-05 204323](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-7-Stack/assets/162097297/c8d4fe6e-e601-4e65-864b-ee898e81eefe)


## Kesimpulan

Stack adalah urutan data yang bekerja secara LIFO (Last in First Out) yaitu data yang terakhir dimasukkan akan keluar pertama. stack dapat dimasukkan elemn dan menhapus elemen di list datanya, untuk memasukkan diberi operasi push dan untuk menghilangkan diberi pop. 

Bedanya dengan array adalah array menggunakan index, jika menginginkan suatu data tinggal panggil indexnya sementara stack tidak bisa karea data linear  atau LIFO. Jika di stack kita dapat menggunakan berbagai elemen tipe data yang berbeda dan di Array kita harus menggunakan elemn dengan tipe data yang sama. 

## Referensi
[1] Maulana Anieb. (2021), Memahami Stack, Struktur Data yang Mudahkan Programmer Jalankan Tugasnya, [Artikel] glints.

[2] (2023). Struktur Data Stack: Pengertian, Fungsi, Contoh dan Kelebihan [Artikel] , LamanIT.com

[3] Yoga Pristyanto*, Acihmah Sidauruk, Atik Nurmasani. (2022), Klasifikasi Penyakit Diabetes Pada Imbalanced Class Dataset
Menggunakan Algoritme Stacking, Fakultas Ilmu Komputer, Program Studi S1Sistem Informasi, Universitas Amikom Yogyakarta, Yogyakarta, Indonesia: JURNAL MEDIA INFORMATIKA BUDIDARMA.