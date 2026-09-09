NCLUDE Irvine32.inc
COMMENT*
Name: Muhammad Farhan
Roll no: 25K-0538
The task is to show and practice how the comments work,
reasoning for which data type to use and when.
its fun.
*

.data
rolly WORD 0538 ;WORD because 538 is too big for BYTE
phoney DWORD 1234567 ; DWORD because phone number needs more space
namae BYTE "Farhano", 0 ;string is stored in BYTE regardless of size i believe

.code
main PROC

exit
main ENDP
END main
