INCLUDE Irvine32.inc

.data
meter DWORD 00780056h

.code
main PROC

movzx EAX, WORD PTR meter
call WriteHex

mov AL, ' '
call WriteChar

movzx EAX, WORD PTR meter[2]
call WriteHex



exit
main ENDP
END main