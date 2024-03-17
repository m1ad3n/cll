#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

static void cll_debug(cll_t* tail, const char* _format);

int main(int argc, char *argv[]) {
	cll_t* TAIL = cll_new("Hello Idiot", NULL);
	cll_push_new(TAIL, "SECOND");
	cll_push_new(TAIL, "THIRD");
	cll_push_new(TAIL, "FOURTH");
	cll_push_new(TAIL, "FIFTH");
	cll_push_new(TAIL, "SIXTH");
	
	cll_debug(TAIL, "%s\n");
	
	printf("WANTED: %s\n", cll_at(TAIL, 4)->value);
	
	// free the memory and exit
	cll_free(TAIL);
	return 0;
}

cll_t* cll_new(void* _value, cll_t* _next) {
	cll_t* _tmp = (cll_t*)malloc(sizeof(cll_t));
	_tmp->value = _value;
	_tmp->next = _next;
	return _tmp;
}


int cll_push(cll_t* tail, cll_t* ell) {
	if (tail == NULL || ell == NULL) return FALSE;
	
	// set the tmp to HEAD
	cll_t* head = tail;
	while (head) {
		if (head->next == NULL) break;
		head = head->next;
	}
	
	head->next = ell;
	return TRUE;
}

int cll_push_new(cll_t* tail, void* _value) {
	if (tail == NULL || _value == NULL) return FALSE;
	cll_t* tmp = cll_new(_value, NULL);
	if (cll_push(tail, tmp)) return FALSE;
	return TRUE;
}

cll_t* cll_at(cll_t* tail, unsigned int index) {
	if (tail == NULL) return NULL;
	cll_t* tmp = tail;
	unsigned int count = 0;
	
	while (tmp) {
		if (count == index) return tmp;
		count++;
		tmp = tmp->next;
	}
	
	return NULL;
}

static void cll_debug(cll_t* tail, const char* _format) {
	if (tail == NULL) return;
	
	cll_t* tmp = tail;
	unsigned int count = 0;
	
	while (tmp) {
		printf("%p = ", tmp);
		printf(_format, tmp->value);
		tmp = tmp->next;
		count++;
	}
	printf("\nELEMENTS = %d\n", count);
	printf("SIZE     = %d\n\n\n", count * sizeof(cll_t));
}

void cll_free(cll_t* tail) {
	if (tail == NULL) return;
	if (tail->next != NULL) cll_free(tail->next);
	free(tail);
}