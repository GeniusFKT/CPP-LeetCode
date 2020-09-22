#include <iostream>
#include <string>

using namespace std;

class KMP {
private: 
    string pattern;
    int *next;

    void buildNext() {
        next = new int [pattern.size() + 1];

        int i = 0;
        int j = -1;
        next[i] = j;

        while (i < pattern.size()) {
            if (j == -1 || pattern[i] == pattern[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
    }

public:
    KMP(string s) {
        pattern = s;
        buildNext();
    }

    void printNext() {
        for (int i = 0; i <= pattern.size(); ++i) {
            cout << next[i] << endl;
        }
    }

    int stringMatch(string s) {
        int ptr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (ptr == -1)
                ptr = 0;

            if (ptr == pattern.size())
                return i - ptr;

            if (s[i] == pattern[ptr]) {
                ptr++;
            }
            else {
                while (ptr != -1) {
                    ptr = next[ptr];
                    if (s[i] == pattern[ptr]) {
                        ptr++;
                        break;
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    string a = "ABCDABD";
    string b = "";
    KMP k = KMP(a);
    k.printNext();

    cout << k.stringMatch("BBC ABCDAB ABCDABCDABDE") << endl;
}

