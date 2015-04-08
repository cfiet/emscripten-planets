#include "../config.h"

#ifdef _WIN32
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#include "../app.h"

extern GLFWwindow *window;

int main () {
	switch(pt_app_initialize()) {
        case PT_INIT_GLFW_FAILURE:
            exit(EXIT_FAILURE);

        case PT_INIT_SUCCESS:
            break;
    }

    while (!glfwWindowShouldClose(window)) {
		pt_app_main_loop();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

#endif // _WIN32