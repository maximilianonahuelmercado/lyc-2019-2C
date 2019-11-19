
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
	&cte1 dd 1
	&cte2 dd 2
	&cte3 dd 3
	&cte4 dd 5
	&cte5 dd 22
	&cte6 dd 15
	&cte7 dd 4
	&cte8 dd 16
	&cte9 dd 32
	&cte10 dd 7
	&cte11 dd 44
	&cte12 dd 2.3
	&cte13 dd 1.22
	&cte14 db "HOLA", '$', 26 dup(?)
	&cte15 db "hello", '$', 25 dup(?)
	&cte16 db "HOLA fdf 6543 mm", '$', 14 dup(?)
	&cte17 db "mundo", '$', 25 dup(?)
	&cte18 db "world", '$', 25 dup(?)
	@aux1 dd 0.0
	@aux2 dd 0.0
	@aux3 dd 0.0
	@aux4 dd 0.0
	@aux5 dd 0.0
	@aux6 dd 0.0
	@aux7 dd 0.0
	@aux8 dd 0.0
	@aux9 dd 0.0
	@aux10 dd 0.0
	@aux11 dd 0.0
	@aux12 dd 0.0
	@aux14 dd 0.0
	@aux15 dd 0.0
	@aux16 dd 0.0
	@aux17 dd 0.0
	@aux19 dd 0.0
	@aux20 dd 0.0
	@aux21 dd 0.0
	@aux22 dd 0.0
	@aux23 dd 0.0
	@aux24 dd 0.0
	@aux25 dd 0.0
	@aux26 dd 0.0
	@aux27 dd 0.0
	@aux28 dd 0.0
	@aux29 dd 0.0
	@aux30 dd 0.0
	@aux31 dd 0.0
	@aux32 dd 0.0
	@aux33 dd 0.0
	@aux34 dd 0.0
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
	@aux51 dd 0.0
	@aux52 dd 0.0
	@aux53 dd 0.0
	@aux54 dd 0.0
	@aux55 dd 0.0
	@aux56 dd 0.0
	@aux57 dd 0.0
	@aux58 dd 0.0
	@aux60 dd 0.0
	@aux61 dd 0.0
	@aux62 dd 0.0
	@aux63 dd 0.0
	@aux65 dd 0.0
	@aux66 dd 0.0
	@aux67 dd 0.0
	@aux70 dd 0.0
	@aux71 dd 0.0
	@aux72 dd 0.0
	@aux73 dd 0.0
	@aux74 dd 0.0
	@aux75 dd 0.0
	@aux76 dd 0.0
	@aux77 dd 0.0
	@aux79 dd 0.0
	@aux80 dd 0.0
	@aux81 dd 0.0
	@aux82 dd 0.0
	@aux84 dd 0.0
	@aux85 dd 0.0
	@aux86 dd 0.0
	@aux87 dd 0.0
	@aux89 dd 0.0
	@aux90 dd 0.0
	@aux91 dd 0.0
	@aux92 dd 0.0
	@aux94 dd 0.0
	@aux95 dd 0.0
	@aux96 dd 0.0
	@aux97 dd 0.0
	@aux98 dd 0.0
	@aux99 dd 0.0
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
	@aux122 dd 0.0
	@aux123 dd 0.0
	@aux124 dd 0.0
	@aux125 dd 0.0
	@aux126 dd 0.0
	@aux127 dd 0.0
	@aux128 dd 0.0
	@aux129 dd 0.0
	@aux131 dd 0.0
	@aux132 dd 0.0
	@aux133 dd 0.0
	@aux134 dd 0.0
	@aux135 dd 0.0
	@aux136 dd 0.0
	@aux137 dd 0.0
	@aux138 dd 0.0
	@aux139 dd 0.0
	@aux140 dd 0.0
	@aux141 dd 0.0
	@aux142 dd 0.0
	@aux143 dd 0.0
	@aux144 dd 0.0
	@aux145 dd 0.0
	@aux146 dd 0.0

.CODE ;Comienzo de la zona de codigo
START: 		;Código assembler resultante de compilar el programa fuente.
	mov AX,@DATA 		;Inicializa el segmento de datos
	mov DS,AX
	finit



ETIQ_inicio_0:
	;ASIGNACIÓN
	fld b
	fstp a

	;ASIGNACIÓN
	fld &cte1
	fstp i

	;ASIGNACIÓN
	fld &cte2
	fstp j

	;ASIGNACIÓN
	fld &cte3
	fstp w



ETIQ_inicio_repeat_13:
	;CMP
	fld a
	fld b
	fcomp
	fstsw ax
	fwait
	sahf

	ja ETIQ_fin_repeat_35


ETIQ_inicio_18:
	;SUMA
	fld a
	fld &cte4
	fadd
	fstp @aux21

	;ASIGNACIÓN
	fld @aux21
	fstp c

	;SUMA
	fld b
	fld &cte4
	fadd
	fstp @aux26

	;ASIGNACIÓN
	fld @aux26
	fstp c

	;SUMA
	fld a
	fld &cte5
	fadd
	fstp @aux31

	;ASIGNACIÓN
	fld @aux31
	fstp c

	jmp ETIQ_inicio_repeat_13


ETIQ_fin_repeat_35:


ETIQ_inicio_36:
	;CMP
	fld i
	fld &cte6
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_fin_seleccion_49
	;CMP
	fld a
	fld &cte7
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_fin_seleccion_49


ETIQ_inicio_45:
	;ASIGNACIÓN
	fld &cte8
	fstp i



ETIQ_fin_seleccion_49:


ETIQ_inicio_50:
	;CMP
	fld i
	fld &cte6
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_64
	;CMP
	fld a
	fld &cte7
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_64


ETIQ_inicio_59:
	;ASIGNACIÓN
	fld &cte8
	fstp i

	jmp ETIQ_fin_seleccion_68


ETIQ_inicio_64:
	;ASIGNACIÓN
	fld &cte9
	fstp i



ETIQ_fin_seleccion_68:


ETIQ_inicio_69:
	;CMP
	fld i
	fld &cte6
	fcomp
	fstsw ax
	fwait
	sahf

	je ETIQ_inicio_83
	;CMP
	fld a
	fld &cte7
	fcomp
	fs