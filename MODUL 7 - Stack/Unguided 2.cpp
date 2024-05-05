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
