#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[4], b[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3];
        bool ans = false;
        for (int c1 = 1; c1 <= 10; c1++) {
            for (int c2 = 1; c2 <= 10; c2++) {
                for (int c3 = 1; c3 <= 10; c3++) {
                    for (int c4 = 1; c4 <= 10; c4++) {
                        int c[4] = {c1, c2, c3, c4};
                        int ab = 0;
                        int ba = 0;
                        int ac = 0;
                        int ca = 0;;
                        int bc = 0;
                        int cb = 0;
                        for (int aa : a) {
                            for (int bb : b) {
                                for (int cc : c) {
                                    if (aa < bb) ab += 1;
                                    if (aa > bb) ba += 1;
                                    if (aa < cc) ac += 1;
                                    if (aa > cc) ca += 1;
                                    if (bb < cc) bc += 1;
                                    if (bb > cc) cb += 1;
                                }
                            }
                        }
                        ans |= ab < ba && bc < cb && ca < ac;
                        ans |= ab > ba && bc > cb && ca > ac;
                    }
                }
            }
        }
        if (ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}