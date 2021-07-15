#include <iostream>

using namespace std;

bool finished = false;

int MAXCANDIDATES = 5;

bool is_a_solution(int a[], int k, int n)
{
    return k == n;
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void process_solution(int a[], int k)
{
    int i;
    cout << "{ ";
    for (i = 1; i <= k; i++)
    {
        if (a[i] == true)
        {
            cout << i;
            if (i != k)
            {
                cout << " ";
            }
        }
    }
    cout << " }" << endl;
}

void backtrack(int a[], int k, int input)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if (is_a_solution(a, k, input))
    {
        process_solution(a, k);
    }
    else
    {
        k = k + 1;
        construct_candidates(a, k, input, c, &ncandidates);
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            backtrack(a, k, input);
            if (finished)
            {
                return;
            }
        }
    }
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    backtrack(a, 0, 4);
    // The quick brown fox jumps over the lazy dog
    return 0;
}