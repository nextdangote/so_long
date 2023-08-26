# so_long
A 2D Game in C using the MLX42 Graphics Library  👾🕹️

## Structure :
* [Resources](#resources)
* [How to build it](#how-to-build-it)
* [What I learned](#what-i-learned)

## Resources :  

https://github.com/liz753/so_long/blob/main/Makefile

https://github.com/Laendrun/42-so_long/tree/main/includes  

https://42-cursus.gitbook.io/guide/rank-02/so_long  

https://reactive.so/post/42-a-comprehensive-guide-to-so_long  

https://github.com/madebypixel02/so_long

## How to build it :  

First I create my Project Plan :  

<ins>1. Theme and Graphics</ins>
*   choice of theme 
*   image research 
*   image manipulation using GIMP (transparency and resizing)

<ins>2. Code Structure</ins>
*   create a Makefile that doesn't relink
*   create a header file

<ins>3. Parsing</ins>
*   read the map file with the C-functions ``open`` and ``read`` and store its content in a string
*   store the map in a 2D-array
*   check that the map is valid
*   check that the path is valid (all collectibles and exit reachable) using floodfill
*   implement error messages

<ins>4. Game Coding</ins>
*   keyboard input (``W`` ``A`` ``S`` ``D`` + arrow keys for moving and ``ESC`` for closing the game)
*   image conversion to ``.xpm42`` using ``xpm3_conv.py``-file of the MLX42
*   initialization of assets (in this case only images)
*   rendering 
*   implement the hooks
*   display the movement count in the shell
*   display messages in the shell (a)when player wants to go on exit before collecting all the collectibles, b) when the player collected them all, c) when     the player quit the game before finishing and d)when the player won the game)

## What I learned : 

