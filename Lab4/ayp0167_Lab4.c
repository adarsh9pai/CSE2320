/*
Name: Adarsh Yogesh Pai
Lab: #4
CSE 2320
UTA ID: 1001530167
Omega Command: gcc ayp0167_Lab4.c -o program
*/
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

int CheckBlackProperty(struct Node* Root){
	if(Root == NULL){
		return 0;
	}
	int LeftChildHeight = CheckBlackProperty(Root->LeftChild);
	int RightChildHeight = CheckBlackProperty(Root->RightChild);
	int HeightAdd = (Root->Color == 'B') ? 1 : 0;

	if(LeftChildHeight == -1 || RightChildHeight == -1 || LeftChildHeight != RightChildHeight){
		printf("\nBlack height problem");
		printf("\nDoes not satisfy\n");
		exit(0);
		return -1;
	}
	else{
		return LeftChildHeight + HeightAdd;
	}
}

int main(){

	struct Node* TreeRoot;
	TreeRoot = BuildTree();
	PreOrderTraversal(TreeRoot);
	if(TreeRoot != NULL && TreeRoot->Color != 'B'){
		printf("\nRoot of tree is not black");
		printf("\nDoes not satisfy\n");
		exit(0);
	}
	CheckRedProperty(TreeRoot);
	CheckBlackProperty(TreeRoot);

	//If Red Property and Black Property is not valid, the program quits. If they are valid, program won't quit -> proceed to print out success message
	printf("\nSatisfies all properties\n");	
}
