INCLUDE Irvine32.inc

.data
msg1 BYTE "Enter Account Balance: ", 0
msg2 BYTE "Enter Withdrawal Amount: ", 0
msg3 BYTE "Transaction logged", 0
msg4 BYTE "Remaining Balance: ", 0

balance DWORD ?
withdraw DWORD ?

.code
main PROC
mov EDX, OFFSET msg1
call WriteString
call ReadInt
mov balance, EAX

mov EDX, OFFSET msg2
call WriteString
call ReadInt
mov withdraw, EAX

mov EAX, balance
sub EAX, withdraw

call audit

call DumpRegs

call Crlf
mov EDX, OFFSET msg4
call WriteString
call WriteDec
call Crlf

exit
main ENDP

audit PROC
pushad
pushfd

mov EDX, OFFSET msg3
call WriteString
call Crlf

mov EBX, 5
add EBX, 10

popfd
popad
ret
audit ENDP

END main