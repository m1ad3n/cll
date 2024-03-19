#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

int main(int argc, char *argv[]) {
	cll_t* head = cll_new("Hello Idiot", NULL);
	cll_push_back(head, "SECOND");
	cll_push_back(head, "THIRD");
	cll_push_back(head, "FOURTH");
	cll_push_back(head, "FIFTH");
	cll_push_back(head, "SIXTH");
	
    cll_debug(head, "%s");
	cll_push_front(head, "HAHAHA");
    cll_debug(head, "%s");
    
    // free the memory and exit
	cll_free(head);
	return 0;
}

cll_t* cll_new(void* _value, cll_t* _next) {
	cll_t* tmp = (cll_t*)malloc(sizeof(cll_t));
	tmp->value = _value;
	tmp->next = _next;
	return tmp;
}

int cll_insert(cll_t* head, void* _value, unsigned int index) {
    if (head == NULL || _value == NULL) return FALSE;

    unsigned int count = 0;
    cll_t* tmp = head;
    while (tmp) {
        if (count == index - 1) break;
        tmp = tmp->next;
        count++;
    }

    tmp->next = cll_new(_value, tmp->next);
    return TRUE;
}

int cll_push_back(cll_t* head, void* _value) {
	if (head == NULL || _value == NULL) return FALSE;
	
	// set the TAIL
	cll_t* tail = head;
	while (tail) {
		if (tail->next == NULL) break;
		tail = tail->next;
	}
	
	tail->next = cll_new(_value, NULL);
	return TRUE;
}

int cll_push_front(cll_t* head, void* _value) {
    if (head == NULL || _value == NULL) return FALSE;
    cll_t* temp = cll_new(_value, head);
    head = temp;
    return TRUE;
}

cll_t* cll_at(cll_t* head, unsigned int index) {
	if (head == NULL) return NULL;
	cll_t* tmp = head;
	unsigned int count = 0;
	
	while (tmp) {
		if (count == index) return tmp;
		count++;
		tmp = tmp->next;
	}
	
	return NULL;
}

unsigned int cll_length(cll_t* head) {
    if (head == NULL) return 0;
    unsigned int count = 0;
    cll_t* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

unsigned int cll_size(cll_t* head) {
    if (head == NULL) return 0;
    unsigned int sum = 0;
    cll_t* temp = head;
    while (temp) {
        sum += sizeof(temp);
        temp = temp->next;
    }
    return sum;
}

void cll_debug(cll_t* head, const char* _format) {
	if (head == NULL) return;
	
	cll_t* tmp = head;
    printf("[");
	while (tmp) {
		printf(_format, tmp->value);
        printf(" ");
		tmp = tmp->next;
	}
    printf("]\n");
}

void cll_free(cll_t* head) {
	if (head == NULL) return;
	if (head->next != NULL) cll_free(head->next);
	free(head);
}
