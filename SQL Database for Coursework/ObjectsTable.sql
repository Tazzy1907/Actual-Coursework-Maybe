CREATE TABLE [dbo].[Objects]
(
	[ObjectID] INT NOT NULL PRIMARY KEY, 
    [Username] VARCHAR(16) NOT NULL,
	[Object Name] VARCHAR(MAX) NOT NULL,
	[Date Accessed] DATE NOT NULL,
	[Public] BIT NOT NULL

	Foreign key (Username) references Accounts (Username)
	
)
