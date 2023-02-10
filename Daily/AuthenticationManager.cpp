#include <al_zzh.h>

using namespace std;

class AuthenticationManager {
public:
    int timeT = 0;
    unordered_map<string,int> token;
    AuthenticationManager(int timeToLive) {
        timeT = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        token[tokenId] = currentTime + timeT;
    }
    
    void renew(string tokenId, int currentTime) {
        if(!token.count(tokenId)) {
            return;
        }else if (currentTime < token[tokenId])
        {
            token[tokenId] = currentTime + timeT;
        }
        return;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto s : token) {
            if (s.second > currentTime) {
                ans++;
            }else {
                string era= s.first;
                token.erase(era);
            }
        }
        return ans;
    }
};