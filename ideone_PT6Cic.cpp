#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *left,*right;
    vector<int>v;
};
int character[26];
vector<char>vchar;
void print(vector<int>bit)
{
    for(int i=0;i<bit.size();i++) {
        cout << bit[i];
    }
    cout << endl;
}
void printlist(node *root)
{
    if(root == NULL) {
        return ;
    }
    print(root->v);
    printlist(root->left);
    printlist(root->right);
    return ;
}
vector<int> bitvector(string s,int l,int r,int ch)
{
    vector<int>bit;
    if(l == r) {
        for(int i=0;i<s.length();i++)
            bit.push_back(ch);
        return bit;
    }
    int m = (l+r)/2;
    for(int i=0;i<s.length();i++) {
        int found = 1;
        for(int j=l;j<=m;j++) {
            if(s[i] == vchar[j])
               found = 0;
        }
        bit.push_back(found);
    }
    return bit;
}
vector<string> parallelSplit(string s,vector<int>bit)
{
    string s1="",s2 = "";
    vector<string>vs;
    for(int i=0;i<bit.size();i++) {
        if(bit[i] == 0)
            s1 += s[i];
        else
            s2 += s[i];
    }
    vs.push_back(s1);
    vs.push_back(s2);
    return vs;
}
node * rwTree(string s,int l,int r,int ch)
{
    node *temp = new node();
    if(l == r) {
        temp->left = NULL;
        temp->right = NULL;
        temp->v = bitvector(s,l,r,ch);
        return temp;
    }
    temp->v = bitvector(s,l,r,ch);

    vector<string>vs = parallelSplit(s,temp->v);
    temp->left = rwTree(vs[0],l,(l+r)/2,0);
    temp->right = rwTree(vs[1],(l+r)/2+1,r,1);
    return temp;
}
int main()
{
    string s;
    cin >> s;
    node *root;
    int len = s.length();
    for(int i=0;i<len;i++) {
        character[s[i]-'a']=1;
    }
    for(int i=0;i<26;i++) {
        if(character[i] > 0) {
            vchar.push_back((char)('a'+i));
        }
    }
    int l=0,r = vchar.size();
    root = rwTree(s,l,r-1,0);
    printlist(root);
}
