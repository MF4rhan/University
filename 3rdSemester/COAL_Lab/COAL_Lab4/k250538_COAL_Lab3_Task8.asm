NCLUDE Irvine32.inc

.data
MidtermScore SDWORD 35
FinalExamScore SDWORD 55
Deductions SDWORD 8
FinalGrade SDWORD ?

.code
main PROC
mov EAX, MidtermScore
mov EBX, FinalExamScore
mov ECX, Deductions

mov EDX, EBX
sub EDX, ECX
add EDX, EAX

mov FinalGrade, EDX

call DumpRegs

exit
main ENDP
END main
