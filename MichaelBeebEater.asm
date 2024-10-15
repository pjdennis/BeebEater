;TODOs
;-When handling keyboard, the escape character (#$1B) Should set escape condition immediately
;-When key pressed store ASCII to READBUFFER
;-Call BRKV when a break interrupt is encountered 
;-For now make sure the write character routing handles 0 since the startup message printing will send this
;-Make sure the display can handle the $0A $0D sequence for newline
;-Low memory should return the address of the page following the end of uploaded code
;-Sometimes escape from a tight print loop will cause a crash
;-Sometimes INPUT immediately returns with empty string without anything being typed
; BBC User guide - https://ntoll.org/static/files/BBC_User_Guide.pdf
; BBC Memory map - https://www.chibiakumas.com/6502/bbc.php

OSHWM = $0800

    .include BeebDefinitions.inc

    .org BASIC
    .incbin "Basic4r32.rom"

    .org CODE_START

reset:
; TODO initialize hardware

    JMP beebEaterReset

; On entry A contains the character to print
; On exit A, X, Y are preservered (per http://www.benryves.com/bin/bbcbasic/manual/OS_Call_OSWRCH.htm)
OSWRCHV:
; TODO write to screen. Handle $0A $0D sequence correctly.
    RTS

; TODO call push_key with A set to the ASCII of the key that is pushed.

code_interrupt:
; TODO
    RTI

    .include BeebEater.inc

    .include BeebEntryPoints.inc
