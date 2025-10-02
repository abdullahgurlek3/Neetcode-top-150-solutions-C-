#include "iostream"
#include "helper.h"
#include "map"

struct Trie
{
    bool end;
    Trie *children['z' - 'a' + 1];
};

class WordDictionary
{
public:
    Trie *trie = new Trie();
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        Trie *local = trie;
        for (char c : word)
        {
            if (local->children[c - 'a'])
            {
                local = local->children[c - 'a'];
            }
            else
            {
                local->children[c - 'a'] = new Trie{};
                local = local->children[c - 'a'];
            }
        }
        local->end=true;
    }

    bool search(string word, Trie *local)
    {
        if (word.size()==0 && !local)
        {
            return false;
        }
        int index = 0;
        for (char c : word)
        {
            if (c == '.')
            {
                for (int i = 0; i < 'z' - 'a' + 1; i++)
                {
                    if (local->children[i] && search(word.substr(index + 1), local->children[i]))
                        return true;
                }
                return false;
            }
            else if (local->children[c - 'a'])
            {
                local = local->children[c - 'a'];
            }
            else
            {
                return false;
            }
            index++;
        }
        return local->end;
    }

    bool search(string word)
    {
        Trie *local = trie;
        return search(word, local);
    }
};

int main()
{

    WordDictionary *obj = new WordDictionary();
    obj->addWord("aa");
    cout << obj->search(".a");
}
