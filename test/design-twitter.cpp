#include "iostream"
#include "helper.h"
#include "map"

class Twitter
{
public:
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> m;
    map<int, set<int>> f;
    int index = 0;
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        if (m.count(userId))
        {
            m[userId].push({index, tweetId});
        }
        else
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
            p.push({index, tweetId});
            if (p.size() > 10)
            {
                p.pop();
            }

            m[userId] = p;
        }
        index++;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pl(m[userId]);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> r;
        while (pl.size() > 0)
        {
            r.push(pl.top());
            pl.pop();
            if (r.size() > 10)
            {
                r.pop();
            }
        }
        if (f.count(userId))
        {
            set<int> s = f[userId];
            for (const auto i : s)
            {
                if (m.count(i))
                {
                    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pl(m[i]);
                    while (pl.size() > 0)
                    {
                        r.push(pl.top());
                        pl.pop();
                        if (r.size() > 10)
                        {
                            r.pop();
                        }
                    }
                }
            }
        }
        vector<int> ret;
        while (r.size() > 0)
        {
            ret.push_back(r.top().second);
            r.pop();
        }

        int i = 0;
        int j = ret.size() - 1;
        while (i < j)
        {
            swap(ret[i], ret[j]);
            i++;
            j--;
        }

        return ret;
    }

    void follow(int followerId, int followeeId)
    {
        if (f.count(followerId))
        {
            f[followerId].insert(followeeId);
        }
        else
        {
            set<int> s;
            s.insert(followeeId);
            f[followerId] = s;
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        f[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter *obj = new Twitter();
    obj->postTweet(1, 1);
    print_v(obj->getNewsFeed(1));
    obj->follow(1, 2);
    obj->unfollow(1, 2);
}
