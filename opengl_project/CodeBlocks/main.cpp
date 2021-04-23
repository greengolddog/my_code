#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>

float a1 = 0.000, a2 = 0.000, i = -1, i2 = -1.5;
class Shader
{
public:
    unsigned int ID;

    // Конструктор генерирует шейдер на лету
    Shader(const char* vertexPath, const char* fragmentPath)
    {
        // Этап №1: Получение исходного кода вершинного/фрагментного шейдера из переменной filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        // Убеждаемся, что объекты ifstream могут выбросить исключение
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // Открываем файлы
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;

            // Считываем содержимое файловых буферов в потоки
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            // Закрываем файлы
            vShaderFile.close();
            fShaderFile.close();

            // Конвертируем данные из потока в строковые переменные
            vertexCode   = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();

        // Этап №2: Компилируем шейдеры
        unsigned int vertex, fragment;

        // Вершинный шейдер
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");

        // Фрагментный шейдер
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");

        // Шейдерная программа
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        // После того, как мы связали шейдеры с нашей программой, удаляем их, так как они нам больше не нужны
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    // Активация шейдера
    void use()
    {
        glUseProgram(ID);
    }

    // Полезные uniform-функции
    void setBool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    void setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

private:
    // Полезные функции для проверки ошибок компиляции/связывания шейдеров
    void checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};
#endif

// glfw: всякий раз, когда изменяются размеры окна (пользователем или оперионной системой), вызывается данная callback-функция
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Убеждаемся, что окно просмотра соответствует новым размерам окна.
	// Обратите внимание, что ширина и высота будут значительно больше, чем указано на Retina-дисплеях
    glViewport(0, 0, width, height);
}

// Обработка всех событий ввода: запрос GLFW о нажатии/отпускании клавиш на клавиатуре в текущем кадре и соответствующая обработка данных событий
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        a1 -= 0.001;
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        a1 += 0.001;
    }
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        a2 += 0.001;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        a2 -= 0.001;
    }
    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        a1 = 0.000;
    }
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        a2 = 0.000;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        i -= 0.001;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        i += 0.001;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        i2 += 0.001;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        i2 -= 0.001;
}
// Константы
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: инициализация и конфигурирование
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // раскомментируйте эту строку, если используете macOS
#endif

    // glfw: создание окна
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL for Ravesli.com", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: загрузка всех указателей на OpenGL-функции
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    Shader sh("s.vs", "s.fs");

    // Указывание вершин (и буферов) и настройка вершинных атрибутов
    float vertices[] = {
        // координаты         // цвета
     0.0f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // нижняя правая вершина
    -1.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // нижняя левая вершина
    -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // верхняя вершина
    };

    unsigned int VBO[1], VAO[1];
    glGenVertexArrays(1, VAO);
    glGenBuffers(1, VBO);

    // Сначала связываем объект вершинного массива, затем связываем и устанавливаем вершинный буфер(ы), и затем конфигурируем вершинный атрибут(ы)
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // Координатный атрибут
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Цветовой атрибут
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);


    // Раскомментируйте следующую строку для отрисовки полигонов в режиме каркаса
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Цикл рендеринга
    while (!glfwWindowShouldClose(window))
    {
        i += a1;
        if (i >= 2) {
            i -= 3;
            // a1 += 0.001;
        }
        if (i < -1) {
            i += 3;
            // a1 += 0.001;
        }
        i2 += a2;
        if (i2 >= 1.5) {
            i2 -= 3;
            // a2 += 0.001;
        }
        if (i2 < -1.5) {
            i2 += 3;
            // a2 += 0.001;
        }
        // Обработка ввода
        processInput(window);

        // Рендеринг
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Рисуем наш первый треугольник
        float timeValue = glfwGetTime();
        float col = (sin(timeValue) / 2.0f) + 0.5f;
        //float col = 1;
        //int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        sh.use();
        sh.setFloat("smx", i);
        sh.setFloat("smy", i2);
        sh.setFloat("col", col);
        //glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(VAO[0]); // поскольку у нас есть только один VАО, то нет необходимости связывать его каждый раз (но мы сделаем это, чтобы всё было немного организованнее)
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // glBindVertexArray(0); // не нужно каждый раз его отвязывать

        // glfw: обмен содержимым front- и back- буферов. Отслеживание событий ввода\вывода (была ли нажата/отпущена кнопка, перемещен курсор мыши и т.п.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Опционально: освобождаем все ресурсы, как только они выполнили свое предназначение
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);

    // glfw: завершение, освобождение всех ранее задействованных GLFW-ресурсов
    glfwTerminate();
    return 0;
}
