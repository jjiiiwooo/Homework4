#include <stdio.h>

//노드 구조체 
typedef struct TreeNode
{
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 2,NULL, NULL };
TreeNode n5 = { 3,NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode n8 = { 6, NULL,NULL};
TreeNode n9 = { 7,NULL, NULL};
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { '-', &n7, &n10 };
TreeNode n12 = { 9, NULL, NULL};
TreeNode n13 = { '+', &n11, &n12 };
TreeNode* exp = &n13;

//트리 노드 계산
double evaluate(TreeNode* root)
{
	double op1 = 0;
	double op2 = 0;
	double result = 0;

	if (root == NULL) return 0;
	//단말 노드라면
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		op1 = evaluate(root->left);
		op2 = evaluate(root->right);

		if (root->data == '+') result = op1 + op2;
		else if (root->data == '-')  result =op1 - op2;
		else if (root->data == '*')  result =op1 * op2;
		else if (root->data == '/') result =op1 / op2;

		printf("%f %c %f= %f\n", op1, root->data, op2, result);
		}

	return result;
}

//노드 개수 
int get_node_count(TreeNode* Node)
{
	int count = 0;
	if (Node != NULL)
		count = 1 + get_node_count(Node->left) +
		get_node_count(Node->right);
	return count;
}

int main(void)
{
	printf("수식의 값은 %f입니다.\n", evaluate(exp));
	printf("총 노드의 개수는 %d입니다.", get_node_count(exp));
	return 0;
}
