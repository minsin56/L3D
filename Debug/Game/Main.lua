function BeginDraw()
    Graphics.ClearColor( 0.196078, 0.6, 0.8)
end

Pos1 = glm.vec2(0.5,-0.5)
Pos2 = glm.vec2(0,0.5)
Pos3 = glm.vec2(0.5,0.5)

Vertices = {
    Pos1,
    Pos2,
    Pos3
}

function Draw()
    Graphics.BeginTriangles();
    Graphics.Vertex2Array(Vertices)
    Graphics.EndTriangles();
end