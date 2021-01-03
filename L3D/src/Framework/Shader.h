#pragma once
#include <string>
extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}
#include "gl/glew.h"

namespace ShaderType
{
    const int VertexShader = 0;
    const int FragmentShader = 1;
    const int GeometryShader = 2;
    const int PixelShader = 3;
};

class Shader
{
public:

    unsigned int Program;

    Shader();

    void Create();
    void Bind() const;
    void UnBind() const;
    void LoadShader(std::string Name, int ShaderType);

    static void RegisterToLua(lua_State* L);

private:
    static int LoadFromText(std::string Text,int Type);
    static int LoadFromFile(std::string Path, int Type);
    GLint Shaders[4];
};
