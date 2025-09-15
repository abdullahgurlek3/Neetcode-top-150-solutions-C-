#include "iostream"
#include "helper.h"
#include "map"

struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;
};

class LRUCache
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int capacity;
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            if (mp[key] == head)
            {
                /* code */
            }
            else if (mp[key] == tail)
            {
                Node *nt = tail->prev;
                Node *current = tail;
                tail->prev->next = nullptr;
                tail->prev = nullptr;
                tail = nt;
                head->prev = current;
                current->next = head;
                head = current;
            }
            else
            {
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                mp[key]->next = head;
                head->prev = mp[key];
                head = mp[key];
            }
            return mp[key]->value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            mp[key]->value = value;
            get(key);
        }
        else
        {
            mp[key] = new Node{value : value, key : key};
            if (head == nullptr)
            {
                head = mp[key];
                tail = mp[key];
            }
            else
            {
                head->prev = mp[key];
                mp[key]->next = head;
                head = mp[key];
            }
            if (mp.size() > capacity)
            {
                Node *current = tail;
                tail->prev->next = nullptr;
                tail=tail->prev;
                mp.erase(current->key);
            }
        }
    }
};

int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 2);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;    
    cout << obj->get(4) << endl;

}
