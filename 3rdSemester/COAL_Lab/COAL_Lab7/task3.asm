INCLUDE Irvine32.inc


.data
racers DWORD 3 DUP(?)

.code
main PROC

mov ESI, 0
mov ECX, 3
l1:
mov EAX, 0
call ReadInt
mov racers[ESI], EAX
push EAX
add ESI, TYPE racers
loop l1

pop racers[4]
pop racers[0]
pop racers[8]

call Crlf
call Crlf
mov ECX, 3
mov ESI, 0
l2:
mov EAX, racers[ESI]
call WriteDec
call Crlf
add ESI, TYPE racers
loop l2

exit
main ENDP
END main