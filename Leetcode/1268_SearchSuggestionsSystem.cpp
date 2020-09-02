// https://leetcode.com/problems/search-suggestions-system/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Trie{
        public:
        vector<Trie*> children;
        bool isEnd;
        
        Trie(){
            children = vector<Trie*> (26, nullptr);
            isEnd=false;
        }
        
        void addWord(string word){
            Trie* node=this;
            for(char c : word){
                if(node->children[c-'a']==nullptr)
                    node->children[c-'a']=new Trie();
                
                node=node->children[c-'a'];
            }
            node->isEnd=true;
        }
        
        void searchWord(vector<string>& result, string partial, int& count){
            Trie* node=this;
            if(count>2) return;
            if(node->isEnd==true){
                result.push_back(partial);
                count++;
            }
            for(int i=0; i<26; i++){
                if(node->children[i]!=nullptr){
                    partial += (i+'a');
                    node->children[i]->searchWord(result, partial, count);
                    partial.pop_back();
                }
            }
        }
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie=new Trie();
        int n=searchWord.size();
        vector<vector<string>> result;
        
        for(string product : products)
            trie->addWord(product);
        
        string partial="";
        for(int i=0; i<n; i++){
            if(trie->children[searchWord[i]-'a']==nullptr){
                while(i<n){
                    result.push_back({});
                    i++;
                }    
            }
            else{
                vector<string> cprefix;
                partial+=searchWord[i];
                trie=trie->children[searchWord[i]-'a'];
                int count=0;
                trie->searchWord(cprefix, partial, count);
                result.push_back(cprefix);
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<string> input = {"mobile","mouse","moneypot","monitor","mousepad"};
    vector<vector<string>> show = a.suggestedProducts(input,"mouse") << endl;
    return 0;
}
