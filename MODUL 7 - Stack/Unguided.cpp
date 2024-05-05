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
