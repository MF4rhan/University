INCLUDE Irvine32.inc

rows = 3
columns = 4
total_elements = rows * columns

.data
records DWORD 10, 15, 20, 25
DWORD 30, 10, 5, 15
DWORD 20, 20, 20, 20
msg1 BYTE "The Total Deliveries made are: ", 0

.code
main PROC

mov ESI, 0
mov EAX, 0
mov ECX, total_elements
L1:
add EAX, records[ESI * TYPE records]
inc ESI
loop L1

mov EDX, OFFSET msg1
call WriteString
call WriteInt

exit
main ENDP
END main