
struct Node{
    Node* next[26] = {}; 
    bool is_word = false; 
}; 

class WordDictionary {
public:
    Node* root; 
    WordDictionary() {
        root = new Node(); 
    }
    
    void addWord(string word) {
        Node* curr = root; 
        for(char x: word)
        {
            int i = x-'a'; 
            if(!curr->next[i])
            {
                curr->next[i] = new Node(); 
            }
            curr = curr->next[i]; 
        }
        curr->is_word = true; 
    }
    bool dfs(string word, int index, Node* curr)
    {
       if(index==word.size())return curr->is_word;
       if(word[index]!='.')
       {
            if(!curr->next[word[index]-'a'])return false; 
            return dfs(word, index+1, curr->next[word[index]-'a']); 
       }
       else
       {
         for(char x='a'; x<='z'; x++)
         {
            if(curr->next[x-'a'])
            {
                if(dfs(word, index+1, curr->next[x-'a']))return true; 
            }
         }
       }

       return false; 
    }
    bool search(string word) {
        Node* curr = root; 
        return dfs(word, 0, curr); 
       
    }
};
