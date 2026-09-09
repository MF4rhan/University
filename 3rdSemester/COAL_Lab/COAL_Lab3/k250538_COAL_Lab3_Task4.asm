INCLUDE Irvine32.inc
COMMENT @
so this program is supposed to add the price of individual items,
and then subtract it from the payment amount.
@

.data
bill WORD 0

.code
main PROC
add bill, 10 ;adding 10 to the bill
add bill, 20 ;adding 20 to the bill
mov eax, 0 ;cleaning the eax register
mov ax, 50 ;the payment for the bill
sub ax, bill ;subtracting bill from payment

call DumpRegs

exit
main ENDP
END main
