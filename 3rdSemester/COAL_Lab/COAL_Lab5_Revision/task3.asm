INCLUDE Irvine32.inc

.data
sales WORD 1200, 1500, 900, 1750, 2000

.code
main PROC
mov ESI, OFFSET sales
mov ECX, LENGTHOF sales
mov EAX, 0

L1:
movzx EBX, WORD PTR [ESI]
add EAX, EBX
add ESI, TYPE sales
loop L1

call WriteDec

exit
main ENDP
END main