INCLUDE Irvine32.inc

.data
myName BYTE "Farhan", 0 ;using BYTE because BYTE is 8 bits, and my name is 6 bits
roll BYTE 38 ;BYTE works for double digits
age BYTE 19
CGPA REAL4 3.58 ;REAL4 for floating point

.code
main PROC
CALL DumpRegs ;just for checking

exit
main ENDP
END main
