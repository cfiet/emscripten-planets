#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "config.h"

typedef struct t_vector3 {
	pt_float x;
	pt_float y;
	pt_float z;
} Vector3;

pt_float v3_len (Vector3*);

void v3_to_unit (Vector3*);

void v3_neg (Vector3*);
void v3_add (Vector3*, Vector3*);
void v3_sub (Vector3*, Vector3*);
void v3_mul (Vector3*, pt_float);
void v3_div (Vector3*, pt_float);

Vector3* v3_create (pt_float, pt_float, pt_float);
void v3_dispose(Vector3*);
Vector3* v3_copy (Vector3*);

#endif // __VECTOR3_H__