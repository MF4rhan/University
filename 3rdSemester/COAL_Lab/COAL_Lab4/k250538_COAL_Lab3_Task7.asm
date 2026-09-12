INCLUDE Irvine32.inc

.data

breakduration BYTE 15
days = 6
periods = 8

grid BYTE days * periods Dup (0)

.code
main PROC



exit
main ENDP
END main
