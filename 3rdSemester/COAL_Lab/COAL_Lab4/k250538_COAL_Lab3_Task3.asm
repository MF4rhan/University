INCLUDE Irvine32.inc

.data

Ali word 78
Sara word 85

.code
main PROC

mov ax, Ali
xchg Sara, ax
mov ali, ax


movzx eax, Ali ; moving ali marks into eax for print
call writedec ; displays 85
call crlf ; skip line

movzx eax, Sara ; moving sara marks into ebx for print
call writedec ; displays 78


exit

main ENDP
END main
