#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    char in[1000];
    cout << "Введите строку: ";
    cin.getline(in, sizeof(in));

    char maxw[100];
    int maxc = 0;
    int curc = 0;
    char curw[100];

    for (int i = 0; in[i] != '\0'; ++i) {
        char c = in[i];

        if (c != ' ' && c != '\t') {
            curw[curc] = c;
            curc++;
        }
        else {
            curw[curc] = '\0';
            curc = 0;

            if (curw[0] != '\0') {
                int charc[256] = { 0 };

                for (int j = 0; j < strlen(curw); ++j) {
                    charc[curw[j]]++;
                }

                char mfc = '\0';
                int maxccount = 0;

                for (int j = 0; j < 256; ++j) {
                    if (charc[j] > maxccount) {
                        maxccount = charc[j];
                        mfc = static_cast<char>(j);
                    }
                }

                if (maxccount > maxc) {
                    maxc = maxccount;
                    strcpy_s(maxw, curw);
                }
            }
        }
    }

    if (maxc > 0) {
        cout << "Слово с максимальным количеством одинаковых символов: " << maxw << endl;
    }
    else {
        cout << "В строке нет слов." << endl;
    }

    return 0;
}
