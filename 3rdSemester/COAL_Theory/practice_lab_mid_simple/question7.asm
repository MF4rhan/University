INCLUDE Irvine32.inc

.data
sensor BYTE 0F6h

.code
main PROC
movzx EAX, [sensor]
movsx EDX, [sensor]

call DumpRegs

exit
main ENDP
END main