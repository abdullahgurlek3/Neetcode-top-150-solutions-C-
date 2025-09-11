
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

template <typename T>
void print_matrix(vector<vector<T>> v)
{
    for (int y = 0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
        {
            cout << v[y][x]<<"\t";
        }
        cout << endl;
    };
}

template <typename T, typename V>
void print_map(unordered_map<T, V> v)
{
    for (const auto &i : v)
    {
        cout << "map: " << i.first << ":" << i.second << ", ";
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

vector<vector<int>> &convertStrToMatrix(string str)
{
    vector<vector<int>> *r = new vector<vector<int>>;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '[')
        {
            for (int j = i + 1; j < str.size(); j++)
            {
                if (str[j] == '[')
                {
                    string nm = "";
                    vector<int> v;
                    for (int k = j + 1; k < str.size(); k++)
                    {
                        if (str[k] == ']')
                        {
                            //cout << nm << endl;
                            v.push_back(stoi(nm));
                            break;
                        }
                        if (str[k] == ',')
                        {
                           // cout << nm << endl;
                            v.push_back(stoi(nm));
                            nm = "";
                        }
                        else
                        {
                            nm += str[k];
                        }
                    }
                    r->push_back(v);
                }
            }
        }
    }
    return *r;
}