#ifndef __APP_H_
#define __APP_H_

#include "planet.h"

#define PT_WINDOW_WIDTH 800
#define PT_WINDOW_HEIGHT 600
#define PT_WINDOW_TITLE "Planets"

typedef enum {
	PT_INIT_SUCCESS,
	PT_INIT_GLFW_FAILURE
} pt_init_result_t;

pt_init_result_t pt_app_initialize ();
void pt_app_main_loop (void);

#endif // __APP_H_