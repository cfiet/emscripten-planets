#include "config.h"

#include <math.h>
#include <stdlib.h>

#include "vector3.h"

pt_float v3_len (Vector3 *v) {
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void v3_to_unit (Vector3 *v) {
	pt_float length = v3_len(v);

	v->x = v->x / length;
	v->y = v->y / length;
	v->z = v->z / length;
}

void v3_neg (Vector3 *v) {
	v3_mul(v, -1);
}

void v3_add (Vector3 *left, Vector3 *right) {
	left->x += right->x;
	left->y += right->y;
	left->z += right->z;
}

void v3_sub (Vector3 *left, Vector3 *right) {
	left->x -= right->x;
	left->y -= right->y;
	left->z -= right->z;
}

void v3_mul (Vector3 *vec, pt_float value) {
	vec->x *= value;
	vec->y *= value;
	vec->z *= value;
}

void v3_div (Vector3 *vec, pt_float value) {
	// TODO: what if value == 0 ?
	v3_mul(vec, 1/value);
}

Vector3* v3_create (pt_float x, pt_float y, pt_float z) {
	Vector3* ret = (Vector3*)malloc(sizeof(Vector3));

	ret->x = x;
	ret->y = y;
	ret->z = z;

	return ret;
}

void v3_dispose(Vector3 *v) {
	free(v);
}

Vector3* v3_copy (Vector3 *v) {
	return v3_create(v->x, v->y, v->z);
}