#include "iostream"
#include "helper.h"
#include "unordered_set"

struct Pair
{
    string value;
    int timestamp;
};

class TimeMap
{
public:
    unordered_map<string, vector<Pair>> m;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        if (!m.count(key))
        {
            m[key] = *new vector<Pair>();
        }
        m[key].push_back(Pair{timestamp : timestamp, value : value});
    }

    string get(string key, int timestamp)
    {
        vector<Pair> &pairs = m[key];
        int i = 0;
        int j = pairs.size() - 1;

        int last = -1;

        while (i <= j)
        {
            int m = (i + j) / 2;
            Pair md = pairs[m];
            if (md.timestamp == timestamp)
            {
                return md.value;
            }
            if (md.timestamp <= timestamp)
            {
                i = m + 1;
                last = m;
            }
            else
            {
                j = m - 1;
            }
        }


        if (last != -1)
        {
            return pairs[last].value;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    TimeMap *obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl;
    cout << obj->get("foo", 2) << endl;
    cout << obj->get("foo", 3) << endl;
}
