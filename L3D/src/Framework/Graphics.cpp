#include "Graphics.h"
#include <glm/glm.hpp>



#include "Mesh.h"
#include "Shader.h"
#include "Utils/VertexArray.h"

void Graphics::ClearColor(lua_State* L)
{
    glClearColor((float)lua_tonumber(L,1),(float)lua_tonumber(L,2),(float)lua_tonumber(L,3),(float)lua_tonumber(L,4));
}

void Graphics::BeginTriangles(lua_State* L)
{
    glBegin(GL_TRIANGLES);
}

void Graphics::EndTriangles(lua_State* L)
{
    glEnd();
}

void Graphics::Vertex2(lua_State* L)
{
    glVertex2d((double)lua_tonumber(L,1),(double)lua_tonumber(L,2));
}

void Graphics::Vertex3(lua_State* L)
{
    glVertex3d((double)lua_tonumber(L,1),(double)lua_tonumber(L,2),(double)lua_tonumber(L,3));
}

void Graphics::DrawVertexArraySlow(VertexArray* Array)
{
   if(Array)
   {
       for(int i = 0;i < Array->Items.size(); i++)
       {
           glm::vec3 Pos = Array->Items[i];

           glVertex3d(Pos.x,Pos.y,Pos.z);
       }
   }
}

void Graphics::DrawMesh(Mesh* Mesh)
{
    glBindVertexArray(Mesh->VAO);
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES,Mesh->Indices.size(),GL_UNSIGNED_INT,0);
    glBindVertexArray(0);

}


void Graphics::RegisterToLua(lua_State* L)
{
    luabridge::getGlobalNamespace(L).beginClass<Graphics>("Graphics").
    addStaticFunction("ClearColor",&ClearColor).
    addStaticFunction("BeginTriangles",&BeginTriangles).
    addStaticFunction("Vertex2",&Vertex2).
    addStaticFunction("Vertex3",&Vertex3).
    addStaticFunction("DrawVertexArraySlow",&DrawVertexArraySlow).
    addStaticFunction("DrawMesh",&DrawMesh).
    addStaticFunction("EndTriangles",&EndTriangles).
    endClass();

    // Vector Types
    luabridge::getGlobalNamespace(L).beginNamespace("glm")
     .beginClass<glm::vec4>("vec4")
     .addConstructor<void(*)(float, float, float,float)>().
        addProperty("x", &VecHelper<glm::vec4,0>::Get,&VecHelper<glm::vec4,1>::Set).
        addProperty("y", &VecHelper<glm::vec4,1>::Get,&VecHelper<glm::vec4,1>::Set).
        addProperty("z", &VecHelper<glm::vec4,2>::Get,&VecHelper<glm::vec4,2>::Set).
        addProperty("w", &VecHelper<glm::vec4,3>::Get,&VecHelper<glm::vec4,3>::Set).
    endClass().
    endNamespace();


    luabridge::getGlobalNamespace(L).beginNamespace("glm")
     .beginClass<glm::vec3>("vec3")
     .addConstructor<void(*)(float, float, float)>().
        addProperty("x", &VecHelper<glm::vec3,0>::Get,&VecHelper<glm::vec3,1>::Set).
        addProperty("y", &VecHelper<glm::vec3,1>::Get,&VecHelper<glm::vec3,1>::Set).
        addProperty("z", &VecHelper<glm::vec3,2>::Get,&VecHelper<glm::vec3,2>::Set).
    endClass().
    endNamespace();

    luabridge::getGlobalNamespace(L).beginNamespace("glm")
     .beginClass<glm::vec2>("vec2")
     .addConstructor<void(*)(float, float)>().
        addProperty("x", &VecHelper<glm::vec2,0>::Get,&VecHelper<glm::vec2,0>::Set).
        addProperty("y", &VecHelper<glm::vec2,1>::Get,&VecHelper<glm::vec2,1>::Set).
    endClass().
    endNamespace();

    Mesh::RegisterToLua(L);
    Shader::RegisterToLua(L);
}
