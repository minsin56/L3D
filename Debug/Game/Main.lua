function BeginDraw()
    Graphics:ClearColor(0.5,1,0.5,1)
end

Vertices = VertexArray();

Vertices:Add(glm.vec3(-0.5,-0.5,0))
Vertices:Add(glm.vec3(0,0.5,0))
Vertices:Add(glm.vec3(0.5,-0.5,0))

function Draw()
    Graphics.BeginTriangles();
    Graphics.DrawVertexArraySlow(Vertices)
    Graphics.EndTriangles();
end