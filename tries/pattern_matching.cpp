//Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
	
    
    bool search(TrieNode* root, string word){
        if(word.size()==0){
            return true;
        }
        
        
        int index=word[0]-'a';
        
        if(root->children[index]){
            return search(root->children[index], word.substr(1));

        }
        else{
            return false;

        }
        
        
        
    }
    
    bool search(string pattern){
        return search(root, pattern);
    }
    
    
    bool patternMatching(vector<string> vect, string pattern) {
        
        for(int i=0;i<vect.size();i++){
            
            while(vect[i].size()!=0){
                insertWord(vect[i]);
                vect[i]=vect[i].substr(1);
            }
        }
        
		return search(pattern);
        
    }
};
