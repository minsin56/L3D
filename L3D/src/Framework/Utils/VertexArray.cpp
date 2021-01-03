#include "VertexArray.h"

#include "LuaBridge/LuaBridge.h"

void VertexArray::Add(glm::vec3 Vec)
{
    Items.push_back(Vec);
}

void VertexArray::Register(lua_State* State)
{
    luabridge::getGlobalNamespace(State).beginClass<VertexArray>("VertexArray").addConstructor<void(*)()>().addFunction("Add",&Add).endClass();
}
