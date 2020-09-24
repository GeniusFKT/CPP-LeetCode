#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool *isVisited = new bool [rooms.size()];
        for (int i = 0; i < rooms.size(); ++i) {
            isVisited[i] = false;
        }

        vector<int> q;
        q.push_back(0);
        isVisited[0] = true;

        while (q.size() > 0) {
            int room = q.back();
            q.pop_back();

            for (int i = 0; i < rooms[room].size(); ++i) {
                if (!isVisited[rooms[room][i]]) {
                    q.push_back(rooms[room][i]);
                    isVisited[rooms[room][i]] = true;
                }
            }
        }

        for (int i = 0; i < rooms.size(); ++i) {
            if (!isVisited[i]) {
                return false;
            }
        }

        return true;
    }
};