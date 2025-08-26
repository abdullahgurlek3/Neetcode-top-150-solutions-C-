#include "iostream"

using namespace std;

template <typename T>
void print_v(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T>
void print_ar(T ar[]){
    cout << ar[0];
}

int main()
{
    vector<long> v;
    v.push_back(1);
    v.push_back(1 << 1);
    v.push_back(1 << 2);
    v.push_back(1 << 3);

    print_v(v);

    int ar[12];
    ar[0]=123;
    print_ar(ar);
}