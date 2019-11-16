
INCLUDE macros2.asm		 ;incluye macros
INCLUDE number.asm		 ;incluye el asm para impresion de numeros

.MODEL LARGE		 ; tipo del modelo de memoria usado.
.386
.387
.STACK 200h		 ; bytes en el stack
	
.DATA		 ; comienzo de la zona de datos.
	TRUE equ 1
	FALSE equ 0
	MAXTEXTSIZE equ 32
	p dd 0.0
	w dd 0
	j dd 0
	i dd 0
	c dd 0
	b dd 0
	a dd 0
	k db MAXTEXTSIZE dup(?), '$'
	x dd 0
	&cte1 dd 5
	&cte2 dd 22
	&cte3 dd 15
	&cte4 dd 4
	&cte5 dd 16
	&cte6 dd 32
	&cte7 dd 2
	&cte8 dd 7
	&cte9 dd 44
	&cte10 dd 2.3
	&cte11 dd 1.22
	&cte12 db "HOLA", '$', 26 dup(?)
	&cte13 db "hello", '$', 25 dup(?)
	&cte14 db "HOLA fdf 6543 mm", '$', 14 dup(?)
	&cte15 db "mundo", '$', 25 dup(?)
	&cte16 db "world", '$', 25 dup(?)
	@aux2 dd 0.0
	@aux3 dd 0.0
	@aux4 dd 0.0
	@aux5 dd 0.0
	@aux7 dd 0.0
	@aux8 dd 0.0
	@aux9 dd 0.0
	@aux10 dd 0.0
	@aux11 dd 0.0
	@aux12 dd 0.0
	@aux13 dd 0.0
	@aux14 dd 0.0
	@aux15 dd 0.0
	@aux16 dd 0.0
	@aux17 dd 0.0
	@aux18 dd 0.0
	@aux19 dd 0.0
	@aux20 dd 0.0
	@aux21 dd 0.0
	@aux22 dd 0.0
	@aux24 dd 0.0
	@aux25 dd 0.0
	@aux26 dd 0.0
	@aux27 dd 0.0
	@aux28 dd 0.0
	@aux29 dd 0.0
	@aux30 dd 0.0
	@aux31 dd 0.0
	@aux33 dd 0.0
	@aux34 dd 0.0
	@aux35 dd 0.0
	@aux37 dd 0.0
	@aux38 dd 0.0
	@aux39 dd 0.0
	@aux40 dd 0.0
	@aux41 dd 0.0
	@aux42 dd 0.0
	@aux43 dd 0.0
	@aux44 dd 0.0
	@aux46 dd 0.0
	@aux47 dd 0.0
	@aux48 dd 0.0
	@aux49 dd 0.0
	@aux51 dd 0.0
	@aux52 dd 0.0
	@aux53 dd 0.0
	@aux55 dd 0.0
	@aux56 dd 0.0
	@aux57 dd 0.0
	@aux58 dd 0.0
	@aux59 dd 0.0
	@aux60 dd 0.0
	@aux61 dd 0.0
	@aux62 dd 0.0
	@aux64 dd 0.0
	@aux65 dd 0.0
	@aux66 dd 0.0
	@aux67 dd 0.0
	@aux69 dd 0.0
	@aux70 dd 0.0
	@aux71 dd 0.0
	@aux72 dd 0.0
	@aux74 dd 0.0
	@aux75 dd 0.0
	@aux76 dd 0.0
	@aux77 dd 0.0
	@aux79 dd 0.0
	@aux80 dd 0.0
	@aux81 dd 0.0
	@aux82 dd 0.0
	@aux83 dd 0.0
	@aux84 dd 0.0
	@aux87 dd 0.0
	@aux88 dd 0.0
	@aux89 dd 0.0
	@aux90 dd 0.0
	@aux91 dd 0.0
	@aux92 dd 0.0
	@aux93 dd 0.0
	@aux94 dd 0.0
	@aux95 dd 0.0
	@aux96 dd 0.0
	@aux97 dd 0.0
	@aux98 dd 0.0
	@aux99 dd 0.0
	@aux100 dd 0.0
	@aux101 dd 0.0
	@aux102 dd 0.0
	@aux103 dd 0.0
	@aux104 dd 0.0
	@aux105 dd 0.0
	@aux106 dd 0.0
	@aux107 dd 0.0
	@aux108 dd 0.0
	@aux109 dd 0.0
	@aux110 dd 0.0
	@aux111 dd 0.0
	@aux112 dd 0.0
	@aux113 dd 0.0
	@aux114 dd 0.0
	@aux115 dd 0.0
	@aux116 dd 0.0
	@aux117 dd 0.0
	@aux118 dd 0.0
	@aux119 dd 0.0
	@aux120 dd 0.0

.CODE ;Comienzo de la zona de codigo
START: 		;Código assembler resultante de compilar el programa fuente.
	mov AX,@DATA 		;Inicializa el segmento de datos
	mov DS,AX
	finit



ETIQ_inicio_repeat_0:


ETIQ_inicio_1:
	;CMP
	fld a
	fld b
	fcomp
	fstsw ax
	fwait
	sahf

	ja ETIQ_fin_repeat_23


ETIQ_inicio_6:
	;SUMA
	fld a
	fld &cte1
	fadd
	fstp @aux9

	;ASIGNACIÓN
	fld @aux9
	fstp c

	;SUMA
	fld b
	fld &cte1
	fadd
	fstp @aux14

	;ASIGNACIÓN
	fld @aux14
	fstp c

	;SUMA
	fld a
	fld &cte2
	fadd
	fstp @aux19

	;ASIGNACIÓN
	fld @aux19
	fstp c

	jmp ETIQ_inicio_repeat_0


ETIQ_fin_repeat_23:
	;CMP
	fld i
	fld &cte3
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_fin_seleccion_36
	;CMP
	fld a
	fld &cte4
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_fin_seleccion_36


ETIQ_inicio_32:
	;ASIGNACIÓN
	fld &cte5
	fstp i



ETIQ_fin_seleccion_36:
	;CMP
	fld i
	fld &cte3
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_50
	;CMP
	fld a
	fld &cte4
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_50


ETIQ_inicio_45:
	;ASIGNACIÓN
	fld &cte5
	fstp i

	jmp ETIQ_fin_seleccion_54


ETIQ_inicio_50:
	;ASIGNACIÓN
	fld &cte6
	fstp i



ETIQ_fin_seleccion_54:
	;CMP
	fld i
	fld &cte3
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_68
	;CMP
	fld a
	fld &cte4
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_68


ETIQ_inicio_63:
	;ASIGNACIÓN
	fld &cte5
	fstp i

	jmp ETIQ_inicio_repeat_0


ETIQ_inicio_68:
	;CMP
	fld j
	fld &cte7
	fcomp
	fstsw ax
	fwait
	sahf

	jne ETIQ_inicio_78


ETIQ_inicio_73:
	;CMP
	fld w
	fld &cte8
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_fin_seleccion_86


ETIQ_inicio_78:
	;ASIGNACIÓN
	fld &cte6
	fstp i

	;ASIGNACIÓN
	fld &cte9
	fstp j



ETIQ_fin_seleccion_85:


ETIQ_fin_seleccion_86:
	;SUMA
	fld a
	fld b
	fadd
	fstp @aux89

	;SUMA
	fld b
	fld c
	fadd
	fstp @aux92

	;SUMA
	fld a
	fld b
	fadd
	fstp @aux95

	;SUMA
	fld b
	fld c
	fadd
	fstp @aux98

	;CMP
	fld @aux98
	fld &cte10
	fcomp
	fstsw ax
	fwait
	sahf

	jne ETIQ_inicio_repeat_0
	;CMP
	fld @aux95
	fld &cte11
	fcomp
	fstsw ax
	fwait
	sahf

	jne ETIQ_inicio_repeat_0
	;PRINT
	GetFloat b

	;PRINT
	getString &cte12

	;PRINT
	getString &cte13

	;PRINT
	getString &cte14

	;READ
	DisplayFloat p 2
	newLine 1

	;PRINT
	GetFloat i

	;PRINT
	getString &cte15

	;PRINT
	getString &cte16


TERMINAR: ;Fin de ejecución.
	mov ax, 4C00h ;termina la ejecución.
	int 21h ;syscall

END START ;final del archivo.