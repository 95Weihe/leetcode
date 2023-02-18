class Trie {
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        children.resize(26,nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(int i=0; i<word.length(); i++){
            if(node->children[word[i]-'a']==nullptr){
                node->children[word[i]-'a'] = new Trie();
            }
            node = node->children[word[i]-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i=0; i<word.length(); i++){
            if(node->children[word[i]-'a']==nullptr)
                return false;
            node = node->children[word[i]-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i=0; i<prefix.length(); i++){
            if(node->children[prefix[i]-'a']==nullptr)
                return false;
            node = node->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */