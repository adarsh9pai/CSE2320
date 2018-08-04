#include <stdio.h>
#include <stdlib.h>

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

int main(){
	struct Node* TreeRoot;
	TreeRoot = BuildTree();
	PreOrderTraversal(TreeRoot);

}
