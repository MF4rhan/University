INCLUDE Irvine32.inc

.data
units DWORD 30, 34, 38, 42
rowSize = ($ - units)
      DWORD 36, 40, 44, 48
      DWORD 42, 46, 50, 54
      DWORD 48, 52, 56, 60
      DWORD 54, 58, 62, 66
errMsg BYTE "Invalid input", 0
grandTotal DWORD 0

.code
main PROC
askHouse:
    call ReadInt
    cmp eax, 1
    jl badHouse
    cmp eax, 5
    jg badHouse
    mov ebx, eax
    dec ebx
    jmp askWeek

badHouse:
    mov edx, OFFSET errMsg
    call WriteString
    call Crlf
    jmp askHouse

askWeek:
    call ReadInt
    cmp eax, 1
    jl badWeek
    cmp eax, 4
    jg badWeek
    mov esi, eax
    dec esi
    jmp updateEntry

badWeek:
    mov edx, OFFSET errMsg
    call WriteString
    call Crlf
    jmp askWeek

updateEntry:
    mov eax, ebx
    mov edx, rowSize
    mul edx
    mov ebx, eax

    mov eax, units[ebx + esi * TYPE units]
    call WriteDec
    call Crlf

    add units[ebx + esi * TYPE units], 15

    mov ebx, 0
    mov ecx, 5
rowLoop:
    push ecx
    mov esi, 0
    mov edx, 0
    mov ecx, 4
colLoop:
    mov eax, units[ebx + esi * TYPE units]
    call WriteDec
    mov al, ' '
    call WriteChar
    add edx, units[ebx + esi * TYPE units]
    inc esi
    loop colLoop

    mov eax, edx
    call WriteDec
    call Crlf
    add grandTotal, edx
    add ebx, rowSize
    pop ecx
    loop rowLoop

    mov eax, grandTotal
    call WriteDec
    call Crlf
    exit
main ENDP
END main