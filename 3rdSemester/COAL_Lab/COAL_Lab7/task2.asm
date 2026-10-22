INCLUDE Irvine32.inc

.data
string BYTE "KARACHI", 0
lengthy DWORD LENGTHOF string - 1

.code
main PROC

mov ECX, lengthy
mov ESI, OFFSET string
l1:
movzx EAX, BYTE PTR [ESI]
push EAX
inc ESI
loop l1

mov ECX, lengthy
l2:
pop EAX
call WriteChar
loop l2

exit
main ENDP
END main