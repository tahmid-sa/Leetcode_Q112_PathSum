#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool sumHelper(TreeNode* root, int targetSum, int& currSum) {
    if (root != nullptr) {
        currSum += root->val;
        if (sumHelper(root->left, targetSum, currSum) == true) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr && currSum == targetSum) {
            return true;
        }

        if (sumHelper(root->right, targetSum, currSum) == true) {
            return true;
        }
        currSum -= root->val;
    }

    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int currSum = 0;

    return sumHelper(root, targetSum, currSum);
}

int main()
{
    TreeNode p7(7, nullptr, nullptr);
    TreeNode p2(3, nullptr, nullptr);
    TreeNode p11(11, &p7, &p2);
    TreeNode p4_1(4, &p11, nullptr);

    TreeNode p1(1, nullptr, nullptr);
    TreeNode p4(4, nullptr, &p1);
    TreeNode p13(13, nullptr, nullptr);
    TreeNode p8(8, &p13, &p4);

    TreeNode p5(5, &p4_1, &p8);

    cout << hasPathSum(&p5, 22);

    return 0;
}