#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node{

public:
    string key;
    T value;
    Node *next;

    Node(string key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }

};

template <typename T>

class hash_table{

    Node<T> **table;
    int cs;
    int ts;

    int hash_fn(string key){

        int i = 0;
        int pow = 1;

        for(auto x : key){
            i = (i+x*pow)%ts;
            pow = (pow*10)%ts;
        }
        return i;
    }

    void rehash(){

        Node<T> **oldTable = table;
        int oldTs = ts;

        ts = 2*ts+1;
        cs = 0;
        table = new Node<T>*[ts];

        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }

        for(int i=0;i<oldTs;i++){

            Node<T> *temp = oldTable[i];

            while(temp!=NULL){
                string key = temp->key;
                T value = temp->value;
                insert_hash(key,value);
                temp = temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

public:
    hash_table(int default_size = 10){
        cs = 0;
        ts = default_size;

        table = new Node<T>*[ts];

        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
    }

    void insert_hash(string key, T val){

        int idx = hash_fn(key);

        Node<T>* n = new Node<T>(key,val);

        n->next = table[idx];
        table[idx] = n;

        cs++;
        float load_factor = cs/float(ts);
        if(load_factor>0.7){
            rehash();
        }
    }

    T* search_hash(string key){
        int idx = hash_fn(key);

        Node<T> *temp = table[idx];

        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp = temp->next;
        }

        return NULL;
    }

};

#endif
