INCLUDE Irvine32.inc

.data
cinema WORD 500, 750, 750, 1000, 1000, 1200
msg1 BYTE "Price of Seat 4 = ",0

.code
main PROC
mov esi, 3

mov edx, offset msg1
call WriteString

mov ax, [cinema + (TYPE cinema * esi)]
movzx EAX, ax
call WriteInt
exit
main ENDP
END main