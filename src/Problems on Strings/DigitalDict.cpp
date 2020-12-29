#include <iostream>
#include <map>
#define hashmap map<char, node *>
#define ll long long int
using namespace std;

class node
{
public:
  char data;
  hashmap h;
  bool isterminal;
  node(char ch)
  {
    data = ch;
    isterminal = false;
  }
};

class trie
{
public:
  node *root;
  trie()
  {
    root = new node('\0');
  }
  void addword(string word)
  {
    node *temp = root;
    char ch;
    for (int i = 0; word[i] != '\0'; i++)
    {
      ch = word[i];
      if (temp->h.count(ch) == 0)
      {
        node *child = new node(ch);
        temp->h[ch] = child;
        temp = child;
      }
      else
      {
        temp = temp->h[ch];
      }
    }
    temp->isterminal = true;
  }

  void print(node *temp, string word)
  {
    if (temp->h.empty())
    {
      cout << word << endl;
      return;
    }
    if (temp->isterminal)
    {
      cout << word << endl;
    }
    node *t;
    string w;
    for (auto it = temp->h.begin(); it != temp->h.end(); it++)
    {
      t = temp->h[it->first];
      w = word + it->first;
      print(t, w);
    }
    return;
  }

  bool search(string word)
  {
    node *temp = root;
    char ch;
    for (int i = 0; word[i] != '\0'; i++)
    {
      ch = word[i];
      if (temp->h.count(ch))
      {
        temp = temp->h[ch];
      }
      else
      {
        return false;
      }
    }
    print(temp, word);
    return true;
  }
};

int main()
{
  ll n, i;
  cin >> n;
  string s;
  trie t;
  for (i = 0; i < n; i++)
  {
    cin >> s;
    t.addword(s);
  }
  ll q, val;
  cin >> q;
  for (i = 0; i < q; i++)
  {
    cin >> s;
    val = t.search(s);
    /*if(val==false){
     // cout<<s<<"  "<<"No suggestions"<<endl;
    }
    else{
       // cout<<s<<" "<<"found"<<endl;
    }*/
  }
}
