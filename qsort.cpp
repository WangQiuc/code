// kick start
// wangqc
#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>

using namespace std;

const int K = 50;

int n;
vector<int> a;

unsigned long get_tick_count()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC,&ts);
	return ts.tv_sec*1000000 + ts.tv_nsec/1000;
}

void print(int l, int r)
{
    for(int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << endl;
}

void isort(int l, int r)
{
    for (int i = l; i < r; i++)
        for (int j = i+1; j > l && a[j] < a[j-1]; j--)
            swap(a[j], a[j-1]);
    return;
}

void qsort(int l, int r)
{
    if (r - l <= K) 
    {
        isort(l, r);
        return;
    }
    srand(time(NULL));
    swap(a[l+rand()%(r-l)], a[l]);
    int p = a[l], i = l, j = l+1, k = r;
    while (j <= k)
    {
        if (a[j] < p)
            swap(a[i++], a[j++]);
        else if (a[j] > p)
            swap(a[j], a[k--]);
        else
            j++;
    }
    qsort(l, i-1);
    qsort(j, r);
}

void solve()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    qsort(0, n-1);
    print(0, n-1);
}

int main()
{ 
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; kase++)
    {
        cout << "Case #" << kase << ":\n";
        unsigned long t = get_tick_count();
        solve();
        cout << "Took " << (get_tick_count()-t) / 1000. << " ms.\n";
    }
    return 0;
}