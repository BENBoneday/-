//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//typedef struct BINARYNODE
//{
//	char ch;
//	struct BINARYNODE* lChild;
//	struct BINARYNODE* rChild;
//}BinaryNode;
//
////叶子结点数目
//int* CalculateLeafNum(BinaryNode* root,int* leafNum)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	if (root->lChild == NULL && root->rChild == NULL)
//	{
//		(*leafNum)++;
//	}
//	CalculateLeafNum(root->lChild, leafNum);
//	CalculateLeafNum(root->rChild, leafNum);
//	return leafNum;
//}
////树的高度
//int CalculateTreeDepth(BinaryNode* root)
//{
//	
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int depth = 0;
//	int leftDepth = CalculateTreeDepth(root->lChild);
//	int rightDepth = CalculateTreeDepth(root->rChild);
//
//	return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
//}
////拷贝二叉树
//BinaryNode* CopyBinaryTree(BinaryNode* root)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//	BinaryNode* lChild=CopyBinaryTree(root->lChild);
//	BinaryNode* rChild=CopyBinaryTree(root->rChild);
//	BinaryNode* newNode = (BinaryNode*)malloc(sizeof(BinaryNode));
//	newNode->ch = root->ch;
//	newNode->lChild = lChild;
//	newNode->rChild = rChild;
//	return newNode;
//}
////释放树
//void FreeSpaceBinaryTree(BinaryNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	FreeSpaceBinaryTree(root->lChild);
//	FreeSpaceBinaryTree(root->rChild);
//	free(root);
//}
////先序
//void Recursion(BinaryNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	printf("%c ", root->ch);
//	Recursion(root->lChild);
//	Recursion(root->rChild);
//}
////中序
//void Recursion1(BinaryNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	Recursion1(root->lChild);
//	printf("%c ", root->ch);
//	
//	Recursion1(root->rChild);
//}
////后序
//void Recursion2(BinaryNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	
//	Recursion2(root->lChild);
//	Recursion2(root->rChild);
//	printf("%c ", root->ch);
//
//}
//void CreateBinaryTree()
//{
//	BinaryNode node1 = { 'A',NULL,NULL };
//	BinaryNode node2 = { 'B',NULL,NULL };
//	BinaryNode node3 = { 'C',NULL,NULL };
//	BinaryNode node4 = { 'D',NULL,NULL };
//	BinaryNode node5 = { 'E',NULL,NULL };
//	BinaryNode node6 = { 'F',NULL,NULL };
//	BinaryNode node7 = { 'G',NULL,NULL };
//	BinaryNode node8 = { 'H',NULL,NULL };
//
//	node1.lChild = &node2;
//	node1.rChild = &node6;
//	node2.rChild = &node3;
//	node3.lChild = &node4;
//	node3.rChild = &node5;
//	node6.rChild = &node7;
//	node7.lChild = &node8;
//
//	int leafNum = 0;
//	//CalculateLeafNum(&node1, &leafNum);
//
//	
//	//int D=CalculateTreeDepth(&node1);
//	//printf("%d\n", D);
//	BinaryNode* root=CopyBinaryTree(&node1);
//	Recursion(root);
//	free(root);
//}
//int main()
//{
//	CreateBinaryTree();
//	return 0;
//}