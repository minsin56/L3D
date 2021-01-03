#include "Mesh.h"
#include "LuaBridge/LuaBridge.h"
#include <glm/glm.hpp>


Mesh::Mesh()
{
    Vertices = VertexArray();
    Indices = std::vector<unsigned int>();
}


void Mesh::AddVertex(glm::vec3 Vertex)
{
    Vertices.Add(Vertex);
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
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices.Items),Vertices.Items.data(),GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

void Mesh::RegisterToLua(lua_State* L)
{
    luabridge::getGlobalNamespace(L).beginClass<Mesh>("Mesh").addConstructor<void(*)()>().
    addFunction("AddVertex",&AddVertex).addFunction("AddIndex",&AddIndex).addFunction("Create",&Create).endClass();
}
