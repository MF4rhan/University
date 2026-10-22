INCLUDE Irvine32.inc

rows = 4
cols = 3

.data
students DWORD 70, 80, 90
		 DWORD 60, 75, 85
		 DWORD 88, 92, 79
		 DWORD 55, 65, 70
msg1 BYTE "Total Marks of Student: ", 0
msg2 BYTE "Total Marks of all Class: ", 0

.code
main PROC

mov EBX, 0 ;used for total sum
mov ESI, OFFSET students
mov ECX, rows

l1:

push ECX
mov EAX, 0
mov ECX, cols

l2:
add EAX, [ESI]
add EBX, [ESI]
add ESI, TYPE students
loop l2

mov EDX, OFFSET msg1
call WriteString
call WriteDec
call Crlf
pop ECX

loop l1

mov EDX, OFFSET msg2
call WriteString
mov EAX, EBX
call WriteDec

exit
main ENDP
END main