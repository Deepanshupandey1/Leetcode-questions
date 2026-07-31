class Solution {
public:
    struct TrieNode
    {
        bool endWord;
        int cnt;
        TrieNode*children[26];
    };
    TrieNode* root;
    TrieNode* getNode() 
    {
        TrieNode* newNode = new TrieNode();
        newNode->endWord = false;
        newNode->cnt = 0;

        for (int i = 0; i < 26; i++)
            newNode->children[i] = NULL;

        return newNode;
    }
    void insert(string word) 
    {
        TrieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) 
        {
            int index = word[i] - 'a';

            if (crawler->children[index] == NULL)
                crawler->children[index] = getNode();

            crawler = crawler->children[index];
            crawler->cnt++;
        }

        crawler->endWord = true;
    }
    int getScore(string word)
    {
        TrieNode* crawler = root;
        int score = 0;

        for (char ch : word)
        {
            int index = ch - 'a';
            crawler = crawler->children[index];
            score += crawler->cnt;
        }

    return score;
}
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        root = getNode();
        for (string word : words)
            insert(word);
        vector<int> ans;
        for (string word : words)
            ans.push_back(getScore(word));
        return ans;
    }  
};