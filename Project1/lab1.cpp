#include <iostream>
#include <bitset>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const char letters[] = { 'È', 'Í', 'Ò', 'Å', 'Ã', 'Ð', 'À', 'Ë' };
    int n = 8;
    int m = 4;
    int counter = 0;

    int comb = (1 << m) - 1;
    int limit = 1 << n;

    while (comb < limit)
    {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (comb & (1 << i)) {
                cout << letters[i] << " ";
            }
        }
        bitset<8> x(comb);
        cout << "} " << x << " ";
        counter++;
        cout << counter;
        cout << endl;

        int u = comb & -comb;
        int v = comb + u;     
        if (u == 0) break;            
        comb = (((comb ^ v) >> 2) / u) | v;
    }

    return 0;
}
