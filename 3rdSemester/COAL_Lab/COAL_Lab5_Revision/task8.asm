INCLUDE Irvine32.inc

.data
trucks DWORD 80, 45, 90, 60
msg BYTE " ", 0
.code
main PROC
mov ESI, TYPE trucks
add DWORD PTR trucks[ESI], 20

mov ECX, LENGTHOF trucks
mov ESI, 0

L1:
mov EAX, trucks[ESI]
call WriteDec
mov EDX, OFFSET msg
call WriteString
add ESI, TYPE trucks
loop L1

exit
main ENDP
END main