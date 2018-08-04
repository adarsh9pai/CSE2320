#include <stdio.h>
#include <stdlib.h>

int BlackHeight = 0;

struct Node{
	char Color;
	struct Node* LeftChild;
	struct Node* RightChild;
};

struct Node* BuildTree(){
	char Color;
	scanf("%c",&Color);
	struct Node* Child;
	if(Color == '.'){
		return NULL;
	}
	Child = (struct Node*)malloc(sizeof(struct Node));
	Child->Color = Color;
	Child->LeftChild = BuildTree();
	Child->RightChild = BuildTree();

	return Child;
}

void PreOrderTraversal(struct Node* Root){
	if(Root != NULL){
		printf("%c",Root->Color);
		PreOrderTraversal(Root->LeftChild);
		PreOrderTraversal(Root->RightChild);
	}
	else if(Root == NULL){
		printf(".");
	}
}

void CheckRedProperty(struct Node* Root){

	if(Root != NULL){
		if(Root->Color == 'R'){
			struct Node *Left = Root->LeftChild;
			struct Node *Right = Root->RightChild;
			if(Left != NULL){
				if(Left->Color == 'R'){
						printf("\nRed property problem");
						printf("\nDoes not satisfy\n");
						exit(0);
				}
			}
			if(Right != NULL){
				if(Right->Color == 'R'){
						printf("\nRed property problem");
						printf("\nDoes not satisfy\n");
						exit(0);
				}
			}
		}
		CheckRedProperty(Root->LeftChild);
		CheckRedProperty(Root->RightChild);
	}
}

int main(){
	int CheckTreeProperty = 0;
	struct Node* TreeRoot;
	TreeRoot = BuildTree();
	PreOrderTraversal(TreeRoot);
	if(TreeRoot->Color != 'B'){
		printf("\nRoot of tree is not black");
		printf("\nDoes not satisfy\n");
		exit(0);
	}
	CheckRedProperty(TreeRoot);
	
	
}
