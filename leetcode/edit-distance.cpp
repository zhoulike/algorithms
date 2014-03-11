class Solution {
public:
    int minDistance(string word1, string word2) {           
        vector<vector<int> > dis(word1.size() + 1, vector<int>(word2.size() + 1));  //+1 makes coding easy
        for (int i = 0; i < dis.size(); ++i)
        	dis[i][0] = i;
        for (int j = 0; j < dis[0].size(); ++j)
        	dis[0][j] = j;

        for (int i = 1; i < dis.size(); ++i) {
        	for (int j = 1; j < dis[0].size(); ++j) {
        		if (word1[i - 1] == word2[j - 1])
        			dis[i][j] = dis[i - 1][j - 1];  //the same character
        		else
        			dis[i][j] = dis[i - 1][j - 1] + 1; //replace a character

        		dis[i][j] = min(dis[i][j], dis[i - 1][j] + 1);  //delete a character
        		dis[i][j] = min(dis[i][j], dis[i][j - 1] + 1);  //insert a character
        	}
        }

        return dis.back().back();
    }
};