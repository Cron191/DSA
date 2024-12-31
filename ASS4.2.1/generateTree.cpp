#include <vector>
using namespace std;

// Định nghĩa cấu trúc cây
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {}; // Nếu n = 0, không có cây nào
        return buildTrees(1, n);
    }

private:
    vector<TreeNode *> buildTrees(int start, int end)
    {
        vector<TreeNode *> trees;

        // Nếu không có giá trị nào trong khoảng, trả về cây trống
        if (start > end)
        {
            trees.push_back(nullptr);
            return trees;
        }

        // Thử tất cả các giá trị làm gốc
        for (int i = start; i <= end; ++i)
        {
            // Xây dựng tất cả các cây con bên trái từ [start, i-1]
            vector<TreeNode *> leftTrees = buildTrees(start, i - 1);

            // Xây dựng tất cả các cây con bên phải từ [i+1, end]
            vector<TreeNode *> rightTrees = buildTrees(i + 1, end);

            // Kết hợp tất cả các cây con bên trái và phải với gốc là i
            for (TreeNode *left : leftTrees)
            {
                for (TreeNode *right : rightTrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};

class Solution
{
public:
    long long maxVal(TreeNode *root)
    {
        if (root == NULL)
            return LLONG_MIN;
        return max((long long)root->val, max(maxVal(root->left), maxVal(root->right)));
    }
    long long minVal(TreeNode *root)
    {
        if (root == NULL)
            return LLONG_MAX;
        return min((long long)root->val, min(minVal(root->left), minVal(root->right)));
    }
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (maxVal(root->left) < (long long)root->val && minVal(root->right) > (long long)root->val)
            return isValidBST(root->left) && isValidBST(root->right);
        else
            return false;
    }
};
class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *last;
    TreeNode *middle;

private:
    void Inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        Inorder(root->left);
        if (prev != NULL && (prev->val > root->val))
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }

            else
            {
                last = root;
            }
        }
        prev = root;
        Inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = prev = last = NULL;
        prev = new TreeNode(INT_MIN);
        Inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        delete1(root, key);
        return root;
    }
    void delete1(TreeNode *&root, int key)
    {
        if (root == NULL)
            return;
        if (key < root->val)
            delete1(root->left, key);
        else if (key > root->val)
            delete1(root->right, key);
        else
        {
            if (root->left == NULL && root->right == NULL)
                root = NULL;
            else if (root->left != NULL && root->right == NULL)
            {
                root->val = root->left->val;
                delete root->left;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                root->val = root->right->val;
                delete root->right;
            }
            else
            {
                TreeNode *mint = MIN_TREE(root);
                swap(root->val, mint->val);
                delete mint;
            }
        }
    }

private:
    TreeNode *MIN_TREE(TreeNode *root)
    {
        if (root == NULL)
            return nullptr;
        if (root->left == NULL)
            return root;
        return MIN_TREE(root->left);
    }
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root)
            if (key < root->val)
                root->left = deleteNode(root->left, key); // We frecursively call the function until we find the target node
            else if (key > root->val)
                root->right = deleteNode(root->right, key);
            else
            {
                if (!root->left && !root->right)
                    return NULL; // No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right; // One child contion -> replace the node with it's child
                                                                  // Two child condition
                TreeNode *temp = root->left;                      //(or) TreeNode *temp = root->right;
                while (temp->right != NULL)
                    temp = temp->right;                         //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                          //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val); //        root->right = deleteNode(root->right, temp);
            }
        return root;
    }
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            else if (root->left != NULL && root->right == NULL)
                return root->left;
            else if (root->left == NULL && root->right != NULL)
                return root->right;
            else
            {
                TreeNode *temp = root->left;
                while (temp->right != NULL)
                    temp = temp->right;
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
    }
};