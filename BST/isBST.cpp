#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		
		BinaryTreeNode(T data){
			this->data = data;
			left= NULL;
			right = NULL;
		}
		
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter Data\n";
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>* > pendingNodes ;
	pendingNodes.push(root);
	while(pendingNodes.size()){
		BinaryTreeNode<int>*  front  = pendingNodes.front();
		pendingNodes.pop();
		int leftData;
		cout<<"Enter the left child of "<<front->data<<":"<<endl;
		cin>>leftData;
		if(leftData != -1){
			BinaryTreeNode<int>*  leftNode = new BinaryTreeNode<int>(leftData);
			front->left = leftNode;
			pendingNodes.push(leftNode);
		}
		int rightData;
		cout<<"Enter the right child of "<<front->data<<":"<<endl;
		cin>>rightData;
		if(rightData != -1){
			BinaryTreeNode<int>*  rightNode = new BinaryTreeNode<int>(rightData);
			front->right = rightNode;
			pendingNodes.push(rightNode);
		}
	}
	return root;
}

bool isBST(BinaryTreeNode<int>* root){
	if(root==NULL){
		return true;
	}
    bool y,z;
    if(root->left ==NULL){
        y= true;
    }else if(root->left->data <= root->data){
		y = isBST(root->left);
	}else{
		y= false;
	}
    if(root->right==NULL){
        z = true;
    }else if(root->right->data >= root->data){
		z = isBST(root->right);
	}else{
		z = false;
	}
    return (y && z);
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();	
	if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
		
	cout<<endl;
	delete root;
	return 0;
}
