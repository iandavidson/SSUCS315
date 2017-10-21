Ian Davidson
cs315 SSU
Spring 2017
Project4

	Phase2:

	Makefile: the executable is made with the command "make"; the Executable is created
	under the name de.x. to run the executable provide a .json file as argv[1]
	(ei: ./de.x project3_sample_input.json).
	
	The functions that actually do the building of the internal representation
	are: buildDirEnt(), parseSingular(), parseChildren().
	This is in the file : buildDirectoryEntry.cpp.
	

	Additioinal setters are called as the internal representation is being created.
	These functions include: setting root, cwd, and parent pointers of nodes.

	General information about functions in DirectoryEntry:
		~All functions are implemented as instructed.
		~All helper functions of DirectoryEntry aren't specific to one function.
		~The Function named destroy & destroyLocal delete the nodes from the rootDir
		     to the DirectoryNodes which are files.


	In main.cpp Lex object is created from .json input, also DirectoryEntry instance is
	created in main.
		
