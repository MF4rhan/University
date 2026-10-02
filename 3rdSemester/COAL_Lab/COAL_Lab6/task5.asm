INCLUDE Irvine32.inc

.data
msg1 BYTE " X ", 0
msg2 BYTE " = ", 0
multiplier DWORD 1
outer DWORD ?

.code
main PROC

mov ECX, 3
L1:
mov outer, ECX
mov ESI, 1
mov ECX, 5
L2:
mov EAX, multiplier ;printing the first number
call WriteDec
mov EDX, OFFSET msg1 ;printing X
call WriteString
mov EAX, ESI ;printing the second number
call WriteDec
mov EDX, OFFSET msg2 ;printing =
call WriteString
mov EAX, multiplier
imul EAX, ESI ;multiplying the 1st and 2nd number
call WriteDec
inc ESI
call Crlf
loop L2
call Crlf
call Crlf
inc multiplier
mov ECX, outer
loop L1

exit
main ENDP
END main