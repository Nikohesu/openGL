#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void mousePositionCallback (GLFWwindow* window, double xpos, double ypos){
    std::cout << "cursor en: " << xpos << ", " << ypos << std::endl;
}
void mouseButtonCallback (GLFWwindow* window, int button, int action, int mods){
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        std::cout << "boton izquierdo del mouse presionado" << std::endl;

    }
}

int main () {
    if (!glfwInit()) { 
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1; 
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//version mayor del administrador de ventanas
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//version menor del administrador de ventanas
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//definimos el perfil de openGL como moderno

    GLFWwindow* window = glfwCreateWindow(600, 600, "proyect 1",NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;glfwTerminate();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
}

    //rederloop
    while (!glfwWindowShouldClose(window)) {

        glfwSetCursorPosCallback(window, mousePositionCallback);
        glfwSetMouseButtonCallback(window, mouseButtonCallback);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}