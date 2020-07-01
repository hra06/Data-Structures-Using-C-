#include<string>
#include"TrieNode.h"

class Trie{
    TrieNode* root;
    
    public:
        Trie(){
            root = new TrieNode('\0');
        }
        
        void insertWord(TrieNode* root, string word){
            //Base Case
            if(word.size() ==0){
                root->isTerminal = true;
                return;
            }
            
            //Small Calculation
            int index = word[0]-'a';
            TrieNode *child;
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            
            //Recursive Call
            insertWord(child,word.substr(1));
        }
        
        void insertWord(string word){
            insertWord(root,word);
        }
        
        bool search(TrieNode* root, string word){
            if(word.size()==0){
                if(root->isTerminal == true){
                    return true;
                }
                return false;
            }
            
            //Small Calucaltion
            int index = word[0]-'a';
            if(root->children[index] !=NULL){
                return search(root->children[index],word.substr(1));
            }
            else{
                return false;
            }
        }
        
        bool search(string word){
            return search(root,word);
        }
};
