#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
};

TreeNode<int>* takeInput(){
    int data;
    cin>>data;
    TreeNode<int>* root=new TreeNode<int>(data);
    int numChild;
    cout<<"Enter no of child of "<<data<<": ";
    cin>>numChild;
    for(int i=0;i<numChild;i++){
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter root data: ";
    cin>>data;
    TreeNode<int>* root=new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter no of children of "<<front->data<<": ";
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int ChildData;
            cout<<"Enter " <<i<<"th Child data: ";
            cin>>ChildData;
            TreeNode<int>* child=new TreeNode<int>(ChildData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(TreeNode<int> * root){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* front=q.front();
        q.pop();
        cout<<front->data<<": ";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<", ";
        }
        cout<<endl;
        for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
        }
    }
}

int sumOfNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        int smallSum=sumOfNodes(root->children[i]);
        sum+=smallSum;
    }
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){
    if(root==NULL){
        return root;
    }
    TreeNode<int>* max=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* subtree_max=maxDataNode(root->children[i]);
        if(max->data<subtree_max->data){
            max=subtree_max;
        }
    }
    return max;
}

int treeHeight(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int max=0;
    for(int i=0;i<root->children.size();i++){
        int subtree_height=treeHeight(root->children[i]);
        if(subtree_height>max){
            max=subtree_height;
        }
    }
    return 1+max;
}

int leafNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans += leafNodes(root->children[i]);
    }
    return ans;
}
//    1 2 2 3 3 4 5 6 0 0 0 0
int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printTree(root);
    cout<<sumOfNodes(root)<<endl;
    cout<<maxDataNode(root)->data<<endl;
    cout<<treeHeight(root)<<endl;
    cout<<leafNodes(root)<<endl;
}



