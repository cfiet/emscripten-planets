#include "../config.h"

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#include "../app.h"

static GLFWwindow *window;

int main () {
    int width, height;
    float ratio;

    switch(pt_app_initialize()) {
        case PT_INIT_GLFW_FAILURE:
            emscripten_log(EM_LOG_ERROR, "Error while initializing GLFW");
            return EXIT_FAILURE;

        case PT_INIT_SUCCESS:
            emscripten_log(EM_LOG_CONSOLE, "Initailization succeded");
            break;
    }
    
    emscripten_set_main_loop(pt_app_main_loop, 0, false);

    return EXIT_SUCCESS;
}
#endif // EMSCRIPTEN