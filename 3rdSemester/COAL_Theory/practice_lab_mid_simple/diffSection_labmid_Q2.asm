INCLUDE Irvine32.inc

.data
wordStr BYTE "FARHAN", 0
codes DWORD (LENGTHOF wordStr - 1) DUP(?)
columns DWORD ?
spacer BYTE " ", 0
sum DWORD ?

.code
main PROC
mov EAX, 0
mov EAX, TYPE wordStr ;type, length and size of wordStr
call WriteDec
call Crlf
mov EAX, LENGTHOF wordStr
call WriteDec
call Crlf
mov EAX, SIZEOF wordStr
call WriteDec
call Crlf

call Crlf

mov EAX, TYPE codes ;type, length and size of codes
call WriteDec
call Crlf
mov EAX, LENGTHOF codes
call WriteDec
call Crlf
mov EAX, SIZEOF codes
call WriteDec
call Crlf
call Crlf

mov columns, 1
mov ECX, LENGTHOF wordStr - 1 ;ecx = 6
outer:
mov EBX, ECX ;save ecx
mov ECX, columns ;move columns to ecx for columns
mov ESI, OFFSET wordStr ;so we restart the string each time

inner:
mov al, [ESI]
call WriteChar
inc ESI
loop inner

call Crlf
mov ECX, EBX
inc columns ;increasing columns
loop outer

;now storing ascii codes to memory
mov ECX, LENGTHOF codes ;already LENGTHOF wordStr - 1
mov ESI, OFFSET wordStr
mov EDI, OFFSET codes ;we can't use codes directly, need to use a pointer
mov sum, 0
ascii:
movzx EAX, BYTE PTR [ESI]
mov [EDI], EAX
inc ESI
add EDI, TYPE codes

call WriteDec ;printing each ascii already
mov EDX, OFFSET spacer
call WriteString
add sum, EAX ;here summing
loop ascii

;now displaying sum
call Crlf
mov EAX, sum
call WriteDec

;now lowercasing it all
;bitwise: Uppercase to Lowercase: Turn bit 5 ON using OR
;bitwise: Lowercase to Uppercase: Turn bit 5 OFF using AND
mov ECX, LENGTHOF codes
mov ESI, OFFSET wordStr
mov EAX, 0
call Crlf
lower:
or BYTE PTR [esi], 20h
inc ESI
loop lower

;now display lower new string
mov EDX, OFFSET wordStr
call WriteString

exit
main ENDP
END main