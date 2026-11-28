INCLUDE Irvine32.inc

.data
carelessName BYTE "muhammad farhan####", 0
capitalName BYTE "MUHAMMAD FARHAN", 0
finalRecord BYTE LENGTHOF carelessName DUP(?)
matchMsg BYTE "Record matches", 0
noMatchMsg BYTE "Record does not match", 0

.code
main PROC
    INVOKE Str_length, ADDR carelessName
    call WriteDec
    call Crlf

    INVOKE Str_trim, ADDR carelessName, '#'
    INVOKE Str_ucase, ADDR carelessName

    INVOKE Str_copy, ADDR carelessName, ADDR finalRecord

    INVOKE Str_length, ADDR finalRecord
    call WriteDec
    call Crlf

    INVOKE Str_compare, ADDR finalRecord, ADDR capitalName
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