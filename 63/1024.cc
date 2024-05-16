#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
};

node *rotateRight(node *root)
{
	node* t;
	t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

node *rotateLeft(node *root)
{
	node* t;
	t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

node *rotateRightLeft(node *root)
{
	root->right = rotateRight(root->right);	//注意这里是转动子树
	return rotateLeft(root);
}

node *rotateLeftRight(node *root)
{
	root->left = rotateLeft(root->left);	//注意这里是转动子树
	return rotateRight(root);
}

int getHeight(node* root)
{
	if(root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

node *insert(node* root, int val)
{
	if(root == NULL)
	{
		root = new node();
		root->val = val;
		root->left = NULL;
		root->right = NULL;
	}
	else if(root->val < val)
	{
		root->right = insert(root->right, val);
		if(getHeight(root->right) - getHeight(root->left) == 2)
			root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);	//向右偏并且挂在右边,直接左旋
	}
	else
	{
		root->left = insert(root->left, val);
		if(getHeight(root->right) - getHeight(root->left) == -2)
			root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);	//向左挂左直接右旋
	}

	return root;
}

int main(void)
{
	int val,n;
	cin>>n;
	node* root = NULL;
	for(int i =0;i < n;i++)
	{
		scanf("%d",&val);
		root = insert(root,val);
	}

	printf("%d\n",root->val);
	return 0;
}
