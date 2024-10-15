    ; BBC MOS system calls. Code call these by jumping to their place in memory.
    ; Most of them jump to a 'vector' that properly handles the system call.
    
    .org $FFB6
    .byte 0,0,0 ; no vector table
    .byte $60,$60,$60 ; FFB9
    .byte $60,$60,$60 ; FFBC
    .byte $60,$60,$60 ; FFBF
    .byte $60,$60,$60 ; FFC2
    .byte $60,$60,$60 ; FFC5
    .byte $60,$60,$60 ; FFC8
    .byte $60,$60,$60 ; FFCB
    .byte $60,$60,$60 ; FFCE
    .byte $60,$60,$60 ; FFD1
    .byte $60,$60,$60 ; FFD4
    .byte $60,$60,$60 ; FFD7
    .byte $60,$60,$60 ; FFDA
    .byte $60,$60,$60 ; FFDD

    JMP (OSRDCHV_) ; FFE0 ; PJD changed from JMP OSRDCHV
    .org OSASCI ; FFE3
    CMP #$0D ; Is it carriage return? Jump to OSNEWL, otherwise fall through to OSWRCH.
    BNE OSWRCH
    ; If it's carriage return, fall through to OSNEWL

    .org OSNEWL ; OSNEWL is essentially OSWRCH, but with a line break (CR+LF)
    LDA #$0A ; Send 'Carriage Return' character.
    JSR OSWRCH
    LDA #$0D ; Send a 'Line Feed' character. CR+LF make up a complete line break.
    ; fall through to OSWRCH

    .org OSWRCH
    ; PJD - changed to JMP (OSWRCHV_)
    JMP (OSWRCHV_) ; At address 'OSWRCH', jump to the 'OSWRCHV' routine (AKA a 'vector').

    .org OSWORD
    JMP (OSWORDV_) ; PJD - Changed from JMP OSWORDV

    .org OSBYTE
    JMP (OSBYTEV_) ; PJD - Changed from JMP OSBYTEV
    .byte $60,$60,$60 ; FFF7

    ; 6502-specific calls, such as interrupts and resets.
    .org NMI
    .word code_interrupt ; at NMI, go to interrupt handler; PJD - changed from interrupt
    .word reset ; at RESET address, go to reset label
    .word code_interrupt ; When IRQ goes low or BRK is called, go to the interrupt handler
