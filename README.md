# TwinKnight-game
A class and a client program to walk a twin knights’ tour.

In the game of chess, a knight is a piece moving like the letter L on a chessboard.
That is, it moves either two squares horizontally and one square vertically (2H1V) or 1H2V. A twin
knights’ tour is to put two knights on a chessboard, each making moves, such that they never visit a
square more than once. Note that the two knights can eventually end up in squares where both can
have no more possible moves but other squares remain unvisited.

There are two source files TwinKnightsTour.cpp and tour.cpp. The
former is the implementation of the class TwinKnightsTour, while the latter is a client program of
class TwinKnightsTour which performs the program flow.

In the program, knights are represented by symbols @ and #. During the game, player has to input in the format [knight symbol (@ or #)] [integer] [integer].
However, the input integers must be a position that a knight is allowed to move, just like a knight on chessboard.

At the beginning of the game, player has to input the position of the knights in the format of [row1] [col1] [row2] [col2], where row1 and col1 are for knight @ and row1 and col1 are for knight #. 

Each array element stores either a dot “.”, one letter “A”–“Z”/“a”–“z”, or two letters “AA”–“AZ”, “BA”–“BZ”, …,
“ZZ” (or “aa”–“az”, “ba”–“bz”, …, “zz”). A dot “.” means that the square was not visited by any
knight before. Uppercase strings “A”–“ZZ” denote the move sequence of the one knight @:
A->B->C->…->Z->AA->AB->…->AZ->BA->…, where “A” is the starting position of @. (The
sequence is like the column ordering in spreadsheet applications.) Lowercase strings “a”–“zz”
denote similarly for the other knight #.
