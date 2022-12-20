#include <bits/stdc++.h>
#include "hash_table.h"
#include "trie.h"
using namespace std;

int main()
{
    hash_table<string> h;

    Trie t;

    while(1)
    {
        cout << "Enter 1 to Add" << endl;
        cout << "Enter 2 to Search" << endl;
        cout << "Enter 3 to Exit" << endl;
        int x;
        cin >> x;

        if(x==1)
        {
            cout << "How many number you want to add?" << endl;
            int n;
            cin >> n;

            for(int i=0; i<n; i++)
            {
                cout << "Enter Name" << endl;
                string name;
                cin >> name;
                cout << "Enter Phone Number" << endl;
                string phoneNum;
                cin >> phoneNum;
                t.insert_trie(name);
                h.insert_hash(name,phoneNum);
            }
        }
        else if(x==2){
            cout << "Enter Name/Enter first few later of name" << endl;
            string name;
            cin >> name;
            t.search_trie(name,h);
        }
        else{
            break;
        }
    }


//
//    t.insert_trie("shishir");
//
    //t.insert_trie("feroz");
    //h.insert_hash("feroz",100);
//    //int *k = h.search_hash("feroz");
//    t.insert_trie("shis");
//    t.insert_trie("shishir455");
//
//    //cout << *k << endl;
    //t.search_trie("fer",h);
}

