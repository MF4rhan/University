INCLUDE Irvine32.inc


.data
menu DWORD 300, 450, 600, 250, 800, 550, 700

.code
main PROC
mov ESI, 4
mov EAX, menu[ESI*TYPE menu]
call writeDec

exit
main ENDP
END main