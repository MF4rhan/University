INCLUDE Irvine32.inc

.data
carelessName BYTE "muhammad farhan jamali####", 0
capitalName BYTE "MUHAMMAD FARHAN JAMALI", 0
finalRecord BYTE LENGTHOF carelessName DUP(?)
matchMsg BYTE "Record matches", 0
noMatchMsg BYTE "Record does not match", 0

.code
main PROC
    mov edx, OFFSET carelessName
    call Str_length
    call WriteDec
    call Crlf

    mov edx, OFFSET carelessName
    mov al, '#'
    call Str_trim
    call Str_ucase

    mov esi, OFFSET carelessName
    mov edi, OFFSET finalRecord
    call Str_copy

    mov edx, OFFSET finalRecord
    call Str_length
    call WriteDec
    call Crlf

    mov esi, OFFSET finalRecord
    mov edi, OFFSET capitalName
    call Str_compare
    je matched

    mov edx, OFFSET noMatchMsg
    call WriteString
    call Crlf
    jmp done

matched:
    mov edx, OFFSET matchMsg
    call WriteString
    call Crlf

done:
    exit
main ENDP
END main