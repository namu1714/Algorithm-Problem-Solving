#include <iostream>
using namespace std;

typedef struct node {
	node* leftNode;
	node* rightNode;
	int data;
};

void postorder(node* root) {
	if (root->leftNode != NULL)
		postorder(root->leftNode);
	if (root->rightNode != NULL)
		postorder(root->rightNode);
	cout << root->data << "\n";
}

void insert(node* root, int newData) {
	node* curr = root;
	node* newNode = new node;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->data = newData;

	while (true) {
		if (curr->data > newData) {
			if (curr->leftNode != NULL) {
				curr = curr->leftNode;
			}
			else {
				curr->leftNode = newNode;
				break;
			}
		}
		else {
			if (curr->rightNode != NULL) {
				curr = curr->rightNode;
			}
			else {
				curr->rightNode = newNode;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tmp;

	cin >> tmp; //root
	node* root = new node;
	root->leftNode = NULL;
	root->rightNode = NULL;
	root->data = tmp;

	while (cin >> tmp) {
		insert(root, tmp);
	}

	postorder(root);

	return 0;
}