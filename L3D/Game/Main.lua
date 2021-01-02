function BeginDraw()
    Graphics:ClearColor(0.5,1,0.5,1)
end

function Draw()
    Graphics.BeginTriangles();
    Graphics.Vertex2(-0.5,-0.5);
    Graphics.Vertex2(0,0.5);
    Graphics.Vertex2(0.5,-0.5);
    Graphics.EndTriangles();
end