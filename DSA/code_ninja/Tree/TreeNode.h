#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include<vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*>children;

    TreeNode(T _data) :data(_data){}
};




#endif // TREENODE_H_INCLUDED
