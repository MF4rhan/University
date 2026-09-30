INCLUDE Irvine32.inc
TAX EQU 1200

.data
NetPay DWORD ?

.code
main PROC
mov EAX, 0
mov EBX, 0
mov ECX, 0
mov EDX, 0

mov EAX, 30000
mov EBX, 5000

mov ECX, EBX
sub ECX, TAX

mov EDX, EAX
add EDX, ECX

call DumpRegs

exit
main ENDP
END main