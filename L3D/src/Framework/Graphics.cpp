#include "Graphics.h"
#include <glm/glm.hpp>
#include <LuaBridge/LuaBridge.h>
#include <LuaBridge/detail/LuaRef.h>


#include "glfw/glfw3.h"

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

void Graphics::Vertex2Array(lua_State* L)
{
    
}

void Graphics::RegisterToLua(lua_State* L)
{
    luabridge::getGlobalNamespace(L).beginClass<Graphics>("Graphics").
    addStaticFunction("ClearColor",ClearColor).
    addStaticFunction("BeginTriangles",BeginTriangles).
    addStaticFunction("Vertex2",Vertex2).
    addStaticFunction("Vertex3",Vertex3).
    addStaticFunction("Vertex2Array",Vertex2Array).
    addStaticFunction("EndTriangles",EndTriangles).
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

}
