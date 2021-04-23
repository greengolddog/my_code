#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec3 pos;
uniform float col;  
void main()
{
    FragColor = vec4(ourColor.x*col, ourColor.y*col, ourColor.z*col, 1.0);
}
