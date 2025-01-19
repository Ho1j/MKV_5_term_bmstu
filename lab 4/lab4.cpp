#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(vector<int> part, int size, int l, int u) {
    if (l > part[size - 1] || part[size - 1] > u)
        return 1;
    return 0;
}

void print_num(int n, vector<int> part, int len) {
    cout << n << " = ";
    for (int i = 0; i < len - 1; i++)
        cout << part[i] << " + ";
    cout << part[len - 1] << endl;
}

vector<int> init(int n, int iter) {
    vector<int> a;
    a.reserve(iter);
    for (int i = 0; i < iter - 1; i++)
        a.push_back(1);
    a.push_back(n - iter + 1);
    return a;
}

int find(vector<int> part, int len) {
    for (int i = len - 1; i >= 0; i--)
        if (part[i] + 2 <= part[len - 1])
            return i;
    return -1;
}

int last(vector<int> part, int n) {
    int a = n;
    for (int i = 0; i < part.size() - 1; i++)
        a -= part[i];
    return a;
}

void gindenburg(int n, int l, int u) {
    vector<int> partition;
    int a;
    for (int i = 1; i <= n; i++) {
        partition = init(n, i);
        if (check(partition, i, l, u))
            print_num(n, partition, i);
        while ((a = find(partition, i)) >= 0) {
            partition[a]++;
            for (int j = a + 1; j < i - 1; j++)
                partition[j] = partition[a];
            partition[i - 1] = last(partition, n);
            if (check(partition, i, l, u)) print_num(n, partition, i);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Incorrect number of arguments. Use n l u";
        return 1;
    }

    int n = stoi(argv[1]);
    int l = stoi(argv[2]);
    int u = stoi(argv[3]);

    if (n <= 0 || l <= 0 || u <= 0) {
        cout << "Invalid arguments. Must be > 0";
        return 1;
    }

    if (l > u) {
        cout << "Invalid l. Must be <= u";
        return 1;
    }

    gindenburg(n, l, u);
}
