#include <iostream>
using namespace std;
#define MAXLEN 100

typedef struct SString {
    int length;
    char ch[MAXLEN + 1];
    SString(const char *ch) {
        for (int i = 0; i != '\0'; i++) {
            this->ch[i] = ch[i];
            length++;
        }
    }
} SString;

int nxt[MAXLEN + 1];

void getNext(SString S, int nxt[]) {
    int i = 0, j = 0;
    nxt[0] = 0;
    while (i < S.length) {
        if (j == 0 || S.ch[i] == S.ch[j])
            nxt[++i] = ++j;
        else
            j = nxt[j];
    }
}

int Index_KMP(SString S, SString T, int pos) {
    int i = pos, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else
            j = nxt[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main() {
    const char *main_char = "abaabcaaadba", *mode_char = "bcaaa";
    SString S(main_char), T(mode_char);
    getNext(T, nxt);
    cout << Index_KMP(S, T, 0) << endl;
}