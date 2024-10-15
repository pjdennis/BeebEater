BASIC = $8000 ; the entry point for language rom.
CODE_START = $C000 ; the entry point for BeebEater. PJD - changed from START

; Hardware 6502-specific addresses
NMI = $FFFA ; This is the entry point for when we trigger a 'Non-Maskable Interupt'. 
RST = $FFFC ; RESET
IRQ = $FFFE ; Maskable interupts

OSKBD1  = $EC
OSAREG  = $EF
OSXREG  = $F0
OSYREG  = $F1
OSINTA  = $FC
OSFAULT = $FD

READBUFFER = OSKBD1 ; this stores the latest ASCII character that was sent into the ACIA


; BBC MOS "OS Calls". These addresses point to routines that access your hardware.
OSRDCH = $FFE0 ; "OS Read Character" - Transfers the characters read from the 6551 ACIA into Register A (Accumulator)
OSASCI = $FFE3 ; "OS ASCII" - Print an ASCII character stored in Register A (Accumulator)
OSNEWL = $FFE7 ; "OS New Line" - Print the 'CR' ASCII character, followed by the 'LF' character. These two characters make up a new line.
OSWRCH = $FFEE ; "OS Write Character" - Print a byte stored in the Accumulator. This doesn't necessarily have to be an ASCII one.
OSWORD = $FFF1 ; "OS Word" - A group of system calls that have parameters passed in a control block pointed to by the XY registers.
OSBYTE = $FFF4 ; "OS Byte" - A group of system calls that have byte parameters in the registers. This one is much simpler than OSWORD.

; PJD-Vector locations
OSRDCHV_ = $0210
OSWRCHV_ = $020E
OSWORDV_ = $020C
OSBYTEV_ = $020A


