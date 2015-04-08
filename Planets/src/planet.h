#ifndef __PLANET_H__
#define __PLANET_H__

#include "config.h"
#include "vector3.h"

typedef struct t_planet {
	Vector3 position;
	Vector3 speed;
	pt_float mass;
} Planet;

#endif // __PLANET_H__