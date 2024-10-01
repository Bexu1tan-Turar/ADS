#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
private:
    TreeNode* root;

    int subtreeSize(TreeNode* node) {
        if (node == NULL)
            return 0;
        return 1 + subtreeSize(node->left) + subtreeSize(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        if (root == NULL) {
            root = new TreeNode(value);
            return;
        }
        TreeNode* current = root;
        while (true) {
            if (value < current->val) {
                if (current->left == NULL) {
                    current->left = new TreeNode(value);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = new TreeNode(value);
                    return;
                }
                current = current->right;
            }
        }
    }

    int getSubtreeSize(int target) {
        TreeNode* current = root;
        while (current != NULL) {
            if (target == current->val)
                return subtreeSize(current);
            if (target < current->val)
                current = current->left;
            else
                current = current->right;
        }
        return 0;
    }
};

int main() {
    int N, target;
    cin >> N;
    BST tree;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    cin >> target;
    cout << tree.getSubtreeSize(target) << endl;
    return 0;
}