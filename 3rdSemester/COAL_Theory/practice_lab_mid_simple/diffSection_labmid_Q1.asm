INCLUDE Irvine32.inc

.data
fixed SBYTE -5, 3, -2, 7
user SBYTE 4 DUP(?)
msg BYTE " ", 0
R DWORD ?

.code
main PROC

;taking user input here
mov ecx, 4
mov ESI, 0
l1:
call ReadInt
mov user[ESI], AL
inc ESI
loop l1 ;user input part ends

;adding the offset and reading them part
mov ecx, 4
mov esi, 0
l2:
mov AL, fixed[ESI]
add user[ESI], AL
movsx EAX, user[ESI]
call WriteInt

mov EDX, OFFSET msg
call WriteString
inc ESI
loop l2

movsx EAX, user[1] ;r1
movsx EBX, user[2] ;r2
sub EAX, EBX ;r1-r2

movsx EBX, user[3] ;r3
add EAX, EBX

movsx EBX, user[0] ;r0
sub EAX, EBX

mov R, EAX
call Crlf
call WriteDec
call Crlf
call WriteHex
call Crlf

movzx EAX, WORD PTR R
call WriteHex
call Crlf
movsx EAX, BYTE PTR R
call WriteInt

exit
main ENDP
END main