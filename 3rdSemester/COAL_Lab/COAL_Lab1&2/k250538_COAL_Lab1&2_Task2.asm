INCLUDE Irvine32.inc

.data
myName BYTE "Facharn", 0 ;using BYTE because BYTE is 8 bits, and my name is 6 bits
roll BYTE 38 ;BYTE works for double digits
age
CGPA REAL4 3.58 ;REAL4 for floating point

.code
main PROC

MOV EAX, 13h ;18 = 13h in hexa
MOV EBX, 1001b ;random binary

CALL DumpRegs ;

exit
main ENDP
END main
