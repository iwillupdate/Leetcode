/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function jo har node ke liye max path sum calculate karega
    int findMaxPathSum(TreeNode* root, int &maxi) {
        // Agar node NULL hai, toh path sum 0 hoga
        if (root == NULL) return 0;

        // \U0001f501 Recursively left subtree ka max path sum nikaal rahe
        // Agar left side ka path negative aaya, toh usko ignore karne ke liye max(0, ...)
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));

        // \U0001f501 Recursively right subtree ka max path sum
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        // ✅ Check karo ki current node se guzarte hue (left + right + root) path zyada hai kya
        // Agar haan, toh global max (maxi) ko update karo
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);

        // \U0001f519 Parent ko return karte time, hum sirf ek side ka path le sakte hain (left ya right)
        // Because path upar jaate hue straight hona chahiye (tree mein cycle allowed nahi)
        return root->val + max(leftMaxPath, rightMaxPath);
    }

    // Main function jo answer return karega
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Initially maximum path sum ko sabse chhoti value pe set kiya
        findMaxPathSum(root, maxi); // DFS traversal start
        return maxi; // Final max path sum return karo
    }
};

/*
\U0001f9e0 Simple Explanation:
Har node pe hum check karte hain ki left aur right side se kitna max path aa sakta hai (negative ko ignore karke).

Fir left + right + root ka total calculate karke, global max update karte hain.

Jab upar return karte hain, tab sirf ek hi side ka path return karte hain — because tree path me hum split nahi kar sakte (kyunki wo path cycle ban jaayega).

Aise recursively karte karte final answer milta hai maxi me.

\U0001f4cc Return & Update ka Difference:
Task	Explanation
return root->val + max(left, right)	Ek straight path ka sum parent ko bhejne ke liye
maxi = max(maxi, left + right + root)	Jab current node pe turn leke pura best path check karte hain

*/