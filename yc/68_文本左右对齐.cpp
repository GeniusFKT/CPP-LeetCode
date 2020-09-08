#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector <string> ans;
        string line;
        int length = words[0].size();
        int begin = 0;

        for (int i = 1; i < words.size(); ++i) {
            if (length + words[i].size() + 1 <= maxWidth) {
                length += (words[i].size() + 1);
            }
            else {
                ans.push_back(this->buildOneLineWithIndex(words, begin, i - 1, length, maxWidth));
                begin = i;
                length = words[i].size();
            }
        }

        ans.push_back(this->buildOneLineWithIndex(words, begin, words.size() - 1, length, maxWidth, true));
        return ans;
    }

    string buildOneLineWithIndex(vector<string>& words, int head, int rear, int length, int maxWidth, bool isLast = false) {
        string line = "";
        
        if (isLast) {
            for (int i = head; i <= rear; ++i) {
                if (i != rear)
                    line += (words[i] + " ");
                else
                    line += words[i];
            }
            
            line += this->buildSpace(maxWidth - line.size());
        }
        else {
            int numOfSpace = maxWidth - (length - (rear - head));
            if (rear == head) {
                line += words[head];
                line += this->buildSpace(numOfSpace);
            }
            else {
                vector <int> allSpaces;
                int avg = numOfSpace / (rear - head);
                int remainder = numOfSpace % (rear - head);

                for (int i = 0; i < rear - head; ++i) {
                    if (i < remainder) {
                        allSpaces.push_back(avg + 1);
                    }
                    else {
                        allSpaces.push_back(avg);
                    }
                }

                for (int i = head; i < rear; ++i) {
                    line += words[i];
                    line += this->buildSpace(allSpaces[i-head]);
                }

                line += words[rear];
            }
        }

        return line;
    }

    string buildSpace(int n) {
        string a = "";
        for (int i = 0; i < n; ++i) {
            a += " ";
        }
        return a;
    }
};