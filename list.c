#include <assert.h>
#include <stdlib.h>
#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL); assert(new_element != NULL);
	list_t* thisList = head;
	list_t* nextList = head->next;
	uint32_t indexToInsert = new_element->index;
	new_element->next = NULL; //just in case
	if (head->index > new_element->index) { //insert before head
		new_element->next = head;
		head = new_element;
	}
	else {
		while (nextList != NULL) {
			if (indexToInsert < nextList->index ) {//insert here
				new_element->next = nextList;
				thisList->next = new_element;
				break;
			}
			thisList = nextList;
			nextList = thisList->next;
		}
		if (nextList == NULL) {//need to insert at the end
			thisList->next = new_element;
		}
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
    list_t* prev = NULL;
    list_t* current = head;
    list_t* next;
    while (current != NULL) {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;	
	return head;
}

