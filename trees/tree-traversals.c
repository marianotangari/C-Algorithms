#include <stdio.h>
#include <stdlib.h>

/*We are going to traverse the following binary tree: 

				|A|
				/ \ 
			   /   \
			 |B|   |C| 
			 / \
			/   \
		  |D|   |E|
		  /	\	  \
		 /	 \	   \
	   |G|   |H|   |F|
*/

// Binary tree node representation using structs. 
struct node {
	char data;
	struct node *left;
	struct node *right;
}; 

void preorder_traversal(struct node *tree);
void inorder_traversal(struct node *tree);
void postorder_traversal(struct node *tree);


int main() {

	//Creating root node (a) and siblings.
	struct node *a, *b, *c, *d, *e, *f, *g, *h; 

	a = (struct node *) malloc(sizeof(struct node));
	b = (struct node *) malloc(sizeof(struct node));
	c = (struct node *) malloc(sizeof(struct node));
	d = (struct node *) malloc(sizeof(struct node));
	e = (struct node *) malloc(sizeof(struct node));
	f = (struct node *) malloc(sizeof(struct node));
	g = (struct node *) malloc(sizeof(struct node));
	h = (struct node *) malloc(sizeof(struct node));

	//Assigning data to nodes.
	a->data = 'A';
	b->data = 'B';
	c->data = 'C';
	d->data = 'D';
	e->data = 'E';
	f->data = 'F';
	g->data = 'G'; 
	h->data = 'H';

	//Connecting nodes. 
	a->left = b; 
	a->right = c;
	b->left = d; 
	b->right = e;
	d->left = g; 
	d->right = h; 
	e->left = f;

	printf("%s", "Preorder Traversal: ");
	preorder_traversal(a);

	printf("\n%s", "Inorder Traversal: "); 
	inorder_traversal(a);

	printf("\n%s\n", "Postorder Traversal: "); 
	postorder_traversal(a); 
}

void preorder_traversal(struct node *tree) {

	putchar(tree->data); 

	if (tree->left) {
		preorder_traversal(tree->left);
	}

	if(tree->right) {
		preorder_traversal(tree->right);
	}
}

void inorder_traversal(struct node *tree) {

	if (tree->left) {
		inorder_traversal(tree->left);
	}

	putchar(tree->data);

	if(tree->right) {
		inorder_traversal(tree->right);
	}
}

void postorder_traversal(struct node *tree) {

	if (tree->left) {
		postorder_traversal(tree->left);
	}

	if(tree->right) {
		postorder_traversal(tree->right);
	}

	putchar(tree->data);
}