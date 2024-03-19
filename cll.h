#ifndef CLL_H
#define CLL_H

#define TRUE  1
#define FALSE 0

//
// C++ SUPPORT
//
#ifdef __cplusplus
extern "C" {
#endif

typedef struct cll cll_t;
struct cll {
	void* value;
	struct cll* next;
};

cll_t* cll_new(void* _value, cll_t* _next);
cll_t* cll_at(cll_t* head, unsigned int index);

int cll_push_back(cll_t* head, void* _value);
int cll_push_front(cll_t* head, void* _value);
int cll_insert(cll_t* head, void* _value, unsigned int index);

unsigned int cll_length(cll_t* head);
unsigned int cll_size(cll_t* head);

void cll_debug(cll_t* head, const char* _format);
void cll_free(cll_t* head);

//
// END FOR C++ SUPPORT
//
#ifdef __cplusplus
}
#endif

#endif
