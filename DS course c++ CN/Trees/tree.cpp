#include <vector>
using namespace std;

template<typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode<T>*> treeChildren;
    TreeNode(T data){
    this->data=data;
    }
    TreeNode(){}
    ~TreeNode(){
        for(int i=0;i<treeChildren.size();i++){
            delete treeChildren[i];
        }
    }

};
