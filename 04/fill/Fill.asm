// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(LOOP)
@SCREEN
D=A
@R32
M=D
@R33
M=0
@8192
D=A
@R34
M=D
@KBD
D=M

@BLACK_SCREEN
D;JGT

@WHITE_SCREEN
D;JEQ

@LOOP
0;JMP

(BLACK_SCREEN)
@R32
D=M
@R33
D=D+M
A=D
M=-1
@R33
M=M+1
@R34
M=M-1
D=M
@BLACK_SCREEN
D;JGT

@LOOP
0;JMP

(WHITE_SCREEN)
@R32
D=M
@R33
D=D+M
A=D
M=0
@R33
M=M+1
@R34
M=M-1
D=M
@WHITE_SCREEN
D;JGT

@LOOP
0;JMP