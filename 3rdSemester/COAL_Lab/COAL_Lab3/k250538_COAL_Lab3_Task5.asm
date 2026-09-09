INCLUDE Irvine32.inc

.data
age BYTE 10
phone DWORD 1234567
temperature SBYTE -60
serial_number QWORD 223497243987

.code
main PROC
mov EAX, 0 ;clearing register for easy readability
mov al, temperature

call DumpRegs

exit
main ENDP
END main
