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
This way of work brings forward the idea of ```markup languages``` ( example : *XML*).

Input file example :

```
Image
```
The Rules :
- The Comments ```#```* shall be ingnored as well as unknown commands ```##```*.
```
Image
```
- The first non-ignored line will be the number of ants.
```
Image
```
- Secondly the different rooms (with there own positions for a visualizer) are introduced. There will be a ```##start``` room and an ```##end``` room.
```
Image
```
- Thirdly there will be the links between the roomsm there needs to be at least one valid.
```
Image
```

## Additional information

The **Lexing / Parsing** of the file will handle every potentiel errors and exit properly without any leaks.
Then send the parsed information to the algorithm and print out the result.

example of output :

```
Image
```
