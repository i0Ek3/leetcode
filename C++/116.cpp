// 116 Populating Next Right Pointers in Each Node
//
// 给定一个完全二叉树，填充一个指针，使得所有节点的该指针都指向其同水平位置的右边的节点，如过没有右边的节点，则指向 NULL，初始时都指向 NULL。
//
// 只能进行简单的分析，看了别人的答案后才想到是层序遍历。
//

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        if (root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
