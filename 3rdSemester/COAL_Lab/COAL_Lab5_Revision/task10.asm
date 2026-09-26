INCLUDE Irvine32.inc

.data
    salaries DWORD 45, 60, 38, 72, 50
    msgNum   BYTE "Number of employees recorded: ", 0
    msgSize  BYTE "Total memory used (bytes): ", 0
    msgTotal BYTE "Combined total salary: ", 0

.code
main PROC
    
    mov EDX, OFFSET msgNum
    call WriteString
    mov EAX, LENGTHOF salaries
    call WriteDec
    call Crlf

    mov EDX, OFFSET msgSize
    call WriteString
    mov EAX, SIZEOF salaries   
    call WriteDec
    call Crlf

    mov ESi, OFFSET salaries 
    mov ECX, LENGTHOF salaries   
    mov EAX, 0                

L1:
    add EAX, [ESI]                 
    add ESI, TYPE salaries         
    loop L1

    mov EDX, OFFSET msgTotal
    call WriteString
    call WriteDec                 
    call Crlf

    exit
main ENDP
END main