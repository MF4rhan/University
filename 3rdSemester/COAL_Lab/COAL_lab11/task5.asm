INCLUDE Irvine32.inc

.data
stock DWORD 600, 575, 550, 525, 500, 475, 450, 425, 400, 375, 350, 325, 300, 275
notFoundMsg BYTE "Not found", 0

.code
main PROC
    call ReadDec
    cld
    mov edi, OFFSET stock
    mov ecx, LENGTHOF stock
    repne scasd
    jnz notFound

    mov eax, LENGTHOF stock
    sub eax, ecx
    call WriteDec
    call Crlf
    jmp done

notFound:
    mov edx, OFFSET notFoundMsg
    call WriteString
    call Crlf

done:
    exit
main ENDP
END main