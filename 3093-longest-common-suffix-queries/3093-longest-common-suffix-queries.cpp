class Node{
public:
    int smallestidx;
    Node* children[26];

    Node(){
        this->smallestidx=INT_MAX;
        for(int i=0;i<26;i++) children[i]=nullptr;
    }
    ~Node(){
        for(int i=0;i<26;i++) delete children[i];
    }
};

class Solution {
public:
    void insert(Node* &root,vector<string>& s,int &idx){
        Node* curr=root;
        int l=s[idx].size();

        for(int i=l-1;i>=0;i--){
            char &ch=s[idx][i];
            if(curr->children[ch-'a']){
                curr=curr->children[ch-'a'];
                if(s[curr->smallestidx].size()>l) curr->smallestidx=idx;
            }
            else{
                Node* newNode = new Node();
                newNode->smallestidx=idx;
                curr->children[ch-'a']=newNode;
                curr=newNode;
            }
        }
        return;
    }

    int searchPrefix(Node* &root,string &s){
        Node* curr=root;

        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            if(!curr->children[ch-'a']) return curr->smallestidx;
            curr=curr->children[ch-'a'];
        }
        return curr->smallestidx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Node* root = new Node();
        vector<int>ans;

        int minidx=0;
        for(int i=0;i<wordsContainer.size();i++){
            insert(root,wordsContainer,i);
            if(wordsContainer[i].size()<wordsContainer[minidx].size()) minidx=i;
        }
        root->smallestidx=minidx;

        for(int i=0;i<wordsQuery.size();i++)    ans.push_back(searchPrefix(root,wordsQuery[i]));
        delete root;
        return ans;
    }
};