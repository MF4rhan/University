INCLUDE Irvine32.inc

.data
sales WORD 1500, 1620, 1740, 1860, 1980, 2100
rowSize = ($ - sales)
      WORD 1700, 1820, 1940, 2060, 2180, 2300
      WORD 1900, 2020, 2140, 2260, 2380, 2500
      WORD 2100, 2220, 2340, 2460, 2580, 2700
errMsg BYTE "Invalid month", 0

.code
main PROC
askMonth:
    call ReadInt
    cmp eax, 1
    jl invalid
    cmp eax, 6
    jg invalid
    jmp valid

invalid:
    mov edx, OFFSET errMsg
    call WriteString
    call Crlf
    jmp askMonth

valid:
    dec eax
    mov esi, eax
    mov ebx, OFFSET sales
    mov ecx, 4
    mov edx, 0

sumLoop:
    movzx eax, WORD PTR [ebx + esi * TYPE sales]
    add edx, eax
    add ebx, rowSize
    loop sumLoop

    mov eax, edx
    call WriteDec
    call Crlf

    xor edx, edx
    mov ebx, 4
    div ebx
    call WriteDec
    call Crlf

    exit
main ENDP
END main