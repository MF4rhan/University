INCLUDE Irvine32.inc

.data
studentName BYTE "Farhan", 0
backupName BYTE LENGTHOF studentName DUP(?)

marks WORD 52, 56, 60, 64, 68, 72, 76, 80
backupMarks WORD LENGTHOF marks DUP(?)

.code
main PROC
    cld

    mov esi, OFFSET studentName
    mov edi, OFFSET backupName
    mov ecx, LENGTHOF studentName
    rep movsb

    mov esi, OFFSET marks
    mov edi, OFFSET backupMarks
    mov ecx, LENGTHOF marks
    rep movsw

    mov esi, OFFSET marks
    mov ecx, LENGTHOF marks
addGrace:
    add WORD PTR [esi], 5
    add esi, TYPE marks
    loop addGrace

    mov esi, OFFSET marks
    mov ecx, LENGTHOF marks
printOrig:
    movzx eax, WORD PTR [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE marks
    loop printOrig

    call Crlf

    mov esi, OFFSET backupMarks
    mov ecx, LENGTHOF backupMarks
printBackup:
    movzx eax, WORD PTR [esi]
    call WriteDec
    mov al, ' '
    call WriteChar
    add esi, TYPE backupMarks
    loop printBackup

    call Crlf
    exit
main ENDP
END main