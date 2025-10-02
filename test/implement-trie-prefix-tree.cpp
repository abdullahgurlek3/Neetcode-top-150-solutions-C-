#include "iostream"
#include "helper.h"
#include "map"

struct Node
{
    Node *children['z' - 'a' + 1];
    bool end;
};

class Trie
{
public:
    Node *root = new Node{};
    Trie()
    {
    }

    void insert(string word)
    {
        Node *local = root;
        for (char c : word)
        {
            if (local->children[c - 'a'])
            {
                local = local->children[c - 'a'];
            }
            else
            {
                local->children[c - 'a'] = new Node{};
                local = local->children[c - 'a'];
            }
        }
        local->end = true;
    }

    bool search(string word)
    {
        Node *local = root;
        for (char c : word)
        {
            if (local->children[c - 'a'])
            {
                local = local->children[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return local->end;
    }

    bool startsWith(string prefix)
    {
        Node *local = root;
        for (char c : prefix)
        {
            if (local->children[c - 'a'])
            {
                local = local->children[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{

    Trie *obj = new Trie();
    obj->insert("asdf");
    cout << obj->search("asdf")
         << endl;
    cout << obj->startsWith("as");
}
