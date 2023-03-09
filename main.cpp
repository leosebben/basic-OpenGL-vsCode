#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int error(char *message);

int main() 
{
    // initialize GLFW
    if (!glfwInit()) {
        printf("GLFW initialization failed");
        glfwTerminate();
        return 1;
    }

    // setup glfw window property
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // opengl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // core profile = no compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // allow forward compatibility

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Hello, World!", NULL, NULL);
    if (!mainWindow) {
        printf("GLFW window creation failed");
        glfwTerminate();
        return 1;
    }

    // buffer size informatino
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    // allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("GLEW initialization failed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // loop until window close
    while(!glfwWindowShouldClose(mainWindow)) {
        // get and handle user input events
        glfwPollEvents();

        // clear the window
        glClearColor(1.0f, 1.0f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}

int error(char *message) {
    printf("%s", message);
    glfwTerminate();
    return 1;
}
