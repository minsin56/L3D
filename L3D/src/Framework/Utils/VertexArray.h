#pragma once
#include <vector>
#include <glm/vec3.hpp>
extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}
class VertexArray
{
public:
    VertexArray(){Items = std::vector<glm::vec3>();}
    std::vector<glm::vec3> Items;

    void Add(glm::vec3 Vec);

    static void Register(lua_State* State);
};
