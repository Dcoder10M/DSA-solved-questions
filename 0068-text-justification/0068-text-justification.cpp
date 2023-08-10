
class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> currentLine;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int lineLength = words[i].length();
            int lastWordIndex = i;
            
            while (lastWordIndex + 1 < n && lineLength + words[lastWordIndex + 1].length() + 1 <= maxWidth) {
                lastWordIndex++;
                lineLength += words[lastWordIndex].length() + 1;
            }
            
            string line = words[i];
            int numWords = lastWordIndex - i;
            
            if (lastWordIndex < n - 1 && numWords > 0) {
                int totalSpaces = maxWidth - lineLength + numWords;
                int equalSpaces = totalSpaces / numWords;
                int extraSpaces = totalSpaces % numWords;
                
                for (int j = i + 1; j <= lastWordIndex; j++) {
                    int spaces = (j - i <= extraSpaces) ? equalSpaces + 1 : equalSpaces;
                    line += string(spaces, ' ') + words[j];
                }
            }
            else {
                for (int j = i + 1; j <= lastWordIndex; j++) {
                    line += ' ' + words[j];
                }
                
                int remainingSpaces = maxWidth - line.length();
                line += string(remainingSpaces, ' ');
            }
            
            currentLine.push_back(line);
            i = lastWordIndex + 1;
        }
        
        return currentLine;
    }
};

