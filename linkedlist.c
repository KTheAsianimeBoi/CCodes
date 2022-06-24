#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
	// Step 1
	int data;
	struct tNode* next;
} Node;

typedef struct tLinkedList {
	// Step 1
	Node* head;
	int count;

} LinkedList;


void appendItem(LinkedList* list, int value)
{
	// Step 2
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	if (list->head == NULL) {
		list->head = newNode;
		list->count++;
		return;
	}

	Node* tracker = list->head;
	while (tracker->next != NULL) {
		tracker = tracker->next;
	}
	tracker->next = newNode;
	list->count++;

}

int countItems(LinkedList* list)
{
	if (list->head == NULL) {
		list->count = 0;
	}
	return list->count;
	// Step 3
}

int insertItem(LinkedList* list, int index, int value)
{
	// Step 4
	if (index < 0 || index > list->count) {
		return -1;
	}
	Node* tracker = list->head;
	for (int i = 1; i <= index - 1; i++) {
		tracker = tracker->next;
	}
	Node* rightBehind = tracker->next;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = rightBehind;
	tracker->next = newNode;
	return 1;
}

void removeItem(LinkedList* list, int index)
{
	if (index < 0 || index > list->count) {
		return -1;
	}

	if (index == 0) {
		Node* temp = list->head;
		list->head = list->head->next;
		free(temp);
		return 1;
	}

	Node* tracker = list->head;
	Node* deleted;
	for (size_t i = 1; i <= index-1; i++)
	{
		tracker = tracker->next;
	}

	deleted = tracker->next;
	tracker->next = tracker->next->next;
	free(deleted);
	list->count--;	
	// Step 5
}

void dumpItems(LinkedList* list)
{
	// Step 6
	Node* tracker = list->head;
	while (tracker->next != NULL) {
		printf("%d ", tracker->data);
		tracker = tracker->next;
		if (tracker->next == NULL) {
			printf("%d\n", tracker->data);
		}
	}

}

int getItem(LinkedList* list, int index)
{
	// Step 7
	if (index < 0 || index >= list->count) {
		return -1;
	}

	Node* tracker = list->head;
	for (int i = 1; i <= index; i++) {
		tracker = tracker->next;
	}

	return tracker->data;
}

void clearItems(LinkedList* list)
{
	// Step 8
	Node* tracker = list->head;
	Node* next;
	while (tracker != NULL) {
		next = tracker->next;
		free(tracker);
		tracker = next;
	}
	list->head = NULL;
}

void enqueue(LinkedList* list, int value)
{
	appendItem(list, value);
}

int dequeue(LinkedList* list)
{
	Node* tracker = list->head;
	int result = tracker->data;
	removeItem(list, 0);
	return result;
}	




int main(int argc, char** argv)
{
	// Do not change main function
	LinkedList list;
	list.head = NULL;
	list.count = 0;
	enqueue(&list, 1);
	enqueue(&list, 3);
	enqueue(&list, 2);
	enqueue(&list, 5);

	printf("%d\n", dequeue(&list));
	printf("%d\n", dequeue(&list));
	printf("%d\n", dequeue(&list));
	printf("%d\n", dequeue(&list));

	return 0;
}

//int main(int argc, char** argv)
//{
//	// Do not change main function.
//
//	LinkedList list;
//	list.head = NULL;
//	list.count = 0;
//	appendItem(&list, 1);
//	appendItem(&list, 5);
//	appendItem(&list, 4);
//	appendItem(&list, 7);
//
//	int count = countItems(&list);
//	printf("%d\n", count);
//	dumpItems(&list);
//
//	printf("%d\n", insertItem(&list, 2, 3));
//	printf("%d\n", insertItem(&list, 100, 3));
//	dumpItems(&list);
//
//	printf("%d\n", removeItem(&list, 4));
//	printf("%d\n", removeItem(&list, 100));
//	dumpItems(&list);
//
//	printf("%d\n", getItem(&list, 2));
//	printf("%d\n", getItem(&list, 100));
//
//	clearItems(&list);
//	printf("%d\n", countItems(&list));
//
//	return 0;
//}


