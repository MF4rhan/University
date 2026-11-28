INCLUDE Irvine32.inc

.data
tokens DWORD 301, 302, 303, 304, 305, 306, 307, 308, 309, ?

.code
main PROC
    mov esi, OFFSET tokens
    mov ecx, LENGTHOF tokens - 1
printBefore:
    mov eax, [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE tokens
    loop printBefore

    call Crlf

    std ; set direction flag to copy backwards so overlapping elements are not overwritten
    mov esi, OFFSET tokens + (LENGTHOF tokens - 2) * TYPE tokens
    mov edi, OFFSET tokens + (LENGTHOF tokens - 1) * TYPE tokens
    mov ecx, LENGTHOF tokens - 1
    rep movsd
    cld

    mov tokens, 300

    mov esi, OFFSET tokens
    mov ecx, LENGTHOF tokens
printAfter:
    mov eax, [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE tokens
    loop printAfter

    call Crlf
    exit
main ENDP
END main