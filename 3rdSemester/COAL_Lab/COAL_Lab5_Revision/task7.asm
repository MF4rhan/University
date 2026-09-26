INCLUDE Irvine32.inc

.data
fahrenheit DWORD 32, 68, 104
msg BYTE " ", 0
.code
main PROC
mov ECX, LENGTHOF fahrenheit
mov ESI, 0

L1:
mov EAX, fahrenheit[ESI]
sub EAX, 32

mov EBX, 5
mul EBX

mov EDX, 0
mov EBX, 9
div EBX

call WriteDec
mov EDX, OFFSET msg
call WriteString

add ESI, TYPE fahrenheit
Loop L1

call Crlf

exit
main ENDP
END main