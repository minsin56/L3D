#include "Shader.h"


#include <fstream>
#include <iostream>
#include <LuaBridge/LuaBridge.h>

Shader::Shader()
{
    LoadShader("Main",0);
    LoadShader("Main",1);
}



void Shader::LoadShader(std::string Name, int ShaderType)
{
    std::string ShaderTypeExtension;
    int GLShaderType;
    
    switch(ShaderType)
    {
        case 0:
            ShaderTypeExtension = "_Vert.glsl";
            GLShaderType = GL_VERTEX_SHADER;
            break;
        case 1:
            ShaderTypeExtension = "_Frag.glsl";
            GLShaderType = GL_FRAGMENT_SHADER;
            break;
        case 2:
            ShaderTypeExtension = "_Geo.glsl";
            GLShaderType = GL_GEOMETRY_SHADER;
            break;
        case 3:
            ShaderTypeExtension = "_Pix.glsl";
            GLShaderType = GL_FRAGMENT_SHADER;
            break;

        default:
            std::cout<<"SHADER TYPE DOES NOT EXIST"<<std::endl;
            return;
    }
    
    std::string Path = "Game/Assets/Shaders/" + std::string(Name) + ShaderTypeExtension;
    Shaders[ShaderType] = LoadFromFile(Path,GLShaderType);

}


void Shader::Create()
{
    Program = glCreateProgram();
    glAttachShader(Program,Shaders[0]);
    glAttachShader(Program,Shaders[1]);

    
    if(Shaders[ShaderType::GeometryShader] != 0)
    {
        glAttachShader(Program,Shaders[ShaderType::GeometryShader]);
    }

    if(Shaders[ShaderType::PixelShader] != 0)
    {
        glAttachShader(Program,Shaders[ShaderType::PixelShader]);
    }
    
    GLint Status;
    glLinkProgram(Program);
    glGetProgramiv(Program,GL_LINK_STATUS, &Status);
    if(Status == GL_FALSE)
    {
        GLint InfoLogSize;
        glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &InfoLogSize);
        GLchar* InfoLog = new GLchar[InfoLogSize];
        glGetProgramInfoLog(Program, InfoLogSize, nullptr, InfoLog);
        delete [] InfoLog;
    }



    glDeleteShader(Shaders[ShaderType::VertexShader]);
    glDeleteShader(Shaders[ShaderType::FragmentShader]);

}

void Shader::Bind() const
{
    glUseProgram(Program);
}

void Shader::UnBind() const
{
    glUseProgram(0);
}

void Shader::RegisterToLua(lua_State* L)
{
    luabridge::getGlobalNamespace(L).beginClass<Shader>("Shader").addConstructor<void(*)()>()
    .addFunction("LoadShader",&LoadShader).addFunction("Bind",&Bind).addFunction("UnBind",&UnBind).
    addFunction("Create",&Create).endClass();
    
}

int Shader::LoadFromText(std::string Text,int Type)
{
    int ShaderID = glCreateShader(Type);
    const char* ShaderCode = Text.c_str();
    glShaderSource(ShaderID,1,&ShaderCode,nullptr);

    GLint Status;

    glCompileShader(ShaderID);
    glGetShaderiv(ShaderID,GL_COMPILE_STATUS,&Status);


    
    if(Status == GL_FALSE)
    {
        GLint InfoLogSize;
        glGetShaderiv(ShaderID,GL_INFO_LOG_LENGTH,&InfoLogSize);

        GLchar* InfoLog = new GLchar[InfoLogSize];

        glGetShaderInfoLog(ShaderID,InfoLogSize,nullptr,InfoLog);
        std::cout<<"Shader Error:"<<InfoLog<<std::endl;

        delete [] InfoLog;
    }
    return ShaderID;
    
}

int Shader::LoadFromFile(std::string Path, int Type)
{
    int Ret = -1;
    std::ifstream Reader;
    Reader.open(Path,std::ios_base::in);
    if(Reader)
    {
        std::string Buffer(std::istreambuf_iterator<char>(Reader),(std::istreambuf_iterator<char>()));
        Ret = LoadFromText(Buffer,Type);
    }

    return Ret;
}

