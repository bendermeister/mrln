#include "vec.templ.h"

struct OBJECT {
  size_t size;
  size_t scope;
  TYPE *buf;
};

OBJECT *FUNC(_create)(void) {
  OBJECT *self = ALLOC(sizeof(*self));
  self->size = 0;
  self->scope = 16;
  self->buf = ALLOC(self->scope * sizeof(*self->buf));
  return self;
}

void FUNC(_destroy)(OBJECT *self) {
  if (self) {
    FREE(self->buf);
  }
  FREE(self);
  self = NULL;
}

void FUNC(_init)(OBJECT *self) {
  self->size = 0;
  self->scope = 16;
  self->buf = ALLOC(self->scope * sizeof(*self->buf));
}

void FUNC(_deinit)(OBJECT *self) {
  if (self) {
    FREE(self->buf);
  }
}

void FUNC(_grow)(OBJECT *self) {
  self->scope *= 2;
  self->buf = REALLOC(self->buf, self->scope);
}

TYPE *FUNC(_more)(OBJECT *self) {
  if (self->size == self->scope) {
    FUNC(_grow)(self);
  }
  TYPE *p = &self->buf[self->size];
  self->size += 1;
  return p;
}

TYPE *FUNC(_get)(OBJECT *self, size_t i) {
  return &self->buf[i];
}

size_t FUNC(_size)(OBJECT *self) {
  return self->size;
}

TYPE *FUNC(_begin)(OBJECT *self) {
  return self->buf;
}

TYPE *FUNC(_end)(OBJECT *self) {
  return self->buf + self->size;
}
