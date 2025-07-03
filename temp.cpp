#include<iostream>

using namespace std;

struct node{
    char data;
    node* children[256];
    bool isTerminal;
    node(char ch){
        data=ch;
        isTerminal=false;
        for(int i=0; i<256; i++){
            children[i]=NULL;
        }
    }
};

class Trie{
    public:
    node* root;
    Trie(){
        root=new node('\0');
    }

    void insertUtilWord(node* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'\0';
        node* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new node(word[0]);
            root->children[index]=child;
        }

        insertUtilWord(child,word.substr(1));
    }
    void insert(string word){
        insertUtilWord(root,word);
    }

    bool searchUtilWord(node* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'\0';
        if(root->children[index]!=NULL){
            return searchUtilWord(root->children[index],word.substr(1));
        }else{
            return false;
        }
    }
    bool search(string word){
        if(searchUtilWord(root,word)){
            return true;
        }else{
            return false;
        }
    }

    void deleteUtilWord(node* root,string word){
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'\0';
        node* child=root->children[index];
        deleteUtilWord(child,word.substr(1));

        bool isPresent=false;
        for(int i=0; i<256; i++){
            if(root->children[index]->children[i]!=NULL){
                isPresent=true;
            }
        }

        if(!isPresent && !child->isTerminal){
            delete(child);
            root->children[index]=NULL;
        }

    }

    void deleteWord(string word){
        if(search(word)){
            deleteUtilWord(root,word);
        }else{
            cout<<"word not present"<<endl;
        }
    }
};

int main(){
    Trie *t=new Trie();
    t->insert("Ram");
    t->insert("Radha");
    t->insert("Ra");
    cout<<t->search("Ram")<<endl;
    cout<<t->search("Ra")<<endl;
    t->deleteWord("Ram");
    cout<<t->search("Ram")<<endl;
    cout<<t->search("Ra")<<endl;
    return 0;
}