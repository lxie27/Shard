## Add any additional notes here

Builds on Windows with MingW by running build.py. The game will then build into the Platformer folder in the GameBuild folder. The dll files in the folder are required for it to run. Asset folder must be in the GameBuild folder. It is by default.

Music from: https://www.bensound.com/royalty-free-music/electronica

Tile Editor:
To run the Tile Editor navigate to the TileEditor folder inside Tools and run 'python3 TileEditor.py'

Sprite Editor:
Require Pillow module. Can be installed by running 'pip3 install pillow'.
MingW had issues installing pillow but any base install of Python 3 I used worked fine.
To run the Sprite Editor navigate to the SpriteEditor folder insdie Tools and run 'python 3 SpriteEditor.py'


## Project Hieararchy

In the future, other engineers may take on our project, so we have to keep it organized given the following requirements below. Forming some good organization habits now will help us later on when our project grows as well. These are the required files you should have 

### ./Game Directory Organization

- Docs 
    - Source Code Documentation
- Assets
    - Art assets (With the Sub directories music, sound, images, and anything else)
- src
    - source code(.cpp files) The make file or any build scripts that automate the building of your project should reside here.
- include
    - header files(.h files)
- lib
    - libraries (.so, .dll, .a, .dylib files). Note this is a good place to put SDL
- temp
    - This is the directory where your built executable(.exe for windows, .app for Mac, or a.out for Linux) and any additional generated files are put after each build.
- Tools
	-The Sprite and Tile editor tools.
- GameBuild
    - Your final deliverable. One should be able to copy and paste this directory, and only this directory onto another machine and be able to run the game.
- ThirdParty
    - Code that you have not written if any.

**Note:** that src should only contain ".cpp" or ".h" files. Why? It makes it very fast to do a backup of your src directory as one example. Secondly, binary files that are generated often clutter up directories. I should not see any binaries in your repository, you may use a '.gitignore' file to help prevent this automatically. 
