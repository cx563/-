#include<iostream>
#include<cstring>
using namespace std;
#define maxn 105
int leftone, chance;
char s[maxn],s2[maxn];
int win, loss;
void gess(char ch) {
    bool flag = true;
    int t = strlen(s);
    for (int i = 0; i < t; i++) {
        if (ch == s[i]) {
            s[i] = ' ';
            leftone--;
            flag = false;
        }
    }
    if (flag) chance--;
    if (!chance) loss = 1;
    if (!leftone) win = 1;
}

int main(void) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int rnd;
    while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd !=-1) {
        printf("Round %d\n", rnd);
        win = loss = 0;
        leftone = strlen(s);
        chance = 7;
        int u = strlen(s2);
        for (int i = 0; i < u; i++) {
            gess(s2[i]);
            if (win || loss) break;
        }
        if (win) printf("You win.\n");
        else if (loss) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}