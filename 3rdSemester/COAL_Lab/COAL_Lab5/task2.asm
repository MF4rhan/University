INCLUDE Irvine32.inc

.data
value DWORD 00450078h
msg1 BYTE "Low Part (Hex) = ", 0
msg2 BYTE "High Part (Hex) = ", 0

.code
main PROC

mov EDX, OFFSET msg1
call WriteString

mov eax, [value]
movzx eax, ax
call WriteHex
call Crlf

mov EDX, OFFSET msg2
call WriteString

mov ax, WORD PTR [value + 2]
movzx eax, ax
call WriteHex
call Crlf


exit
main ENDP
END main