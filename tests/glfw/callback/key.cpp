#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void keyCallback (GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){//CUANDO SE PRESIONA LA TECLA
        std::cout << "Escape press" << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_W && action == GLFW_RELEASE) {//CUANDO SE SUELTA LA TECLA
        std::cout << "w press" << std::endl;
    }
    if (key == GLFW_KEY_B && action == GLFW_REPEAT) {//SE MANTIENE PRESIONADA LA TECLA
        std::cout << "B PRESS" << std::endl;
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
        glfwSetKeyCallback(window, keyCallback);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}