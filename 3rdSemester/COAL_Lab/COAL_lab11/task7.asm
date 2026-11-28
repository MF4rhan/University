INCLUDE Irvine32.inc

.data
bills DWORD 280, 325, 370, 415, 460, 505, 550, 595, 640, 685

.code
main PROC
    cld
    mov esi, OFFSET bills
    mov edi, OFFSET bills
    mov ecx, LENGTHOF bills
    mov ebx, 0

updateLoop:
    lodsd
    cmp eax, 500
    jae skipCharge
    add eax, 60
skipCharge:
    stosd
    add ebx, eax
    loop updateLoop

    mov esi, OFFSET bills
    mov ecx, LENGTHOF bills
printBills:
    lodsd
    call WriteDec
    mov al, ' '
    call WriteChar
    loop printBills

    call Crlf
    mov eax, ebx
    call WriteDec
    call Crlf
    exit
main ENDP
END main