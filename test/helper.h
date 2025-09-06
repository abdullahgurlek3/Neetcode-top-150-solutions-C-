
using namespace std;
#include <set>

template <typename T>
void print_v(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T,typename V>
void print_map(unordered_map<T, V> v)
{
    for (const auto &i : v)
    {
        cout <<"map: "<< i.first << ":" << i.second<<", " ;
    }
    cout << endl;
}

template <typename T>
void print_v_ar(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << ",";
    }
    cout << endl;
}

template <typename T>
void print_s(set<T> v)
{
    for (const auto &c : v)
    {
        cout << c << " ";
    }
    cout << endl;
}

template <typename T>
void print_ar(T ar[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << ar[i] << " ";
    }
}
