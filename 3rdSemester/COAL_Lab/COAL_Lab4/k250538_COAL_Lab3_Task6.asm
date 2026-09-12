INCLUDE Irvine32.inc

.data
array25 BYTE 25 DUP(0)

.code
main PROC

mov ECX, LENGTHOF array25
mov EBX, SIZEOF array25
movzx EAX, array25[0]
call DumpRegs

exit
main ENDP
END main
