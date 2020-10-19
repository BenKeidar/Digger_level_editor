README

Digger level editor

Ben Keidar - 208308817
Date - 29.12.19

General description:
This program is a level editor for the digger game.
At first, the user inputs number of rows and columns to define his grid size, and also 
number of stones that the digger allowed to eat.
Then the user can choose between a digger , a monster , a wall, a stone,
and a diamond icon to place on the grid and create his own map of the digger game. 
In addition the user can save his map, clear it or erase one or more of
the icons he places on the grid.

//----------------------------------------------------------------------------------------

Design:
Controller : runs the editor via SFML graphic window.
Board: contains all the various functions on the icons, toolbar and grid.
Toolbar: In charge of the toolbar under the grid and the title above the grid.
Icon : holds an icons shape and color and draws it.
Digger ,Monster ,Wall ,Diamond ,Stone : all have a virtual draw function.

//----------------------------------------------------------------------------------------

files created by the user:
board.txt - saves the users map on a .txt file.

//----------------------------------------------------------------------------------------

Main data structures:
A texture and sprite array to save all the .PNGs of the icons.
A vector of vector of unique pointer to an Icon - holds all the Icons on the grid which placed by the user.

//----------------------------------------------------------------------------------------

Known bugs:
the window size of the editor is costumed according to the users input,
because every cell in the grid is set to a certain pixel size , if the user
will input a large number of row and columns (approximately more than 30)
the window size will be bigger than the screen size.

}