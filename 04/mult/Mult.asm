// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

@R2
M=0 // initialize R2 to zero
@R0
D=M
@END
D;JEQ // check if X=0
@R1
D=M
@END
D;JEQ // check if y=0
@R0
D=M
@R3 // prepare R3 to be used as looping mechanism. x is the loop variable
M=D
(MULT)
@R1
D=M // y
@R2
M=M+D // add y to R2
@R3
M=M-1 // increment counter down
D=M
@MULT
D;JGT
@END
D;JEQ
(END)
@END
0;JMP