This was a classic master/slave project for Operating Systems. The requirements were that it worked for adding 1 number, 2 numbers, 5 numbers, 6 numbers, and 8 numbers together. These all work correctly.

You run it by feeding master arguments, example:

./master 1 2

or

./master 1 2 3 4 5 6 7 8

I wrote master.c, slave.c was supplied for the project. 

The code is very messy, riddled with comments and print commands that are leftover from testing and debugging. If I had to take on this project again, I would rewrite it completely.

Fair warning: the program will do some crazy things if it is fed a different number of arguments than were required for the project(ie. master 1 2 3). 
