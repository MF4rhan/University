INCLUDE Irvine32.inc

.data

.code
main PROC

mov EAX, 49
call RandomRange
call WriteInt

exit
main ENDP
END main