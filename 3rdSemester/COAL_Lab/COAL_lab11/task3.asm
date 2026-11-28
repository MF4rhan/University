INCLUDE Irvine32.inc

.data
pass1 BYTE "Fast1234", 0
pass2 BYTE "Fast1234", 0
sameMsg BYTE "Passwords are the same", 0
diffMsg BYTE "Different at position: ", 0

.code
main PROC
    cld
    mov esi, OFFSET pass1
    mov edi, OFFSET pass2
    mov ecx, LENGTHOF pass1
    repe cmpsb
    jz same

    mov edx, OFFSET diffMsg
    call WriteString
    sub esi, OFFSET pass1
    dec esi
    mov eax, esi
    call WriteDec
    call Crlf
    jmp done

same:
    mov edx, OFFSET sameMsg
    call WriteString
    call Crlf

done:
    exit
main ENDP
END main