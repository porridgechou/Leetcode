#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        for (int j = 1; j < folder.size();) {
            if (folder[j].size() > folder[j-1].size() && folder[j].substr(0, folder[j-1].size()+1) == folder[j-1]+'/'){
                folder.erase(folder.begin()+j);
            }else{
                j++;
            }
        }
        return folder;
    }
};