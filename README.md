This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as

a parameter to your program. Here is an example:

$>cat 42.fdf

0000000000000000000

0000000000000000000

0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0

0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0

0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0

0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0

0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0

0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0

0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0

0000000000000000000

0000000000000000000

$>

Each number corresponds to a point in space:

• The horizontal position corresponds to its axis.

• The vertical position corresponds to its ordinate.

• The value corresponds to its altitude
