#include<bits/stdc++.h>
using namespace std;
class Trienode{
public:
    bool eow;
    Trienode* next[26];
    Trienode(){
        eow=false;
        for(int i=0;i<26;i++)next[i]=nullptr;
    }
};
class Trie{
private:
    Trienode* root;
public:
    Trie(){
        root=new Trienode();
    }
    void insertword(const string &s){
        Trienode* cur=root;
        for(char ch:s){
            int idx=ch-'a';
            if(cur->next[idx]==nullptr)cur->next[idx]=new Trienode();
            cur=cur->next[idx];
        }
        cur->eow=true;
    }
    bool searchword(const string &s){
        Trienode* cur=root;
        for(char ch:s){
            int idx=ch-'a';
            if(cur->next[idx]==nullptr)return false;
            cur=cur->next[idx];
        }
        return cur->eow;
    }
    bool startwith(const string &s){
        Trienode* cur=root;
        for(char ch:s){
            int idx=ch-'a';
            if(cur->next[idx]==nullptr)return false;
            cur=cur->next[idx];
        }
        return true;
    }
};
int main(){
    Trie t;
    t.insertword("antor");
    t.insertword("anto");
    cout<<t.searchword("anto")<<endl;
    cout<<t.startwith("ant")<<endl;
    return 0;
}
