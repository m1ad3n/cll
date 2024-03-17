#ifndef CLL_H
#define CLL_H


#define TRUE  0
#define FALSE 1


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
cll_t* cll_at(cll_t* tail, unsigned int index);

int cll_push(cll_t* tail, cll_t* ell);
int cll_push_new(cll_t* tail, void* _value);

void cll_free(cll_t* tail);


//
// END FOR C++ SUPPORT
//
#ifdef __cplusplus
}
#endif

#endif