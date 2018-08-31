# Lem-in

## Grade		114	/100

### Mandatory	100	/100
### Bonus		14	/25

## Description

This project is to introduce ```Pathfinding``` algorithms such as *Dijkstra* or *A star*.
The program can be separated into two major parts :
- The first **Lexing / Parsing** of the file sent.
- The second the implementation of the ```Pathfinding``` algorithm and printing a specific output.

It is presented as an ant colony where we will have to make a certain amount of ants cross from the ```##start``` room to the ```##end``` room. Only one ant per room and it must be the path(s) that will take the least time.

## Input file

The input file has specific rules that have to be followed or it will be considered an error.
This brings forward the idea of ```markup languages``` ( example : *XML*).

Input file example :

```
#This is a comment
# Number of ants :
11
# List of rooms :
room1 1 1
##start
room2 2 2
room3 3 3
randomroom 4 4
##end
lastroom 5 5
# Links between rooms :
room1-room2
room3-randomroom
lastroom-randomroom
lastroom-room3
room3-room2
#Ending comment
```
The Rules :
- The Comments ```#```* shall be ingnored as well as unknown commands ```##```*.
```
#This is a comment
```
- The first non-ignored line will be the number of ants.
```
# Number of ants :
11
```
- Secondly the different rooms (with there own positions for a visualizer) are introduced. There will be a ```##start``` room and an ```##end``` room.
```
# List of rooms :
room1 1 1
##start
room2 2 2
room3 3 3
randomroom 4 4
##end
lastroom 5 5
```
- Thirdly there will be the links between the roomsm there needs to be at least one valid.
```
# Links between rooms :
room1-room2
room3-randomroom
lastroom-randomroom
lastroom-room3
room3-room2
```

## Additional information

The **Lexing / Parsing** of the file will handle every potentiel errors and exit properly without any leaks.
Then send the parsed information to the algorithm and print out the result.

example of output :

- The parsed input followed by a line break.
- Each ant's move. Ants are named L1... L1-room3 shows that ant 1 moved to room3.

```console
prompt> ./lem-in < rooms.txt
#This is a comment
# Number of ants :
11
# List of rooms :
room1 1 1
##start
room2 2 2
room3 3 3
randomroom 4 4
##end
lastroom 5 5
# Links between rooms :
room1-room2
room3-randomroom
lastroom-randomroom
lastroom-room3
room3-room2
#Ending comment

L1-room3
L1-lastroom L2-room3
L2-lastroom L3-room3
L3-lastroom L4-room3
L4-lastroom L5-room3
L5-lastroom L6-room3
L6-lastroom L7-room3
L7-lastroom L8-room3
L8-lastroom L9-room3
L9-lastroom L10-room3
L10-lastroom L11-room3
L11-lastroom
```
