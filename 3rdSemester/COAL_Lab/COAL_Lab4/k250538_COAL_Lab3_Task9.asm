INCLUDE Irvine32.inc

.data

industrialSensor BYTE 80h


.code
main PROC

movzx eax, industrialSensor
movsx ebx, industrialSensor

call DumpRegs

exit
main ENDP
END main
