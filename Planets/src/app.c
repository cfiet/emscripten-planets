#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#include "planet.h"
#include "simulation.h"
#include "app.h"


#define PLANETS_LENGTH 2

static Planet pl_app_planets[PLANETS_LENGTH];

GLFWwindow *window;

void pt_initailize_planets () {
    pl_app_planets[0].mass = 0.5;
    pl_app_planets[0].position.x = -10;
    pl_app_planets[0].position.y = 0;
    pl_app_planets[0].position.z = 0;
    pl_app_planets[0].speed.x = 0;
    pl_app_planets[0].speed.y = -10;
    pl_app_planets[0].speed.z = 0;

    pl_app_planets[1].mass = 0.5;
    pl_app_planets[1].position.x = 10;
    pl_app_planets[1].position.y = 0;
    pl_app_planets[1].position.z = 0;
    pl_app_planets[1].speed.x = 0;
    pl_app_planets[1].speed.y = 10;
    pl_app_planets[1].speed.z = 0;
}

pt_init_result_t pt_app_initialize () {
    if (!glfwInit()) {
        return PT_INIT_GLFW_FAILURE;
    }

    window = glfwCreateWindow(PT_WINDOW_WIDTH, PT_WINDOW_HEIGHT, PT_WINDOW_TITLE, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return PT_INIT_GLFW_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    pt_initailize_planets();
    
    return PT_INIT_SUCCESS;
}

void pt_app_main_loop () {
    int width, height;
    float ratio;

    sim_run_simulation_step((Planet*) &pl_app_planets, PLANETS_LENGTH, 0.1);

    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
}