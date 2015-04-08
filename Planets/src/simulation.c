#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "planet.h"
#include "vector3.h"


#define G_CONST 1.0

void sim_calculate_planet_acc (Vector3 *force, Planet planets[], unsigned int length, unsigned int index) {
	unsigned int i;
	Planet current, p;
	Vector3 *fvec, *diff;
	pt_float dist, fval;

	current = planets[index];

	force->x = 0;
	force->y = 0;
	force->z = 0;

	for(i = 0; i < length; i++) {
		if (i == index) continue;

		p = planets[i];

		diff = v3_copy(&p.position);
		v3_sub(diff, &current.position);
			
		fvec = v3_copy(diff);
		v3_to_unit(fvec);

		dist = v3_len(diff);
		fval = G_CONST * current.mass * p.mass / (dist*dist);

		v3_mul(fvec, fval);
		v3_add(force, fvec);

		v3_dispose(fvec);
		v3_dispose(diff);
	}

	v3_div(force, current.mass);
}

void sim_simulate_planet(Planet *planet, Vector3 *force, pt_float step) {
	planet->position.x += planet->speed.x * step;
	planet->position.y += planet->speed.y * step;
	planet->position.z += planet->speed.z * step;

	planet->speed.x += force->x * step;
	planet->speed.y += force->y * step;
	planet->speed.z += force->z * step;
}

void sim_run_simulation_step (Planet planets[], unsigned int length, pt_float step) {
	Vector3 *accels = (Vector3*) malloc(sizeof(Vector3) * length);

	unsigned int i;
	for(i = 0; i < length; i++) {
		sim_calculate_planet_acc(accels+i, planets, length, i);
	}

	for(i = 0; i < length; i++) {
		sim_simulate_planet(&planets[i], accels+i, step);
	}
}