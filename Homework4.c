#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
    double data;
	struct treeNode* left;
	struct treeNode* right;
}TreeNode;


TreeNode n1 = { 2, NULL, NULL };
TreeNode n2 = { 3, NULL, NULL };
TreeNode n3 = {'+', &n1, &n2 };
TreeNode n4 = { 4, NULL, NULL };
TreeNode n5 = { 5, NULL, NULL };
TreeNode n6 = {'*', &n4, &n5};
TreeNode n7 = {'+', &n3, &n6 };
TreeNode n8 = { 6, NULL, NULL };
TreeNode n9 = { 7, NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { 9, NULL, NULL };
TreeNode n12 = {'+', &n10, &n11 };
TreeNode n13 = {'-', &n7, &n12 };
TreeNode *exp = &n12;

//수식계산함수 
int evaluate(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		double opt1 = evaluate(root->left);
		double opt2 = evaluate(root->right);
		printf("%f, %c, %f\n", opt1, root->data, opt2);
		if (root->data == '+')
			return opt1 + opt2;
		else if (root->data == '-')
			return opt1 - opt2;
		else if (root->data == '*')
			return opt1 * opt2;
		else if (root->data == '/')
			return opt1 / opt2;

		return 0;
	}
}

//노드의 개수 
int get_node_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

int main(void)
{
	printf("수식의 값은 %d입니다.\n", evaluate(exp));
	printf("총 노드의 수는 %d입니다.", get_node_count(exp));

	return 0;
}