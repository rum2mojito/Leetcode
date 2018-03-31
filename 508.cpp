// 508. Most Frequent Subtree Sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef pair<int, int> PAIR;  
  
    bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {  
      return lhs.second < rhs.second;  
    }  

    struct CmpByValue {  
      bool operator()(const PAIR& lhs, const PAIR& rhs) {  
        return lhs.second > rhs.second;  
      }  
    }; 
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        map<int,int> sub;
        subSum (root, sub);
        vector<PAIR> Try(sub.begin(),sub.end());
        sort(Try.begin(), Try.end(), CmpByValue());
        int max = Try[0].second;
        for (int i=0;i<Try.size();i++) {
            if (Try[i].second == max) {
                res.push_back(Try[i].first);
            }
            else break;
        }
        return res;
    }
    
    int subSum (TreeNode* root, map<int,int> &res) {
        if (root == NULL) return 0;
        int k = subSum(root->left, res) + subSum(root->right, res) + root->val;
        map<int,int>::iterator iter;
        iter = res.find(k);
        if (iter != res.end()) iter->second++;
        else res[k] = 1;
        return k;
    }
};
