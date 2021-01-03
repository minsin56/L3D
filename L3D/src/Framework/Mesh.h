#pragma once
#include <vector>
#include "gl/glew.h"
#include "GLFW/glfw3.h"
#include <glm/vec3.hpp>

extern "C"{
#include "lua/lua.hpp"
}

#include "Utils/VertexArray.h"

class Mesh
{
public:
    VertexArray Vertices;
    std::vector<unsigned int> Indices;

    Mesh();
    
    GLuint  VBO, VAO ,IBO;

    void AddVertex(glm::vec3 Vertex);
    void AddIndex(int Index);

    void Create();

    static void RegisterToLua(lua_State* L);
};
