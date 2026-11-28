INCLUDE Irvine32.inc

.data
validEmail BYTE "muhammad.farhan@nu.edu.pk", 0
invalidEmail BYTE "muhammad.farhan.nu.edu.pk", 0
invalidMsg BYTE "Email is invalid", 0

.code
main PROC
    mov edi, OFFSET validEmail
    mov ecx, LENGTHOF validEmail - 1
    call checkEmail

    mov edi, OFFSET invalidEmail
    mov ecx, LENGTHOF invalidEmail - 1
    call checkEmail

    exit
main ENDP

checkEmail PROC
    cld
    mov ebx, edi
    mov al, '@'
    repne scasb
    jnz notFound

    push edi
    mov eax, edi
    sub eax, ebx
    dec eax
    call WriteDec
    call Crlf

    pop edx
    call WriteString
    call Crlf
    ret

notFound:
    mov edx, OFFSET invalidMsg
    call WriteString
    call Crlf
    ret
checkEmail ENDP
END main