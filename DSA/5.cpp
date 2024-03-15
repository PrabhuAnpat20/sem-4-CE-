#include <iostream>
using namespace std;
#define size 10

class node
{
public:
    string word;
    string meaning;
    node *next;

    node()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        next = NULL;
    }
};

class Hash
{
public:
    node *dict[size];

    Hash()
    {

        for (int i = 0; i < size; i++)
        {
            dict[i] = NULL;
        }
    }
    int gethash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            hash += int(key[i]);
        }
        cout << hash << endl;
        return hash % size;
    }
    void insert(string word, string meaning)
    {
        node *newnode = new node(word, meaning);
        int hash = gethash(word);
        if (dict[hash] != NULL)
        {
            while (dict[hash]->next)
            {
                dict[hash] = dict[hash]->next;
            }
            dict[hash]->next = newnode;
        }
        else
        {
            dict[hash] = newnode;
        }
        cout << "inserted" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            node *temp = dict[i];
            cout << i << ":";
            while (temp)
            {
                cout << temp->word << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void search(string word)
    {
        int hash = gethash(word);
        node *temp = dict[hash];
        bool b = 0;
        while (temp)
        {
            if (temp->word == word)
            {
                cout << "word :" << temp->word << "  "
                     << "meaning :" << temp->meaning << endl;
                b = 1;
                break;
            }
            temp = temp->next;
        }
      if(!b){
        cout<<"not found"<<endl;
      }
    }
};

int main()
{
    Hash h;
    h.insert("e", "dwdw");
    h.insert("a", "wdw");
    h.insert("e", "dwdw");

    h.print();
    h.search("aasaa");

    return 0;
}