INCLUDE Irvine32.inc

.data
heading BYTE "Canteen Receipt", 0
sepLine BYTE 40 DUP(?), 0
sales DWORD 450, 480, 510, 540, 570, 600, 630, 660, 690, 720, 750, 780, 810, 840, 870, 900, 930, 960, 990, 1020

.code
main PROC
    cld
    mov edi, OFFSET sepLine
    mov ecx, 40
    mov al, '-'
    rep stosb

    mov edx, OFFSET heading
    call WriteString
    call Crlf
    mov edx, OFFSET sepLine
    call WriteString
    call Crlf

    call printSales

    cld
    mov edi, OFFSET sales
    mov ecx, LENGTHOF sales
    mov eax, 0
    rep stosd

    call printSales
    exit
main ENDP

printSales PROC
    mov esi, OFFSET sales
    mov ecx, LENGTHOF sales
L1:
    mov eax, [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE sales
    loop L1
    call Crlf
    ret
printSales ENDP
END main