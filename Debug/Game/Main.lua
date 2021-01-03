Tri = Mesh()

Tri:AddVertex(glm.vec3(-1,-1,0))
Tri:AddVertex(glm.vec3(0.5,1,0))
Tri:AddVertex(glm.vec3(1,-1,0))

Tri:AddIndex(0)
Tri:AddIndex(1)
Tri:AddIndex(2)

Tri:Create()

MainShader = Shader()

MainShader:Create()

function BeginDraw()
    Graphics.ClearColor(0.5,1,0.5,1)
end

function Draw()
    MainShader:Bind()
    Graphics.DrawMesh(Tri)
    MainShader:UnBind()
end