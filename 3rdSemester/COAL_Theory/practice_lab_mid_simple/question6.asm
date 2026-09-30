INCLUDE Irvine32.inc

.data
code WORD 10
status BYTE 12
battery DWORD 89

.code
main PROC
mov ESI, OFFSET status
sub ESI, OFFSET code
mov EAX, ESI
call WriteDec

call Crlf

mov ESI, OFFSET battery
sub ESI, OFFSET status
mov EAX, ESI
call WriteDec

exit
main ENDP
END main