#version 330 core
layout (location = 0) in vec3 aPos;   // позиция атрибута, содержащего переменные координат, устанавливается в 0
layout (location = 1) in vec3 aColor; // позиция атрибута, содержащего переменные цвета, устанавливается в 1
  
out vec3 ourColor; // на выходе – значение цвета, передаваемое во фрагментный шейдер
out vec3 pos;

uniform float smy;
uniform float smx;

void main()
{
    pos = aPos;
    gl_Position = vec4(aPos.x + smx, aPos.y + smy, aPos.z , 1.0);
    ourColor = aColor; // присваиваем переменной ourColor значение цвета, которое мы получили из данных вершины
}
