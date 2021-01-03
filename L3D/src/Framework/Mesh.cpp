#include "Mesh.h"
#include "LuaBridge/LuaBridge.h"
#include <glm/glm.hpp>


Mesh::Mesh()
{
    Vertices = std::vector<glm::vec3>();
    Indices = std::vector<unsigned int>();
}

void Mesh::AddVertex(glm::vec3 Vertex)
{
    Vertices.push_back(Vertex);
}

void Mesh::AddIndex(int Index)
{
    Indices.push_back(Index);
}

void Mesh::Create()
{
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,Vertices.size() * sizeof(glm::vec3),Vertices.data(),GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 3 * sizeof(float),(void*)0);

    glGenBuffers(1,&IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Indices),Indices.data(),GL_STATIC_DRAW);
    
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);

}

void Mesh::RegisterToLua(lua_State* L)
{
    luabridge::getGlobalNamespace(L).beginClass<Mesh>("Mesh").addConstructor<void(*)()>().
    addFunction("AddVertex",&AddVertex).addFunction("AddIndex",&AddIndex).addFunction("Create",&Create).endClass();
}
