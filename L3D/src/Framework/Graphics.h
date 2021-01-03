﻿#pragma once
#include <glm/vec2.hpp>

#include "Utils/VertexArray.h"

extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}

#include "LuaBridge/LuaBridge.h"



template<typename T, unsigned Index>
struct VecHelper
{
    static float Get (T const* Vec)
    {
        return (*Vec)[Index];
    }

    static void Set (T* Vec, float Value)
    {
        (*Vec)[Index] = Value;
    }
};

class Graphics
{
public:
    static int Width,Height;
    
    static void ClearColor(lua_State* L);
    static void BeginTriangles(lua_State* L);
    static void EndTriangles(lua_State* L);
    static void Vertex2(lua_State* L);
    static void Vertex3(lua_State* L);
    static void DrawVertexArraySlow(VertexArray* Array);

    static int GetWidth();
    static int GetHeight();

    static void RegisterToLua(lua_State* L);
};