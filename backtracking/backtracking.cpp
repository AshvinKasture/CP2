#include <iostream>

using namespace std;

void backtrack(char[], int, int);
void swap(char[], int, int);
void process_solution(char[], int);

const int MAXCANDIDATES = 5;

int main()
{
    int k = 0, length = 3;
    char a[MAXCANDIDATES] = {'a', 'b', 'c'};
    backtrack(a, k, length);
}

void backtrack(char a[], int k, int n)
{
    if (k == n)
        process_solution(a, k);
    else
    {
        for (int i = k; i < n; i++)
        {
            swap(a, k, i);
            backtrack(a, k + 1, n);
            swap(a, k, i);
        }
    }
}
void swap(char a[], int i, int j)
{
    char temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void process_solution(char a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}
