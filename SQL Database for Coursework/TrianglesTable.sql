CREATE TABLE [dbo].[Triangles]
(
	[TriangleID] INT NOT NULL PRIMARY KEY,
	[ObjectID] INT NOT NULL,
	[Vertex1ID] INT NOT NULL,
	[Vertex2ID] INT NOT NULL,
	[Vertex3ID] INT NOT NULL

	Foreign key (ObjectID) references Objects (ObjectID),
	Foreign key (Vertex1ID) references Vertices (VertexID),
	Foreign key (Vertex2ID) references Vertices (VertexID),
	Foreign key (Vertex3ID) references Vertices (VertexID)
)
