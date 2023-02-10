#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

class MagicDictionary {
public:
    vector<string> MD;
    MagicDictionary() {
        
    }

    MagicDictionary(vector<string> dictionary) {
        
    }
    void printDict() {
        for (auto word : MD) {
            cout<<word<<endl;
        }
    }

    void buildDict(vector<string> dictionary) {
        MD = dictionary;
        sort(MD.begin(), MD.end(),[](string& a, string& b){
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        });
    }
    
    bool search(string searchWord) {
        for (auto word : MD){
            if (word.size() == searchWord.size()) {
                int diff = 0;
                for (int i = 0; i < word.size(); i++) {
                    if(word[i] != searchWord[i]) {
                        diff++;
                    }
                    if(diff > 1) {
                        break;
                    }
                }
                if (diff == 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    cout<<"1";
    vector<string> ans;
    ans.emplace_back("leecode");
    ans.emplace_back("hello");
    MagicDictionary magicDictionary(ans);
    magicDictionary.buildDict(ans);
    magicDictionary.printDict();
    // cout<<magicDictionary.search("hello"); // 返回 False
    // cout<<magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    // cout<<magicDictionary.search("hell"); // 返回 False
    // cout<<magicDictionary.search("leetcoded"); // 返回 False
}