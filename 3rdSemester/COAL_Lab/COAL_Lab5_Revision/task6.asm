INCLUDE Irvine32.inc
.data
SensorID DWORD 14
SensorStatus BYTE 1
SensorReading WORD 69
msg1 BYTE "Gap Between SensorID and SensorStatus: ", 0
msg2 BYTE "Gap between SensorStatus and SensorReading: ", 0
.code
main PROC

mov EDX, OFFSET msg1
call WriteString
mov EAX, OFFSET SensorStatus
sub EAX, OFFSET SensorID
call WriteDec

call Crlf

mov EDX, OFFSET msg2
call WriteString
mov EAX, OFFSET SensorReading
sub EAX, OFFSET SensorStatus
call WriteDec

exit
main ENDP
END main