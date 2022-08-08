#include <iostream>

class Node
{
public:
	int data;
	Node* right;
	Node* left;



	Node(int X)
	{
		data = X;
		Node* right = NULL;
		Node* left = NULL;

	}

};



int findCeil(Node* root, int input) {
	if (root == NULL)
	{

		return -1; //if it doesnt exist
	}
	Node* current = root;
	int answer=0;
	while (current != NULL)
	{
		if (current->data == input)
		{
			answer= current->data;
			return answer;
		}

		if (current->data > input)  //why are we only assigning the answer in the left one?
			//because the greater values lie on the left one, while the smallest on the right
			//ciel is the greater value so we have to check in the left sub tree
		{
			answer = current->data;
			current = current->left;
		}
		else if (current->data < input)
		{
			current = current->right;
		}

	}

	return answer;
}

int main(void)
{

	Node* root = new Node(5);
	root->right = new Node(7);
	root->left = new Node(1);
	root->left->right = new Node(2);
	root->left->right->right = new Node(3);

	int X = 3;

	int Ceil = findCeil(root, X);


	return 0;
}