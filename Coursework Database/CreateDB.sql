CREATE TABLE Accounts (
    Username varchar(16), Password TEXT,
    CONSTRAINT Accounts_PK PRIMARY KEY (Username)
);

CREATE TABLE Objects (
    ObjectID INTEGER,
    Username TEXT,
    "Object Name" TEXT,
    "Date Accessed" DATE,
    Public INTEGER DEFAULT (1),
    -- This will determine that by default, objects uploaded are public.
    CONSTRAINT Objects_PK PRIMARY KEY (ObjectID),
    CONSTRAINT Objects_FK FOREIGN KEY (Username) REFERENCES Accounts(Username)
);

CREATE TABLE Triangles (
	TriangleID INTEGER,
	ObjectID INTEGER,
	Vertex1ID INTEGER,
	Vertex2ID INTEGER,
	Vertex3ID INTEGER,
	CONSTRAINT Triangles_PK PRIMARY KEY (TriangleID) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT Triangles_FK FOREIGN KEY (Vertex1ID) REFERENCES Vertices(VertexID) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT Triangles_FK FOREIGN KEY (Vertex2ID) REFERENCES Vertices(VertexID) ON UPDATE CASCADE ON DELETE CASCADE,
	CONSTRAINT Triangles_FK FOREIGN KEY (Vertex3ID) REFERENCES Vertices(VertexID) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Vertices (
	VertexID INTEGER,
	x REAL,
	y REAL,
	z REAL,
	
	CONSTRAINT Vertices_PK PRIMARY KEY (VertexID)
);


