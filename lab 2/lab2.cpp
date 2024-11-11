#include <iostream>
#include <vector>

using namespace std;

void ShiftPerm(vector<int>& curr_vec, int k)
{
    int temp = curr_vec[k];
    for (int i = k; i > 0; i--)
    {
        curr_vec[i] = curr_vec[i - 1];
    }
    curr_vec[0] = temp;
}

bool CheckWhite(vector<int>& curr_vec, int &white_counter)
{
    for (int i = 0; i < 5; i++)
    {
        if ((curr_vec[i] + i) % 2 != 0)
        {
            return false;
            break;
        }
        if (i == 4)
        {
            white_counter++;
            return true;
        }
    }
}

void PrintResult(vector<int>& curr_vec, bool check_white_result)
{
    int col[5] = { 1, 2, 3, 4, 5 };
    char row[5] = { 'a', 'b', 'c', 'd', 'e' };
    for (int i = 0; i < 5; i++)
    {
        cout << row[i] << col[curr_vec[i]] << " ";
    }
    if (check_white_result)
    {
        cout << "(all white)";
    }
    cout << endl;
}

int main() 
{
    int counter = 1;
    int white_counter = 0;
    vector<int> curr_vec = { 0, 1, 2, 3, 4 };
    int j = 4;
    int n = j;

    PrintResult(curr_vec, CheckWhite(curr_vec, white_counter));

    while (j > 0)
    {
        ShiftPerm(curr_vec, j);
        if (curr_vec[j] != j)
        {
            PrintResult(curr_vec, CheckWhite(curr_vec, white_counter));
            counter++;
            j = n;
        }
        else
        {
            j--;
        }
    }
    cout << counter << endl;
    cout << white_counter;
}