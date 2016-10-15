#include "list.h"

List * InitializeList(Cell * data) {
	// Create the List struct.
	List * new_list;

	// Request the memory from the heap.
	new_list = (List *)malloc(sizeof(List));

	// Check if the request was successful
	if (new_list == 0) {
		printf("Error creating the list node, out of memory\n");
		return NULL;
	}

	// Initialize the values
	new_list->prev_ = NULL;
	new_list->next_ = NULL;
	new_list->data_ = data;

	return new_list;
}

void ListDestructor(List * list) {
	// Check if you are at the end of the list.
	if (list == NULL) {
		return;
	}
	// Frees the memory for the cell.
	CellDestructor(list->data_);
	ListDestructor(list->next_);

	// Free the memory for this node.
	free(list);
}

Cell * front(List * list) {
	// TODO: Implement
	return NULL;
}

Cell * back(List * list) {
	// TODO: Implement
	return NULL;
}

void PushBack(Cell * data, List * list) {
	if (list == NULL) {
		list = InitializeList(data);
		return;
	}
	if (list->next_ == NULL) {
		list->next_ = InitializeList(data);
		return;
	}
	List * head = list->next_;
	while (head->next_ != NULL) {
		head = head->next_;
	}
	head->next_ = InitializeList(data);
}

void Append(Cell * data, List * list) {
	// TODO: Implement
}

Cell * get(int index, List * list) {
	// TODO: Implement
	return NULL;
}

bool in(Cell * data, List * list) {
	// TODO: Implement
	return false;
}

int length(List * list) {
	if (list == NULL) {
		return 0;
	}
	int count = 1;
	List * head = list;
	while (head->next_ != NULL) {
		count++;
		head = head->next_;
	}
	return count;
}

bool empty(List * list) {
	// TODO: Implement
	return false;
}

void clear(List * list) {
	// TODO: Implement
}

void erase(Cell * data, List * list) {
	// TODO: Implement
}

List * reverse(List * list) {
	// TODO: Implement
	return NULL;
}
