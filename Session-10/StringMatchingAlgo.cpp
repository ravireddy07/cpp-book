#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long int

class Node {
public:
  char data;
  bool isTeriminal;
  unordered_map<char, Node*> children;

  Node(char data, bool isTeriminal) {
    this-> data  = data;
    this -> isTeriminal = isTeriminal;
  }
};


void insert(Node *root, string str) {
  Node *temp = root;
  for(int i=0;i<str.size();i++) {
    char ch = str[i];
    if(temp -> children.find(ch) != temp-> children.end()) {
      temp = temp->children[ch];
    }
    else {
      if(i<str.size()-1) {
        temp -> children[ch] = new Node(ch, false);
        temp = temp -> children[ch];
      }
      else {
        temp ->children[ch] = new Node(ch, true);
        temp = temp ->children[ch];
      }
    }
  }
}

bool search(Node *root, string str) {
  Node *temp = root;
  for(int i=0;i<str.size();i++) {
    char ch = str[i];
    if(temp->children.find(ch) == temp->children.end()) {
      return false;
    }
    else {
      temp = temp ->children[ch];
    }
  }
  return temp->isTeriminal;
}

int main(int argc, char const *argv[]) {
  Node *root = new Node('\0', false);
  insert(root, "ape");
  insert(root, "apple");
  insert(root, "apie");
  insert(root, "man");
  insert(root, "mango");
  insert(root, "apngo");
  cout<<search(root, "man");
  return 0;
}
