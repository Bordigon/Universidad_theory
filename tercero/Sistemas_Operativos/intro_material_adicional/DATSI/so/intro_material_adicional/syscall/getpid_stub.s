# función ensamblador que realiza la llamada al sistema getpid
.section  .note.GNU-stack, "", @progbits
.section .text
.global call_getpid

call_getpid:
    # Por convenio, en Linux se especifica el número de la llamada
    # en el registro RAX (getpid -> 39) 
    movq $39, %rax
    # Instrucción que realiza la llamada pasando a modo núcleo.
    # Por convenio, en Linux se devuelve el resultado en RAX
    syscall
    ret
