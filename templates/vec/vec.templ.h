// gen-ignore on
#define TYPE int
#define OBJECT vec_int_t
#define PREFIX vec_int

#include <stdlib.h>
#define ALLOC malloc
#define REALLOC realloc
#define FREE free
// gen-ignore off

#include <stddef.h>

#ifndef TYPE
#error "TYPE has to be defined"
#endif

#ifndef OBJECT
#error "OBJECT has to be defined"
#endif

#ifndef PREFIX
#error "PREFIX has to be defined"
#endif

#define GLUE_(A, B) A##B
#define GLUE(A, B) GLUE_(A, B)

#define FUNC(A) GLUE(PREFIX, A)

typedef struct OBJECT OBJECT;

OBJECT *FUNC(_create)(void);
void FUNC(_destroy)(OBJECT *self);

void FUNC(_init)(OBJECT *self);
void FUNC(_deinit)(OBJECT *self);

void FUNC(_grow)(OBJECT *self);

TYPE *FUNC(_more)(OBJECT *self);

TYPE *FUNC(_get)(OBJECT *self, size_t i);
size_t FUNC(_size)(OBJECT *self);

TYPE *FUNC(_begin)(OBJECT *self);
TYPE *FUNC(_end)(OBJECT *self);
