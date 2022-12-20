#include <bits/stdc++.h>
#include "hash_table.h"
using namespace std;

class Trie;

class Nodee{
    char data;
    unordered_map<char,Nodee*>next;
    bool isEnd;

public:

    Nodee(char d){
        data = d;
        isEnd = false;
    }

    friend class Trie;

};

class Trie{
    Nodee *root;

public:
    Trie(){
        root = new Nodee('\0');
    }

    void insert_trie(string word){

        Nodee *temp = root;

        for(char x : word){
            if(temp->next.count(x)==0){
                Nodee *n = new Nodee(x);
                temp->next[x] = n;
            }
            temp = temp->next[x];
        }

        temp->isEnd = true;

    }

    void hmm(Nodee *temp,string word,hash_table<string> &h){

        if(temp->isEnd==true){
            cout << "Name : ";
            cout << word << endl;
            cout << "Phone Number : ";
            string *ptr = h.search_hash(word);
            cout << *ptr << endl;
        }

        for(auto i=temp->next.begin();i!=temp->next.end();i++){
            hmm(i->second,word+i->first,h);
        }

    }

    void search_trie(string word,hash_table<string> &h){

        Nodee *temp = root;

        for(char x : word){
            if(temp->next.count(x)==0){
                cout << "Name Not Found" << endl;
                break;
            }
            temp = temp->next[x];
        }
        hmm(temp,word,h);
    }
};
