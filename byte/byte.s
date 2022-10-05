	.file	"byte.cc"
	.text
	.section	.text._ZnwmPv,"axG",@progbits,_ZnwmPv,comdat
	.weak	_ZnwmPv
	.type	_ZnwmPv, @function
_ZnwmPv:
.LFB286:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE286:
	.size	_ZnwmPv, .-_ZnwmPv
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZStanSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStanSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStanSt13_Ios_FmtflagsS_
	.type	_ZStanSt13_Ios_FmtflagsS_, @function
_ZStanSt13_Ios_FmtflagsS_:
.LFB1343:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	andl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1343:
	.size	_ZStanSt13_Ios_FmtflagsS_, .-_ZStanSt13_Ios_FmtflagsS_
	.section	.text._ZStorSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStorSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStorSt13_Ios_FmtflagsS_
	.type	_ZStorSt13_Ios_FmtflagsS_, @function
_ZStorSt13_Ios_FmtflagsS_:
.LFB1344:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	orl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1344:
	.size	_ZStorSt13_Ios_FmtflagsS_, .-_ZStorSt13_Ios_FmtflagsS_
	.section	.text._ZStcoSt13_Ios_Fmtflags,"axG",@progbits,_ZStcoSt13_Ios_Fmtflags,comdat
	.weak	_ZStcoSt13_Ios_Fmtflags
	.type	_ZStcoSt13_Ios_Fmtflags, @function
_ZStcoSt13_Ios_Fmtflags:
.LFB1346:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	notl	%eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1346:
	.size	_ZStcoSt13_Ios_Fmtflags, .-_ZStcoSt13_Ios_Fmtflags
	.section	.text._ZStoRRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStoRRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStoRRSt13_Ios_FmtflagsS_
	.type	_ZStoRRSt13_Ios_FmtflagsS_, @function
_ZStoRRSt13_Ios_FmtflagsS_:
.LFB1347:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStorSt13_Ios_FmtflagsS_
	movq	-8(%rbp), %rdx
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1347:
	.size	_ZStoRRSt13_Ios_FmtflagsS_, .-_ZStoRRSt13_Ios_FmtflagsS_
	.section	.text._ZStaNRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStaNRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStaNRSt13_Ios_FmtflagsS_
	.type	_ZStaNRSt13_Ios_FmtflagsS_, @function
_ZStaNRSt13_Ios_FmtflagsS_:
.LFB1348:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movq	-8(%rbp), %rdx
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1348:
	.size	_ZStaNRSt13_Ios_FmtflagsS_, .-_ZStaNRSt13_Ios_FmtflagsS_
	.section	.text._ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,comdat
	.align 2
	.weak	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.type	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, @function
_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_:
.LFB1377:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	24(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %edi
	call	_ZStcoSt13_Ios_Fmtflags
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	$24, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStaNRSt13_Ios_FmtflagsS_
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	$24, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStoRRSt13_Ios_FmtflagsS_
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1377:
	.size	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, .-_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.section	.text._ZSt3hexRSt8ios_base,"axG",@progbits,_ZSt3hexRSt8ios_base,comdat
	.weak	_ZSt3hexRSt8ios_base
	.type	_ZSt3hexRSt8ios_base, @function
_ZSt3hexRSt8ios_base:
.LFB1405:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$74, %edx
	movl	$8, %esi
	movq	%rax, %rdi
	call	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1405:
	.size	_ZSt3hexRSt8ios_base, .-_ZSt3hexRSt8ios_base
	.section	.rodata
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.section	.text._ZSt4setwi,"axG",@progbits,_ZSt4setwi,comdat
	.weak	_ZSt4setwi
	.type	_ZSt4setwi, @function
_ZSt4setwi:
.LFB3591:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3591:
	.size	_ZSt4setwi, .-_ZSt4setwi
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.type	_ZStL10defer_lock, @object
	.size	_ZStL10defer_lock, 1
_ZStL10defer_lock:
	.zero	1
	.type	_ZStL11try_to_lock, @object
	.size	_ZStL11try_to_lock, 1
_ZStL11try_to_lock:
	.zero	1
	.type	_ZStL10adopt_lock, @object
	.size	_ZStL10adopt_lock, 1
_ZStL10adopt_lock:
	.zero	1
	.align 4
	.type	_ZNSt15regex_constantsL5icaseE, @object
	.size	_ZNSt15regex_constantsL5icaseE, 4
_ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL6nosubsE, @object
	.size	_ZNSt15regex_constantsL6nosubsE, 4
_ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL8optimizeE, @object
	.size	_ZNSt15regex_constantsL8optimizeE, 4
_ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL7collateE, @object
	.size	_ZNSt15regex_constantsL7collateE, 4
_ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL10ECMAScriptE, @object
	.size	_ZNSt15regex_constantsL10ECMAScriptE, 4
_ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
	.type	_ZNSt15regex_constantsL5basicE, @object
	.size	_ZNSt15regex_constantsL5basicE, 4
_ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
	.type	_ZNSt15regex_constantsL8extendedE, @object
	.size	_ZNSt15regex_constantsL8extendedE, 4
_ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
	.type	_ZNSt15regex_constantsL3awkE, @object
	.size	_ZNSt15regex_constantsL3awkE, 4
_ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
	.type	_ZNSt15regex_constantsL4grepE, @object
	.size	_ZNSt15regex_constantsL4grepE, 4
_ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
	.type	_ZNSt15regex_constantsL5egrepE, @object
	.size	_ZNSt15regex_constantsL5egrepE, 4
_ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
	.type	_ZNSt15regex_constantsL12__polynomialE, @object
	.size	_ZNSt15regex_constantsL12__polynomialE, 4
_ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
	.type	_ZNSt15regex_constantsL13match_defaultE, @object
	.size	_ZNSt15regex_constantsL13match_defaultE, 4
_ZNSt15regex_constantsL13match_defaultE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_bolE, @object
	.size	_ZNSt15regex_constantsL13match_not_bolE, 4
_ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_eolE, @object
	.size	_ZNSt15regex_constantsL13match_not_eolE, 4
_ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_bowE, @object
	.size	_ZNSt15regex_constantsL13match_not_bowE, 4
_ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_eowE, @object
	.size	_ZNSt15regex_constantsL13match_not_eowE, 4
_ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL9match_anyE, @object
	.size	_ZNSt15regex_constantsL9match_anyE, 4
_ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
	.type	_ZNSt15regex_constantsL14match_not_nullE, @object
	.size	_ZNSt15regex_constantsL14match_not_nullE, 4
_ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
	.type	_ZNSt15regex_constantsL16match_continuousE, @object
	.size	_ZNSt15regex_constantsL16match_continuousE, 4
_ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
	.type	_ZNSt15regex_constantsL16match_prev_availE, @object
	.size	_ZNSt15regex_constantsL16match_prev_availE, 4
_ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
	.type	_ZNSt15regex_constantsL14format_defaultE, @object
	.size	_ZNSt15regex_constantsL14format_defaultE, 4
_ZNSt15regex_constantsL14format_defaultE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL10format_sedE, @object
	.size	_ZNSt15regex_constantsL10format_sedE, 4
_ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
	.type	_ZNSt15regex_constantsL14format_no_copyE, @object
	.size	_ZNSt15regex_constantsL14format_no_copyE, 4
_ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
	.type	_ZNSt15regex_constantsL17format_first_onlyE, @object
	.size	_ZNSt15regex_constantsL17format_first_onlyE, 4
_ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
	.type	_ZNSt15regex_constantsL13error_collateE, @object
	.size	_ZNSt15regex_constantsL13error_collateE, 4
_ZNSt15regex_constantsL13error_collateE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_ctypeE, @object
	.size	_ZNSt15regex_constantsL11error_ctypeE, 4
_ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL12error_escapeE, @object
	.size	_ZNSt15regex_constantsL12error_escapeE, 4
_ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13error_backrefE, @object
	.size	_ZNSt15regex_constantsL13error_backrefE, 4
_ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
	.type	_ZNSt15regex_constantsL11error_brackE, @object
	.size	_ZNSt15regex_constantsL11error_brackE, 4
_ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_parenE, @object
	.size	_ZNSt15regex_constantsL11error_parenE, 4
_ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
	.type	_ZNSt15regex_constantsL11error_braceE, @object
	.size	_ZNSt15regex_constantsL11error_braceE, 4
_ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
	.type	_ZNSt15regex_constantsL14error_badbraceE, @object
	.size	_ZNSt15regex_constantsL14error_badbraceE, 4
_ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
	.type	_ZNSt15regex_constantsL11error_rangeE, @object
	.size	_ZNSt15regex_constantsL11error_rangeE, 4
_ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL11error_spaceE, @object
	.size	_ZNSt15regex_constantsL11error_spaceE, 4
_ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
	.type	_ZNSt15regex_constantsL15error_badrepeatE, @object
	.size	_ZNSt15regex_constantsL15error_badrepeatE, 4
_ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
	.type	_ZNSt15regex_constantsL16error_complexityE, @object
	.size	_ZNSt15regex_constantsL16error_complexityE, 4
_ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
	.type	_ZNSt15regex_constantsL11error_stackE, @object
	.size	_ZNSt15regex_constantsL11error_stackE, 4
_ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 8
	.type	_ZNSt8__detailL19_S_invalid_state_idE, @object
	.size	_ZNSt8__detailL19_S_invalid_state_idE, 8
_ZNSt8__detailL19_S_invalid_state_idE:
	.quad	-1
	.section	.text._ZSt3minImERKT_S2_S2_,"axG",@progbits,_ZSt3minImERKT_S2_S2_,comdat
	.weak	_ZSt3minImERKT_S2_S2_
	.type	_ZSt3minImERKT_S2_S2_, @function
_ZSt3minImERKT_S2_S2_:
.LFB7760:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jnb	.L20
	movq	-16(%rbp), %rax
	jmp	.L21
.L20:
	movq	-8(%rbp), %rax
.L21:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7760:
	.size	_ZSt3minImERKT_S2_S2_, .-_ZSt3minImERKT_S2_S2_
	.section	.rodata
	.align 8
	.type	_ZL7PG_SIZE, @object
	.size	_ZL7PG_SIZE, 8
_ZL7PG_SIZE:
	.quad	4096
	.text
	.globl	_Z3addii
	.type	_Z3addii, @function
_Z3addii:
.LFB8287:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8287:
	.size	_Z3addii, .-_Z3addii
	.section	.rodata
.LC0:
	.string	"Faking "
.LC1:
	.string	" "
	.text
	.globl	_Z8fake_addii
	.type	_Z8fake_addii, @function
_Z8fake_addii:
.LFB8288:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	addl	$100, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8288:
	.size	_Z8fake_addii, .-_Z8fake_addii
	.section	.rodata
.LC2:
	.string	"mprotect failed"
	.text
	.globl	_Z21make_address_writablePv
	.type	_Z21make_address_writablePv, @function
_Z21make_address_writablePv:
.LFB8289:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	andq	$-4096, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPKv@PLT
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPKv@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-24(%rbp), %rax
	movl	$7, %edx
	movl	$4096, %esi
	movq	%rax, %rdi
	call	mprotect@PLT
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L26
	leaq	.LC2(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
.L26:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8289:
	.size	_Z21make_address_writablePv, .-_Z21make_address_writablePv
	.globl	_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE
	.type	_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE, @function
_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE:
.LFB8290:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	movq	%rax, %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE4dataEv
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8290:
	.size	_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE, .-_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE
	.section	.rodata
.LC3:
	.string	"\\x"
	.text
	.align 2
	.type	_ZZ8tracehexSt6vectorIhSaIhEEENKUliE_clEi, @function
_ZZ8tracehexSt6vectorIhSaIhEEENKUliE_clEi:
.LFB8292:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rbx
	movl	$2, %edi
	call	_ZSt4setwi
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw@PLT
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8292:
	.size	_ZZ8tracehexSt6vectorIhSaIhEEENKUliE_clEi, .-_ZZ8tracehexSt6vectorIhSaIhEEENKUliE_clEi
	.globl	_Z8tracehexSt6vectorIhSaIhEE
	.type	_Z8tracehexSt6vectorIhSaIhEE, @function
_Z8tracehexSt6vectorIhSaIhEE:
.LFB8291:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8291
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$432, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -440(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-400(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEEC1Ev@PLT
.LEHE0:
	leaq	-400(%rbp), %rax
	leaq	_ZSt3hexRSt8ios_base(%rip), %rsi
	movq	%rax, %rdi
.LEHB1:
	call	_ZNSolsEPFRSt8ios_baseS0_E@PLT
	movq	%rax, %rbx
	movl	$48, %edi
	call	_ZSt7setfillIcESt8_SetfillIT_ES1_
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St8_SetfillIS3_E@PLT
	leaq	-400(%rbp), %rax
	movq	%rax, %r12
	movq	-440(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4cendEv
	movq	%rax, %rbx
	movq	-440(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE6cbeginEv
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt8for_eachIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEZ8tracehexS6_EUliE_ET0_T_SA_S9_
	leaq	-432(%rbp), %rax
	leaq	-400(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv@PLT
.LEHE1:
	leaq	-432(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
.LEHB2:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE2:
	leaq	-432(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-400(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L33
	jmp	.L36
.L35:
	endbr64
	movq	%rax, %rbx
	leaq	-432(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L32
.L34:
	endbr64
	movq	%rax, %rbx
.L32:
	leaq	-400(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume@PLT
.LEHE3:
.L36:
	call	__stack_chk_fail@PLT
.L33:
	addq	$432, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8291:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA8291:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8291-.LLSDACSB8291
.LLSDACSB8291:
	.uleb128 .LEHB0-.LFB8291
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB8291
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L34-.LFB8291
	.uleb128 0
	.uleb128 .LEHB2-.LFB8291
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L35-.LFB8291
	.uleb128 0
	.uleb128 .LEHB3-.LFB8291
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE8291:
	.text
	.size	_Z8tracehexSt6vectorIhSaIhEE, .-_Z8tracehexSt6vectorIhSaIhEE
	.section	.text._ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev
	.type	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev, @function
_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev:
.LFB8297:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8297:
	.size	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev, .-_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev
	.weak	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD1Ev
	.set	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD1Ev,_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD2Ev
	.section	.text._ZNSt12_Vector_baseIhSaIhEEC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEEC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEEC2Ev
	.type	_ZNSt12_Vector_baseIhSaIhEEC2Ev, @function
_ZNSt12_Vector_baseIhSaIhEEC2Ev:
.LFB8299:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8299:
	.size	_ZNSt12_Vector_baseIhSaIhEEC2Ev, .-_ZNSt12_Vector_baseIhSaIhEEC2Ev
	.weak	_ZNSt12_Vector_baseIhSaIhEEC1Ev
	.set	_ZNSt12_Vector_baseIhSaIhEEC1Ev,_ZNSt12_Vector_baseIhSaIhEEC2Ev
	.section	.text._ZNSt6vectorIhSaIhEEC2Ev,"axG",@progbits,_ZNSt6vectorIhSaIhEEC5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEEC2Ev
	.type	_ZNSt6vectorIhSaIhEEC2Ev, @function
_ZNSt6vectorIhSaIhEEC2Ev:
.LFB8301:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8301:
	.size	_ZNSt6vectorIhSaIhEEC2Ev, .-_ZNSt6vectorIhSaIhEEC2Ev
	.weak	_ZNSt6vectorIhSaIhEEC1Ev
	.set	_ZNSt6vectorIhSaIhEEC1Ev,_ZNSt6vectorIhSaIhEEC2Ev
	.section	.rodata
.LC4:
	.string	"int main()"
.LC5:
	.string	"byte.cc"
.LC6:
	.string	"result == 8"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8293:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8293
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$280, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	leaq	_Z3addii(%rip), %rdi
.LEHB4:
	call	_Z21make_address_writablePv
	movl	$4096, %esi
	movl	$4096, %edi
	call	memalign@PLT
	movq	%rax, -272(%rbp)
	movq	-272(%rbp), %rax
	movq	%rax, %rdi
	call	_Z21make_address_writablePv
.LEHE4:
	movb	$72, -69(%rbp)
	movb	$-72, -68(%rbp)
	movb	$0, -67(%rbp)
	movb	$0, -66(%rbp)
	movb	$0, -65(%rbp)
	movb	$0, -64(%rbp)
	movb	$0, -63(%rbp)
	movb	$0, -62(%rbp)
	movb	$0, -61(%rbp)
	movb	$0, -60(%rbp)
	movb	$-1, -59(%rbp)
	movb	$-32, -58(%rbp)
	leaq	-69(%rbp), %rax
	movq	%rax, -320(%rbp)
	movq	$12, -312(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhEC1Ev
	leaq	-96(%rbp), %rdx
	movq	-320(%rbp), %rcx
	movq	-312(%rbp), %rbx
	movq	%rcx, %rsi
	movq	%rbx, %rdi
	movq	%rbx, %rdi
	leaq	-256(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rdi, %rdx
	movq	%rax, %rdi
.LEHB5:
	call	_ZNSt6vectorIhSaIhEEC1ESt16initializer_listIhERKS0_
.LEHE5:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	leaq	-224(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEEC1Ev
	movl	$0, -296(%rbp)
.L42:
	movl	-296(%rbp), %eax
	movslq	%eax, %rbx
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	cmpq	%rax, %rbx
	setb	%al
	testb	%al, %al
	je	.L41
	leaq	_Z3addii(%rip), %rax
	movq	%rax, -264(%rbp)
	movl	-296(%rbp), %eax
	movslq	%eax, %rdx
	movq	-264(%rbp), %rax
	addq	%rax, %rdx
	leaq	-224(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB6:
	call	_ZNSt6vectorIhSaIhEE9push_backERKh
	addl	$1, -296(%rbp)
	jmp	.L42
.L41:
	movq	-272(%rbp), %rax
	movq	%rax, -280(%rbp)
	movl	$0, -292(%rbp)
.L44:
	cmpl	$7, -292(%rbp)
	jg	.L43
	movl	-292(%rbp), %eax
	addl	$2, %eax
	movslq	%eax, %rdx
	leaq	-256(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEEixEm
	movq	-280(%rbp), %rdx
	movb	%dl, (%rax)
	sarq	$8, -280(%rbp)
	addl	$1, -292(%rbp)
	jmp	.L44
.L43:
	leaq	-256(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEEC1ERKS1_
.LEHE6:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Z8tracehexSt6vectorIhSaIhEE
.LEHE7:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	leaq	-256(%rbp), %rdx
	leaq	-192(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB8:
	call	_ZNSt6vectorIhSaIhEEC1ERKS1_
.LEHE8:
	leaq	-192(%rbp), %rax
	movq	%rax, %rsi
	leaq	_Z3addii(%rip), %rdi
	call	_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE
	leaq	-192(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	movb	$72, -69(%rbp)
	movb	$-57, -68(%rbp)
	movb	$-64, -67(%rbp)
	movb	$8, -66(%rbp)
	movb	$0, -65(%rbp)
	movb	$0, -64(%rbp)
	movb	$0, -63(%rbp)
	movb	$-61, -62(%rbp)
	leaq	-69(%rbp), %rax
	movq	%rax, %r14
	movl	$8, %r15d
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhEC1Ev
	leaq	-96(%rbp), %rdx
	movq	%r14, %rsi
	movq	%r15, %rdi
	movq	%r14, %rcx
	movq	%r15, %rbx
	movq	%rbx, %rdi
	leaq	-160(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rdi, %rdx
	movq	%rax, %rdi
.LEHB9:
	call	_ZNSt6vectorIhSaIhEEC1ESt16initializer_listIhERKS0_
.LEHE9:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	leaq	-160(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB10:
	call	_ZNSt6vectorIhSaIhEEC1ERKS1_
	leaq	-128(%rbp), %rdx
	movq	-272(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	movl	$2, %esi
	movl	$1, %edi
	call	_Z3addii
	movl	%eax, -284(%rbp)
	cmpl	$8, -284(%rbp)
	je	.L45
	leaq	.LC4(%rip), %rcx
	movl	$79, %edx
	leaq	.LC5(%rip), %rsi
	leaq	.LC6(%rip), %rdi
	call	__assert_fail@PLT
.L45:
	movb	$72, -69(%rbp)
	movb	$-72, -68(%rbp)
	movb	$0, -67(%rbp)
	movb	$0, -66(%rbp)
	movb	$0, -65(%rbp)
	movb	$0, -64(%rbp)
	movb	$0, -63(%rbp)
	movb	$0, -62(%rbp)
	movb	$0, -61(%rbp)
	movb	$0, -60(%rbp)
	movb	$-1, -59(%rbp)
	movb	$-48, -58(%rbp)
	movb	$-61, -57(%rbp)
	leaq	-69(%rbp), %rax
	movq	%rax, %r12
	movl	$13, %r13d
	movq	%r12, %rcx
	movq	%r13, %rbx
	movq	%r12, %rax
	movq	%r13, %rdx
	leaq	-160(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE
	leaq	_Z8fake_addii(%rip), %rax
	movq	%rax, -280(%rbp)
	movl	$0, -288(%rbp)
.L47:
	cmpl	$7, -288(%rbp)
	jg	.L46
	movl	-288(%rbp), %eax
	addl	$2, %eax
	movslq	%eax, %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEEixEm
	movq	-280(%rbp), %rdx
	movb	%dl, (%rax)
	sarq	$8, -280(%rbp)
	addl	$1, -288(%rbp)
	jmp	.L47
.L46:
	leaq	-160(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEEC1ERKS1_
.LEHE10:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
.LEHB11:
	call	_Z8tracehexSt6vectorIhSaIhEE
.LEHE11:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	leaq	-160(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB12:
	call	_ZNSt6vectorIhSaIhEEC1ERKS1_
	leaq	-96(%rbp), %rdx
	movq	-272(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z21copy_insts_to_addressPvSt6vectorIhSaIhEE
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	movl	$2, %esi
	movl	$1, %edi
	call	_Z3addii
	movl	%eax, -284(%rbp)
	movl	-284(%rbp), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE12:
	movq	-272(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %ebx
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	leaq	-224(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	movl	%ebx, %eax
	movq	-56(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L55
	jmp	.L62
.L56:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB13:
	call	_Unwind_Resume@PLT
.L58:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	jmp	.L51
.L59:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	jmp	.L51
.L61:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	jmp	.L54
.L60:
	endbr64
	movq	%rax, %rbx
.L54:
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	jmp	.L51
.L57:
	endbr64
	movq	%rax, %rbx
.L51:
	leaq	-224(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE13:
.L62:
	call	__stack_chk_fail@PLT
.L55:
	addq	$280, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8293:
	.section	.gcc_except_table
.LLSDA8293:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8293-.LLSDACSB8293
.LLSDACSB8293:
	.uleb128 .LEHB4-.LFB8293
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB8293
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L56-.LFB8293
	.uleb128 0
	.uleb128 .LEHB6-.LFB8293
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L57-.LFB8293
	.uleb128 0
	.uleb128 .LEHB7-.LFB8293
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L58-.LFB8293
	.uleb128 0
	.uleb128 .LEHB8-.LFB8293
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L57-.LFB8293
	.uleb128 0
	.uleb128 .LEHB9-.LFB8293
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L59-.LFB8293
	.uleb128 0
	.uleb128 .LEHB10-.LFB8293
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L60-.LFB8293
	.uleb128 0
	.uleb128 .LEHB11-.LFB8293
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L61-.LFB8293
	.uleb128 0
	.uleb128 .LEHB12-.LFB8293
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L60-.LFB8293
	.uleb128 0
	.uleb128 .LEHB13-.LFB8293
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
.LLSDACSE8293:
	.text
	.size	main, .-main
	.section	.text._ZSt3maxImERKT_S2_S2_,"axG",@progbits,_ZSt3maxImERKT_S2_S2_,comdat
	.weak	_ZSt3maxImERKT_S2_S2_
	.type	_ZSt3maxImERKT_S2_S2_, @function
_ZSt3maxImERKT_S2_S2_:
.LFB8843:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jnb	.L64
	movq	-16(%rbp), %rax
	jmp	.L65
.L64:
	movq	-8(%rbp), %rax
.L65:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8843:
	.size	_ZSt3maxImERKT_S2_S2_, .-_ZSt3maxImERKT_S2_S2_
	.section	.text._ZNSt6vectorIhSaIhEE4dataEv,"axG",@progbits,_ZNSt6vectorIhSaIhEE4dataEv,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE4dataEv
	.type	_ZNSt6vectorIhSaIhEE4dataEv, @function
_ZNSt6vectorIhSaIhEE4dataEv:
.LFB8874:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8874:
	.size	_ZNSt6vectorIhSaIhEE4dataEv, .-_ZNSt6vectorIhSaIhEE4dataEv
	.section	.text._ZNKSt6vectorIhSaIhEE4sizeEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE4sizeEv
	.type	_ZNKSt6vectorIhSaIhEE4sizeEv, @function
_ZNKSt6vectorIhSaIhEE4sizeEv:
.LFB8875:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8875:
	.size	_ZNKSt6vectorIhSaIhEE4sizeEv, .-_ZNKSt6vectorIhSaIhEE4sizeEv
	.section	.text._ZSt7setfillIcESt8_SetfillIT_ES1_,"axG",@progbits,_ZSt7setfillIcESt8_SetfillIT_ES1_,comdat
	.weak	_ZSt7setfillIcESt8_SetfillIT_ES1_
	.type	_ZSt7setfillIcESt8_SetfillIT_ES1_, @function
_ZSt7setfillIcESt8_SetfillIT_ES1_:
.LFB8888:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8888:
	.size	_ZSt7setfillIcESt8_SetfillIT_ES1_, .-_ZSt7setfillIcESt8_SetfillIT_ES1_
	.section	.text._ZNKSt6vectorIhSaIhEE6cbeginEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE6cbeginEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE6cbeginEv
	.type	_ZNKSt6vectorIhSaIhEE6cbeginEv, @function
_ZNKSt6vectorIhSaIhEE6cbeginEv:
.LFB8890:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC1ERKS2_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L74
	call	__stack_chk_fail@PLT
.L74:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8890:
	.size	_ZNKSt6vectorIhSaIhEE6cbeginEv, .-_ZNKSt6vectorIhSaIhEE6cbeginEv
	.section	.text._ZNKSt6vectorIhSaIhEE4cendEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE4cendEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE4cendEv
	.type	_ZNKSt6vectorIhSaIhEE4cendEv, @function
_ZNKSt6vectorIhSaIhEE4cendEv:
.LFB8891:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC1ERKS2_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L77
	call	__stack_chk_fail@PLT
.L77:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8891:
	.size	_ZNKSt6vectorIhSaIhEE4cendEv, .-_ZNKSt6vectorIhSaIhEE4cendEv
	.text
	.type	_ZSt8for_eachIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEZ8tracehexS6_EUliE_ET0_T_SA_S9_, @function
_ZSt8for_eachIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEZ8tracehexS6_EUliE_ET0_T_SA_S9_:
.LFB8893:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
.L80:
	leaq	-16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_
	testb	%al, %al
	je	.L79
	leaq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	leaq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZZ8tracehexSt6vectorIhSaIhEEENKUliE_clEi
	leaq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv
	jmp	.L80
.L79:
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8893:
	.size	_ZSt8for_eachIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEZ8tracehexS6_EUliE_ET0_T_SA_S9_, .-_ZSt8for_eachIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEZ8tracehexS6_EUliE_ET0_T_SA_S9_
	.section	.text._ZNSaIhEC2Ev,"axG",@progbits,_ZNSaIhEC5Ev,comdat
	.align 2
	.weak	_ZNSaIhEC2Ev
	.type	_ZNSaIhEC2Ev, @function
_ZNSaIhEC2Ev:
.LFB8897:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8897:
	.size	_ZNSaIhEC2Ev, .-_ZNSaIhEC2Ev
	.weak	_ZNSaIhEC1Ev
	.set	_ZNSaIhEC1Ev,_ZNSaIhEC2Ev
	.section	.text._ZNSaIhED2Ev,"axG",@progbits,_ZNSaIhED5Ev,comdat
	.align 2
	.weak	_ZNSaIhED2Ev
	.type	_ZNSaIhED2Ev, @function
_ZNSaIhED2Ev:
.LFB8900:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8900:
	.size	_ZNSaIhED2Ev, .-_ZNSaIhED2Ev
	.weak	_ZNSaIhED1Ev
	.set	_ZNSaIhED1Ev,_ZNSaIhED2Ev
	.section	.text._ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_,"axG",@progbits,_ZNSt6vectorIhSaIhEEC5ESt16initializer_listIhERKS0_,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_
	.type	_ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_, @function
_ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_:
.LFB8903:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8903
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, %rax
	movq	%rdx, %rsi
	movq	%rsi, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIhE3endEv
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIhE5beginEv
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB14:
	call	_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag
.LEHE14:
	jmp	.L88
.L87:
	endbr64
	movq	%rax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEED2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB15:
	call	_Unwind_Resume@PLT
.LEHE15:
.L88:
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L86
	call	__stack_chk_fail@PLT
.L86:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8903:
	.section	.gcc_except_table
.LLSDA8903:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8903-.LLSDACSB8903
.LLSDACSB8903:
	.uleb128 .LEHB14-.LFB8903
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L87-.LFB8903
	.uleb128 0
	.uleb128 .LEHB15-.LFB8903
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
.LLSDACSE8903:
	.section	.text._ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_,"axG",@progbits,_ZNSt6vectorIhSaIhEEC5ESt16initializer_listIhERKS0_,comdat
	.size	_ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_, .-_ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_
	.weak	_ZNSt6vectorIhSaIhEEC1ESt16initializer_listIhERKS0_
	.set	_ZNSt6vectorIhSaIhEEC1ESt16initializer_listIhERKS0_,_ZNSt6vectorIhSaIhEEC2ESt16initializer_listIhERKS0_
	.section	.text._ZNSt6vectorIhSaIhEED2Ev,"axG",@progbits,_ZNSt6vectorIhSaIhEED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEED2Ev
	.type	_ZNSt6vectorIhSaIhEED2Ev, @function
_ZNSt6vectorIhSaIhEED2Ev:
.LFB8906:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8906
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8906:
	.section	.gcc_except_table
.LLSDA8906:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8906-.LLSDACSB8906
.LLSDACSB8906:
.LLSDACSE8906:
	.section	.text._ZNSt6vectorIhSaIhEED2Ev,"axG",@progbits,_ZNSt6vectorIhSaIhEED5Ev,comdat
	.size	_ZNSt6vectorIhSaIhEED2Ev, .-_ZNSt6vectorIhSaIhEED2Ev
	.weak	_ZNSt6vectorIhSaIhEED1Ev
	.set	_ZNSt6vectorIhSaIhEED1Ev,_ZNSt6vectorIhSaIhEED2Ev
	.section	.text._ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev
	.type	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev, @function
_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev:
.LFB8909:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhEC2Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8909:
	.size	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev, .-_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev
	.weak	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1Ev
	.set	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1Ev,_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2Ev
	.section	.text._ZNSt12_Vector_baseIhSaIhEED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEED5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEED2Ev
	.type	_ZNSt12_Vector_baseIhSaIhEED2Ev, @function
_ZNSt12_Vector_baseIhSaIhEED2Ev:
.LFB8912:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8912
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8912:
	.section	.gcc_except_table
.LLSDA8912:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8912-.LLSDACSB8912
.LLSDACSB8912:
.LLSDACSE8912:
	.section	.text._ZNSt12_Vector_baseIhSaIhEED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEED5Ev,comdat
	.size	_ZNSt12_Vector_baseIhSaIhEED2Ev, .-_ZNSt12_Vector_baseIhSaIhEED2Ev
	.weak	_ZNSt12_Vector_baseIhSaIhEED1Ev
	.set	_ZNSt12_Vector_baseIhSaIhEED1Ev,_ZNSt12_Vector_baseIhSaIhEED2Ev
	.section	.text._ZNSt6vectorIhSaIhEE9push_backERKh,"axG",@progbits,_ZNSt6vectorIhSaIhEE9push_backERKh,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE9push_backERKh
	.type	_ZNSt6vectorIhSaIhEE9push_backERKh, @function
_ZNSt6vectorIhSaIhEE9push_backERKh:
.LFB8914:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, %rdx
	je	.L93
	movq	-8(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L95
.L93:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE3endEv
	movq	%rax, %rcx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_
.L95:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8914:
	.size	_ZNSt6vectorIhSaIhEE9push_backERKh, .-_ZNSt6vectorIhSaIhEE9push_backERKh
	.section	.text._ZNSt6vectorIhSaIhEEixEm,"axG",@progbits,_ZNSt6vectorIhSaIhEEixEm,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEEixEm
	.type	_ZNSt6vectorIhSaIhEEixEm, @function
_ZNSt6vectorIhSaIhEEixEm:
.LFB8915:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8915:
	.size	_ZNSt6vectorIhSaIhEEixEm, .-_ZNSt6vectorIhSaIhEEixEm
	.section	.text._ZNSt6vectorIhSaIhEEC2ERKS1_,"axG",@progbits,_ZNSt6vectorIhSaIhEEC5ERKS1_,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEEC2ERKS1_
	.type	_ZNSt6vectorIhSaIhEEC2ERKS1_, @function
_ZNSt6vectorIhSaIhEEC2ERKS1_:
.LFB8917:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8917
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rbx
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	leaq	-41(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB16:
	call	_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_
.LEHE16:
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	movq	%rax, %rcx
	leaq	-41(%rbp), %rax
	movq	%rax, %rdx
	movq	%rcx, %rsi
	movq	%rbx, %rdi
.LEHB17:
	call	_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_
.LEHE17:
	leaq	-41(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %r13
	movq	-56(%rbp), %rax
	movq	(%rax), %rbx
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE3endEv
	movq	%rax, %r12
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE5beginEv
	movq	%r13, %rcx
	movq	%rbx, %rdx
	movq	%r12, %rsi
	movq	%rax, %rdi
.LEHB18:
	call	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E
.LEHE18:
	movq	-56(%rbp), %rdx
	movq	%rax, 8(%rdx)
	nop
	movq	-40(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L101
	jmp	.L104
.L102:
	endbr64
	movq	%rax, %rbx
	leaq	-41(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB19:
	call	_Unwind_Resume@PLT
.L103:
	endbr64
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEED2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE19:
.L104:
	call	__stack_chk_fail@PLT
.L101:
	addq	$40, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8917:
	.section	.gcc_except_table
.LLSDA8917:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8917-.LLSDACSB8917
.LLSDACSB8917:
	.uleb128 .LEHB16-.LFB8917
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB17-.LFB8917
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L102-.LFB8917
	.uleb128 0
	.uleb128 .LEHB18-.LFB8917
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L103-.LFB8917
	.uleb128 0
	.uleb128 .LEHB19-.LFB8917
	.uleb128 .LEHE19-.LEHB19
	.uleb128 0
	.uleb128 0
.LLSDACSE8917:
	.section	.text._ZNSt6vectorIhSaIhEEC2ERKS1_,"axG",@progbits,_ZNSt6vectorIhSaIhEEC5ERKS1_,comdat
	.size	_ZNSt6vectorIhSaIhEEC2ERKS1_, .-_ZNSt6vectorIhSaIhEEC2ERKS1_
	.weak	_ZNSt6vectorIhSaIhEEC1ERKS1_
	.set	_ZNSt6vectorIhSaIhEEC1ERKS1_,_ZNSt6vectorIhSaIhEEC2ERKS1_
	.section	.text._ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE,"axG",@progbits,_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE
	.type	_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE, @function
_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE:
.LFB8919:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rdx, %rcx
	movq	%rsi, %rax
	movq	%rdi, %rdx
	movq	%rcx, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIhE3endEv
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIhE5beginEv
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L107
	call	__stack_chk_fail@PLT
.L107:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8919:
	.size	_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE, .-_ZNSt6vectorIhSaIhEEaSESt16initializer_listIhE
	.section	.text._ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_,"axG",@progbits,_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_
	.type	_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_, @function
_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_:
.LFB9189:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9189:
	.size	_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_, .-_ZNKSt6vectorIhSaIhEE11_M_data_ptrIhEEPT_S4_
	.section	.text._ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_,"axG",@progbits,_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC5ERKS2_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_
	.type	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_, @function
_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_:
.LFB9213:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9213:
	.size	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_, .-_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC1ERKS2_
	.set	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC1ERKS2_,_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC2ERKS2_
	.section	.text._ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_,"axG",@progbits,_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_,comdat
	.weak	_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_
	.type	_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_, @function
_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_:
.LFB9215:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rax
	cmpq	%rax, %rbx
	setne	%al
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9215:
	.size	_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_, .-_ZN9__gnu_cxxneIPKhSt6vectorIhSaIhEEEEbRKNS_17__normal_iteratorIT_T0_EESB_
	.section	.text._ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv,"axG",@progbits,_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv
	.type	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv, @function
_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv:
.LFB9216:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9216:
	.size	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv, .-_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEppEv
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv:
.LFB9217:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9217:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEdeEv
	.section	.text._ZN9__gnu_cxx13new_allocatorIhEC2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhEC5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhEC2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIhEC2Ev, @function
_ZN9__gnu_cxx13new_allocatorIhEC2Ev:
.LFB9220:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9220:
	.size	_ZN9__gnu_cxx13new_allocatorIhEC2Ev, .-_ZN9__gnu_cxx13new_allocatorIhEC2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIhEC1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIhEC1Ev,_ZN9__gnu_cxx13new_allocatorIhEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIhED2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhED5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhED2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIhED2Ev, @function
_ZN9__gnu_cxx13new_allocatorIhED2Ev:
.LFB9223:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9223:
	.size	_ZN9__gnu_cxx13new_allocatorIhED2Ev, .-_ZN9__gnu_cxx13new_allocatorIhED2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIhED1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIhED1Ev,_ZN9__gnu_cxx13new_allocatorIhED2Ev
	.section	.text._ZNSt12_Vector_baseIhSaIhEEC2ERKS0_,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEEC5ERKS0_,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_
	.type	_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_, @function
_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_:
.LFB9226:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1ERKS0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9226:
	.size	_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_, .-_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_
	.weak	_ZNSt12_Vector_baseIhSaIhEEC1ERKS0_
	.set	_ZNSt12_Vector_baseIhSaIhEEC1ERKS0_,_ZNSt12_Vector_baseIhSaIhEEC2ERKS0_
	.section	.text._ZNKSt16initializer_listIhE5beginEv,"axG",@progbits,_ZNKSt16initializer_listIhE5beginEv,comdat
	.align 2
	.weak	_ZNKSt16initializer_listIhE5beginEv
	.type	_ZNKSt16initializer_listIhE5beginEv, @function
_ZNKSt16initializer_listIhE5beginEv:
.LFB9228:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9228:
	.size	_ZNKSt16initializer_listIhE5beginEv, .-_ZNKSt16initializer_listIhE5beginEv
	.section	.text._ZNKSt16initializer_listIhE3endEv,"axG",@progbits,_ZNKSt16initializer_listIhE3endEv,comdat
	.align 2
	.weak	_ZNKSt16initializer_listIhE3endEv
	.type	_ZNKSt16initializer_listIhE3endEv, @function
_ZNKSt16initializer_listIhE3endEv:
.LFB9229:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIhE5beginEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIhE4sizeEv
	addq	%rbx, %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9229:
	.size	_ZNKSt16initializer_listIhE3endEv, .-_ZNKSt16initializer_listIhE3endEv
	.section	.text._ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag,"axG",@progbits,_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag
	.type	_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag, @function
_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag:
.LFB9230:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-56(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm
	movq	-40(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	(%rax), %rdx
	movq	-56(%rbp), %rsi
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E
	movq	-40(%rbp), %rdx
	movq	%rax, 8(%rdx)
	nop
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9230:
	.size	_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag, .-_ZNSt6vectorIhSaIhEE19_M_range_initializeIPKhEEvT_S5_St20forward_iterator_tag
	.section	.text._ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv:
.LFB9231:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9231:
	.size	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	.section	.text._ZSt8_DestroyIPhhEvT_S1_RSaIT0_E,"axG",@progbits,_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E,comdat
	.weak	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
	.type	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E, @function
_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E:
.LFB9232:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPhEvT_S1_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9232:
	.size	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E, .-_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
	.section	.text._ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev
	.type	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev, @function
_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev:
.LFB9234:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9234:
	.size	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev, .-_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev
	.weak	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC1Ev
	.set	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC1Ev,_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev
	.section	.text._ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
	.type	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm, @function
_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm:
.LFB9236:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L131
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm
.L131:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9236:
	.size	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm, .-_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
	.section	.text._ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_,"axG",@progbits,_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_,comdat
	.weak	_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_
	.type	_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_, @function
_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_:
.LFB9237:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9237:
	.size	_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_, .-_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_
	.section	.text._ZNSt6vectorIhSaIhEE3endEv,"axG",@progbits,_ZNSt6vectorIhSaIhEE3endEv,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE3endEv
	.type	_ZNSt6vectorIhSaIhEE3endEv, @function
_ZNSt6vectorIhSaIhEE3endEv:
.LFB9238:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC1ERKS1_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L135
	call	__stack_chk_fail@PLT
.L135:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9238:
	.size	_ZNSt6vectorIhSaIhEE3endEv, .-_ZNSt6vectorIhSaIhEE3endEv
	.section	.text._ZNSt6vectorIhSaIhEE15_S_use_relocateEv,"axG",@progbits,_ZNSt6vectorIhSaIhEE15_S_use_relocateEv,comdat
	.weak	_ZNSt6vectorIhSaIhEE15_S_use_relocateEv
	.type	_ZNSt6vectorIhSaIhEE15_S_use_relocateEv, @function
_ZNSt6vectorIhSaIhEE15_S_use_relocateEv:
.LFB9240:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	call	_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L138
	call	__stack_chk_fail@PLT
.L138:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9240:
	.size	_ZNSt6vectorIhSaIhEE15_S_use_relocateEv, .-_ZNSt6vectorIhSaIhEE15_S_use_relocateEv
	.section	.text._ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE,"axG",@progbits,_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE,comdat
	.weak	_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE
	.type	_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE, @function
_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE:
.LFB9241:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9241:
	.size	_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE, .-_ZNSt6vectorIhSaIhEE19_S_nothrow_relocateESt17integral_constantIbLb1EE
	.section	.rodata
.LC7:
	.string	"vector::_M_realloc_insert"
	.section	.text._ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_
	.type	_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_, @function
_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_:
.LFB9239:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9239
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-88(%rbp), %rax
	leaq	.LC7(%rip), %rdx
	movl	$1, %esi
	movq	%rax, %rdi
.LEHB20:
	call	_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc
	movq	%rax, -64(%rbp)
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -56(%rbp)
	movq	-88(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE5beginEv
	movq	%rax, -80(%rbp)
	leaq	-80(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	movq	%rax, -40(%rbp)
	movq	-88(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm
.LEHE20:
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	addq	%rax, %rcx
	movq	-88(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE9constructIhJRKhEEEvRS0_PT_DpOT0_
	movq	$0, -72(%rbp)
	call	_ZNSt6vectorIhSaIhEE15_S_use_relocateEv
	testb	%al, %al
	je	.L142
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rsi
	movq	-32(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rbx, %rcx
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_
	movq	%rax, -72(%rbp)
	addq	$1, -72(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rax
	movq	-72(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	%rbx, %rcx
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_
	movq	%rax, -72(%rbp)
	jmp	.L143
.L142:
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rsi
	movq	-32(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rbx, %rcx
	movq	%rax, %rdi
.LEHB21:
	call	_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_
	movq	%rax, -72(%rbp)
	addq	$1, -72(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rax
	movq	-72(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	%rbx, %rcx
	movq	%rax, %rdi
	call	_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_
.LEHE21:
	movq	%rax, -72(%rbp)
.L143:
	call	_ZNSt6vectorIhSaIhEE15_S_use_relocateEv
	xorl	$1, %eax
	testb	%al, %al
	je	.L144
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-48(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB22:
	call	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
.L144:
	movq	-88(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	16(%rdx), %rdx
	subq	-56(%rbp), %rdx
	movq	-56(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
.LEHE22:
	movq	-88(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-88(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-32(%rbp), %rdx
	movq	-64(%rbp), %rax
	addq	%rax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, 16(%rax)
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L149
	jmp	.L152
.L150:
	endbr64
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
	cmpq	$0, -72(%rbp)
	jne	.L146
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_
	jmp	.L147
.L146:
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-72(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB23:
	call	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
.L147:
	movq	-88(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
	call	__cxa_rethrow@PLT
.LEHE23:
.L151:
	endbr64
	movq	%rax, %rbx
	call	__cxa_end_catch@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB24:
	call	_Unwind_Resume@PLT
.LEHE24:
.L152:
	call	__stack_chk_fail@PLT
.L149:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9239:
	.section	.gcc_except_table
	.align 4
.LLSDA9239:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT9239-.LLSDATTD9239
.LLSDATTD9239:
	.byte	0x1
	.uleb128 .LLSDACSE9239-.LLSDACSB9239
.LLSDACSB9239:
	.uleb128 .LEHB20-.LFB9239
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB21-.LFB9239
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L150-.LFB9239
	.uleb128 0x1
	.uleb128 .LEHB22-.LFB9239
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB23-.LFB9239
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L151-.LFB9239
	.uleb128 0
	.uleb128 .LEHB24-.LFB9239
	.uleb128 .LEHE24-.LEHB24
	.uleb128 0
	.uleb128 0
.LLSDACSE9239:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT9239:
	.section	.text._ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_,comdat
	.size	_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_, .-_ZNSt6vectorIhSaIhEE17_M_realloc_insertIJRKhEEEvN9__gnu_cxx17__normal_iteratorIPhS1_EEDpOT_
	.section	.text._ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_,"axG",@progbits,_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_,comdat
	.weak	_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_
	.type	_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_, @function
_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_:
.LFB9242:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L155
	call	__stack_chk_fail@PLT
.L155:
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9242:
	.size	_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_, .-_ZN9__gnu_cxx14__alloc_traitsISaIhEhE17_S_select_on_copyERKS1_
	.section	.text._ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	.type	_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv, @function
_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv:
.LFB9243:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9243:
	.size	_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv, .-_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	.section	.text._ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEEC5EmRKS0_,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_
	.type	_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_, @function
_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_:
.LFB9245:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9245
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1ERKS0_
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB25:
	call	_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm
.LEHE25:
	jmp	.L161
.L160:
	endbr64
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB26:
	call	_Unwind_Resume@PLT
.LEHE26:
.L161:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9245:
	.section	.gcc_except_table
.LLSDA9245:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE9245-.LLSDACSB9245
.LLSDACSB9245:
	.uleb128 .LEHB25-.LFB9245
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L160-.LFB9245
	.uleb128 0
	.uleb128 .LEHB26-.LFB9245
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0
	.uleb128 0
.LLSDACSE9245:
	.section	.text._ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEEC5EmRKS0_,comdat
	.size	_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_, .-_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_
	.weak	_ZNSt12_Vector_baseIhSaIhEEC1EmRKS0_
	.set	_ZNSt12_Vector_baseIhSaIhEEC1EmRKS0_,_ZNSt12_Vector_baseIhSaIhEEC2EmRKS0_
	.section	.text._ZNKSt6vectorIhSaIhEE5beginEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE5beginEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE5beginEv
	.type	_ZNKSt6vectorIhSaIhEE5beginEv, @function
_ZNKSt6vectorIhSaIhEE5beginEv:
.LFB9247:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC1ERKS2_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L164
	call	__stack_chk_fail@PLT
.L164:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9247:
	.size	_ZNKSt6vectorIhSaIhEE5beginEv, .-_ZNKSt6vectorIhSaIhEE5beginEv
	.section	.text._ZNKSt6vectorIhSaIhEE3endEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE3endEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE3endEv
	.type	_ZNKSt6vectorIhSaIhEE3endEv, @function
_ZNKSt6vectorIhSaIhEE3endEv:
.LFB9248:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEC1ERKS2_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L167
	call	__stack_chk_fail@PLT
.L167:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9248:
	.size	_ZNKSt6vectorIhSaIhEE3endEv, .-_ZNKSt6vectorIhSaIhEE3endEv
	.section	.text._ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E,"axG",@progbits,_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E,comdat
	.weak	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E
	.type	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E, @function
_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E:
.LFB9249:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9249:
	.size	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E, .-_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhhET0_T_SA_S9_RSaIT1_E
	.section	.text._ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag,"axG",@progbits,_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag
	.type	_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag, @function
_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag:
.LFB9250:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-72(%rbp), %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE8capacityEv
	cmpq	%rax, -32(%rbp)
	seta	%al
	testb	%al, %al
	je	.L171
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_
	movq	-72(%rbp), %rcx
	movq	-64(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_
	movq	%rax, -16(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
	movq	-56(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	16(%rdx), %rcx
	movq	-56(%rbp), %rdx
	movq	(%rdx), %rdx
	subq	%rdx, %rcx
	movq	%rcx, %rdx
	movq	%rdx, %rsi
	movq	-56(%rbp), %rdx
	movq	(%rdx), %rcx
	movq	%rsi, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
	movq	-56(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-56(%rbp), %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-56(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, 16(%rax)
	jmp	.L175
.L171:
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	cmpq	%rax, -32(%rbp)
	setbe	%al
	testb	%al, %al
	je	.L173
	movq	-56(%rbp), %rax
	movq	(%rax), %rdx
	movq	-72(%rbp), %rcx
	movq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt4copyIPKhPhET0_T_S4_S3_
	movq	%rax, %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh
	jmp	.L175
.L173:
	movq	-64(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	movq	%rax, %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt7advanceIPKhmEvRT_T0_
	movq	-56(%rbp), %rax
	movq	(%rax), %rdx
	movq	-40(%rbp), %rcx
	movq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt4copyIPKhPhET0_T_S4_S3_
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	movq	-32(%rbp), %rdx
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rcx
	movq	-56(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	%rax, %rdi
	call	_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E
	movq	-56(%rbp), %rdx
	movq	%rax, 8(%rdx)
.L175:
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L174
	call	__stack_chk_fail@PLT
.L174:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9250:
	.size	_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag, .-_ZNSt6vectorIhSaIhEE13_M_assign_auxIPKhEEvT_S5_St20forward_iterator_tag
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv:
.LFB9392:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9392:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv
	.section	.text._ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC5ERKS0_,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_
	.type	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_, @function
_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_:
.LFB9405:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSaIhEC2ERKS_
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE17_Vector_impl_dataC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9405:
	.size	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_, .-_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_
	.weak	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1ERKS0_
	.set	_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC1ERKS0_,_ZNSt12_Vector_baseIhSaIhEE12_Vector_implC2ERKS0_
	.section	.text._ZNKSt16initializer_listIhE4sizeEv,"axG",@progbits,_ZNKSt16initializer_listIhE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt16initializer_listIhE4sizeEv
	.type	_ZNKSt16initializer_listIhE4sizeEv, @function
_ZNKSt16initializer_listIhE4sizeEv:
.LFB9407:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9407:
	.size	_ZNKSt16initializer_listIhE4sizeEv, .-_ZNKSt16initializer_listIhE4sizeEv
	.section	.text._ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_,"axG",@progbits,_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_,comdat
	.weak	_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_
	.type	_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_, @function
_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_:
.LFB9408:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L183
	call	__stack_chk_fail@PLT
.L183:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9408:
	.size	_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_, .-_ZSt8distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_
	.section	.rodata
	.align 8
.LC8:
	.string	"cannot create std::vector larger than max_size()"
	.section	.text._ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_,"axG",@progbits,_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_,comdat
	.weak	_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_
	.type	_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_, @function
_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_:
.LFB9409:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rdx
	leaq	-25(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSaIhEC1ERKS_
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_
	cmpq	%rax, -40(%rbp)
	seta	%bl
	leaq	-25(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIhED1Ev
	testb	%bl, %bl
	je	.L185
	leaq	.LC8(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
.L185:
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L187
	call	__stack_chk_fail@PLT
.L187:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9409:
	.size	_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_, .-_ZNSt6vectorIhSaIhEE17_S_check_init_lenEmRKS0_
	.section	.text._ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm
	.type	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm, @function
_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm:
.LFB9410:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L189
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE8allocateERS0_m
	jmp	.L191
.L189:
	movl	$0, %eax
.L191:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9410:
	.size	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm, .-_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm
	.section	.text._ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E,"axG",@progbits,_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E,comdat
	.weak	_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E
	.type	_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E, @function
_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E:
.LFB9411:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9411:
	.size	_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E, .-_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E
	.section	.text._ZSt8_DestroyIPhEvT_S1_,"axG",@progbits,_ZSt8_DestroyIPhEvT_S1_,comdat
	.weak	_ZSt8_DestroyIPhEvT_S1_
	.type	_ZSt8_DestroyIPhEvT_S1_, @function
_ZSt8_DestroyIPhEvT_S1_:
.LFB9412:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9412:
	.size	_ZSt8_DestroyIPhEvT_S1_, .-_ZSt8_DestroyIPhEvT_S1_
	.section	.text._ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm,"axG",@progbits,_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm,comdat
	.weak	_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm
	.type	_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm, @function
_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm:
.LFB9413:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9413:
	.size	_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm, .-_ZNSt16allocator_traitsISaIhEE10deallocateERS0_Phm
	.section	.text._ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB9414:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9414:
	.size	_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_
	.type	_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_, @function
_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_:
.LFB9415:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKhEOT_RNSt16remove_referenceIS2_E4typeE
	movzbl	(%rax), %ebx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	_ZnwmPv
	movb	%bl, (%rax)
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9415:
	.size	_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_, .-_ZN9__gnu_cxx13new_allocatorIhE9constructIhJRKhEEEvPT_DpOT0_
	.section	.text._ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_,"axG",@progbits,_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC5ERKS1_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_
	.type	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_, @function
_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_:
.LFB9417:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9417:
	.size	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_, .-_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC1ERKS1_
	.set	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC1ERKS1_,_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC2ERKS1_
	.section	.text._ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc, @function
_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc:
.LFB9419:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE8max_sizeEv
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	subq	%rax, %rbx
	movq	%rbx, %rdx
	movq	-64(%rbp), %rax
	cmpq	%rax, %rdx
	setb	%al
	testb	%al, %al
	je	.L201
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
.L201:
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	movq	%rax, -40(%rbp)
	leaq	-64(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3maxImERKT_S2_S2_
	movq	(%rax), %rax
	addq	%rbx, %rax
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE4sizeEv
	cmpq	%rax, -32(%rbp)
	jb	.L202
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE8max_sizeEv
	cmpq	%rax, -32(%rbp)
	jbe	.L203
.L202:
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIhSaIhEE8max_sizeEv
	jmp	.L204
.L203:
	movq	-32(%rbp), %rax
.L204:
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L206
	call	__stack_chk_fail@PLT
.L206:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9419:
	.size	_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc, .-_ZNKSt6vectorIhSaIhEE12_M_check_lenEmPKc
	.section	.text._ZNSt6vectorIhSaIhEE5beginEv,"axG",@progbits,_ZNSt6vectorIhSaIhEE5beginEv,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE5beginEv
	.type	_ZNSt6vectorIhSaIhEE5beginEv, @function
_ZNSt6vectorIhSaIhEE5beginEv:
.LFB9420:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEC1ERKS1_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L209
	call	__stack_chk_fail@PLT
.L209:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9420:
	.size	_ZNSt6vectorIhSaIhEE5beginEv, .-_ZNSt6vectorIhSaIhEE5beginEv
	.section	.text._ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_,"axG",@progbits,_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_,comdat
	.weak	_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	.type	_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_, @function
_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_:
.LFB9421:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rax
	subq	%rax, %rbx
	movq	%rbx, %rax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9421:
	.size	_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_, .-_ZN9__gnu_cxxmiIPhSt6vectorIhSaIhEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	.section	.text._ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_,"axG",@progbits,_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_,comdat
	.weak	_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_
	.type	_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_, @function
_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_:
.LFB9422:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L214
	call	__stack_chk_fail@PLT
.L214:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9422:
	.size	_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_, .-_ZNSt6vectorIhSaIhEE11_S_relocateEPhS2_S2_RS0_
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv:
.LFB9423:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9423:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEE4baseEv
	.section	.text._ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_,"axG",@progbits,_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_,comdat
	.weak	_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_
	.type	_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_, @function
_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_:
.LFB9424:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_
	movq	%rax, %rdi
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rax, %rdx
	movq	%rbx, %rsi
	call	_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9424:
	.size	_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_, .-_ZSt34__uninitialized_move_if_noexcept_aIPhS0_SaIhEET0_T_S3_S2_RT1_
	.section	.text._ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_,"axG",@progbits,_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_,comdat
	.weak	_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_
	.type	_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_, @function
_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_:
.LFB9425:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9425:
	.size	_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_, .-_ZNSt16allocator_traitsISaIhEE7destroyIhEEvRS0_PT_
	.section	.text._ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_,"axG",@progbits,_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_,comdat
	.weak	_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_
	.type	_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_, @function
_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_:
.LFB9426:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSaIhEC1ERKS_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9426:
	.size	_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_, .-_ZNSt16allocator_traitsISaIhEE37select_on_container_copy_constructionERKS0_
	.section	.text._ZNSaIhEC2ERKS_,"axG",@progbits,_ZNSaIhEC5ERKS_,comdat
	.align 2
	.weak	_ZNSaIhEC2ERKS_
	.type	_ZNSaIhEC2ERKS_, @function
_ZNSaIhEC2ERKS_:
.LFB9428:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9428:
	.size	_ZNSaIhEC2ERKS_, .-_ZNSaIhEC2ERKS_
	.weak	_ZNSaIhEC1ERKS_
	.set	_ZNSaIhEC1ERKS_,_ZNSaIhEC2ERKS_
	.section	.text._ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm,"axG",@progbits,_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm
	.type	_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm, @function
_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm:
.LFB9430:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm
	movq	-8(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9430:
	.size	_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm, .-_ZNSt12_Vector_baseIhSaIhEE17_M_create_storageEm
	.section	.text._ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_,"axG",@progbits,_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_,comdat
	.weak	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_
	.type	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_, @function
_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_:
.LFB9431:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$1, -1(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9431:
	.size	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_, .-_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_
	.section	.text._ZNKSt6vectorIhSaIhEE8capacityEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE8capacityEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE8capacityEv
	.type	_ZNKSt6vectorIhSaIhEE8capacityEv, @function
_ZNKSt6vectorIhSaIhEE8capacityEv:
.LFB9432:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9432:
	.size	_ZNKSt6vectorIhSaIhEE8capacityEv, .-_ZNKSt6vectorIhSaIhEE8capacityEv
	.section	.text._ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_,"axG",@progbits,_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_
	.type	_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_, @function
_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_:
.LFB9433:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9433
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB27:
	call	_ZNSt12_Vector_baseIhSaIhEE11_M_allocateEm
.LEHE27:
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rcx
	movq	-24(%rbp), %rdx
	movq	-64(%rbp), %rsi
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
.LEHB28:
	call	_ZSt22__uninitialized_copy_aIPKhPhhET0_T_S4_S3_RSaIT1_E
.LEHE28:
	movq	-24(%rbp), %rax
	jmp	.L234
.L232:
	endbr64
	movq	%rax, %rdi
	call	__cxa_begin_catch@PLT
	movq	-40(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB29:
	call	_ZNSt12_Vector_baseIhSaIhEE13_M_deallocateEPhm
	call	__cxa_rethrow@PLT
.LEHE29:
.L233:
	endbr64
	movq	%rax, %rbx
	call	__cxa_end_catch@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB30:
	call	_Unwind_Resume@PLT
.LEHE30:
.L234:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9433:
	.section	.gcc_except_table
	.align 4
.LLSDA9433:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT9433-.LLSDATTD9433
.LLSDATTD9433:
	.byte	0x1
	.uleb128 .LLSDACSE9433-.LLSDACSB9433
.LLSDACSB9433:
	.uleb128 .LEHB27-.LFB9433
	.uleb128 .LEHE27-.LEHB27
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB28-.LFB9433
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L232-.LFB9433
	.uleb128 0x1
	.uleb128 .LEHB29-.LFB9433
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L233-.LFB9433
	.uleb128 0
	.uleb128 .LEHB30-.LFB9433
	.uleb128 .LEHE30-.LEHB30
	.uleb128 0
	.uleb128 0
.LLSDACSE9433:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT9433:
	.section	.text._ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_,"axG",@progbits,_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_,comdat
	.size	_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_, .-_ZNSt6vectorIhSaIhEE20_M_allocate_and_copyIPKhEEPhmT_S6_
	.section	.text._ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh,"axG",@progbits,_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh,comdat
	.align 2
	.weak	_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh
	.type	_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh, @function
_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh:
.LFB9434:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9434
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	subq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L237
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPhhEvT_S1_RSaIT0_E
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L237:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9434:
	.section	.gcc_except_table
.LLSDA9434:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE9434-.LLSDACSB9434
.LLSDACSB9434:
.LLSDACSE9434:
	.section	.text._ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh,"axG",@progbits,_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh,comdat
	.size	_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh, .-_ZNSt6vectorIhSaIhEE15_M_erase_at_endEPh
	.section	.text._ZSt4copyIPKhPhET0_T_S4_S3_,"axG",@progbits,_ZSt4copyIPKhPhET0_T_S4_S3_,comdat
	.weak	_ZSt4copyIPKhPhET0_T_S4_S3_
	.type	_ZSt4copyIPKhPhET0_T_S4_S3_, @function
_ZSt4copyIPKhPhET0_T_S4_S3_:
.LFB9435:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIPKhET_S2_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIPKhET_S2_
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	movq	%rbx, %rsi
	movq	%rcx, %rdi
	call	_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9435:
	.size	_ZSt4copyIPKhPhET0_T_S4_S3_, .-_ZSt4copyIPKhPhET0_T_S4_S3_
	.section	.text._ZSt7advanceIPKhmEvRT_T0_,"axG",@progbits,_ZSt7advanceIPKhmEvRT_T0_,comdat
	.weak	_ZSt7advanceIPKhmEvRT_T0_
	.type	_ZSt7advanceIPKhmEvRT_T0_, @function
_ZSt7advanceIPKhmEvRT_T0_:
.LFB9436:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_
	movq	-16(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L241
	call	__stack_chk_fail@PLT
.L241:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9436:
	.size	_ZSt7advanceIPKhmEvRT_T0_, .-_ZSt7advanceIPKhmEvRT_T0_
	.section	.text._ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_,"axG",@progbits,_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_,comdat
	.weak	_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_
	.type	_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_, @function
_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_:
.LFB9532:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9532:
	.size	_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_, .-_ZSt19__iterator_categoryIPKhENSt15iterator_traitsIT_E17iterator_categoryERKS3_
	.section	.text._ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag,"axG",@progbits,_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag,comdat
	.weak	_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag
	.type	_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag, @function
_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag:
.LFB9533:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	subq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9533:
	.size	_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag, .-_ZSt10__distanceIPKhENSt15iterator_traitsIT_E15difference_typeES3_S3_St26random_access_iterator_tag
	.section	.text._ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_,"axG",@progbits,_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_,comdat
	.weak	_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_
	.type	_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_, @function
_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_:
.LFB9534:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$9223372036854775807, %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_
	movq	%rax, -16(%rbp)
	leaq	-16(%rbp), %rdx
	leaq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3minImERKT_S2_S2_
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L248
	call	__stack_chk_fail@PLT
.L248:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9534:
	.size	_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_, .-_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_
	.section	.text._ZNSt16allocator_traitsISaIhEE8allocateERS0_m,"axG",@progbits,_ZNSt16allocator_traitsISaIhEE8allocateERS0_m,comdat
	.weak	_ZNSt16allocator_traitsISaIhEE8allocateERS0_m
	.type	_ZNSt16allocator_traitsISaIhEE8allocateERS0_m, @function
_ZNSt16allocator_traitsISaIhEE8allocateERS0_m:
.LFB9535:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9535:
	.size	_ZNSt16allocator_traitsISaIhEE8allocateERS0_m, .-_ZNSt16allocator_traitsISaIhEE8allocateERS0_m
	.section	.text._ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_,"axG",@progbits,_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_,comdat
	.weak	_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_
	.type	_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_, @function
_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_:
.LFB9536:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$1, -1(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9536:
	.size	_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_, .-_ZSt18uninitialized_copyIPKhPhET0_T_S4_S3_
	.section	.text._ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_,"axG",@progbits,_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_,comdat
	.weak	_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_
	.type	_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_, @function
_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_:
.LFB9537:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9537:
	.size	_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_, .-_ZNSt12_Destroy_auxILb1EE9__destroyIPhEEvT_S3_
	.section	.text._ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm
	.type	_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm, @function
_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm:
.LFB9538:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9538:
	.size	_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm, .-_ZN9__gnu_cxx13new_allocatorIhE10deallocateEPhm
	.section	.text._ZNKSt6vectorIhSaIhEE8max_sizeEv,"axG",@progbits,_ZNKSt6vectorIhSaIhEE8max_sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIhSaIhEE8max_sizeEv
	.type	_ZNKSt6vectorIhSaIhEE8max_sizeEv, @function
_ZNKSt6vectorIhSaIhEE8max_sizeEv:
.LFB9539:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt12_Vector_baseIhSaIhEE19_M_get_Tp_allocatorEv
	movq	%rax, %rdi
	call	_ZNSt6vectorIhSaIhEE11_S_max_sizeERKS0_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9539:
	.size	_ZNKSt6vectorIhSaIhEE8max_sizeEv, .-_ZNKSt6vectorIhSaIhEE8max_sizeEv
	.section	.text._ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE,"axG",@progbits,_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE,comdat
	.weak	_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE
	.type	_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE, @function
_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE:
.LFB9540:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rsi
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9540:
	.size	_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE, .-_ZNSt6vectorIhSaIhEE14_S_do_relocateEPhS2_S2_RS0_St17integral_constantIbLb1EE
	.section	.text._ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_,"axG",@progbits,_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_,comdat
	.weak	_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_
	.type	_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_, @function
_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_:
.LFB9541:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt13move_iteratorIPhEC1ES0_
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L261
	call	__stack_chk_fail@PLT
.L261:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9541:
	.size	_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_, .-_ZSt32__make_move_if_noexcept_iteratorIhSt13move_iteratorIPhEET0_PT_
	.section	.text._ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E,"axG",@progbits,_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E,comdat
	.weak	_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E
	.type	_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E, @function
_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E:
.LFB9542:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9542:
	.size	_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E, .-_ZSt22__uninitialized_copy_aISt13move_iteratorIPhES1_hET0_T_S4_S3_RSaIT1_E
	.section	.text._ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_
	.type	_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_, @function
_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_:
.LFB9543:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9543:
	.size	_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_, .-_ZN9__gnu_cxx13new_allocatorIhE7destroyIhEEvPT_
	.section	.text._ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhEC5ERKS1_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_
	.type	_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_, @function
_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_:
.LFB9545:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9545:
	.size	_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_, .-_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_
	.weak	_ZN9__gnu_cxx13new_allocatorIhEC1ERKS1_
	.set	_ZN9__gnu_cxx13new_allocatorIhEC1ERKS1_,_ZN9__gnu_cxx13new_allocatorIhEC2ERKS1_
	.section	.text._ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_,"axG",@progbits,_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_,comdat
	.weak	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_
	.type	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_, @function
_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_:
.LFB9547:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9547:
	.size	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_, .-_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhEET0_T_SC_SB_
	.section	.text._ZSt12__miter_baseIPKhET_S2_,"axG",@progbits,_ZSt12__miter_baseIPKhET_S2_,comdat
	.weak	_ZSt12__miter_baseIPKhET_S2_
	.type	_ZSt12__miter_baseIPKhET_S2_, @function
_ZSt12__miter_baseIPKhET_S2_:
.LFB9548:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9548:
	.size	_ZSt12__miter_baseIPKhET_S2_, .-_ZSt12__miter_baseIPKhET_S2_
	.section	.text._ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_,"axG",@progbits,_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_,comdat
	.weak	_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_
	.type	_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_, @function
_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_:
.LFB9549:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPKhET_S2_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPKhET_S2_
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_
	movq	%rax, %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt12__niter_wrapIPhET_RKS1_S1_
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9549:
	.size	_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_, .-_ZSt14__copy_move_a2ILb0EPKhPhET1_T0_S4_S3_
	.section	.text._ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag,"axG",@progbits,_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag,comdat
	.weak	_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag
	.type	_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag, @function
_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag:
.LFB9550:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9550:
	.size	_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag, .-_ZSt9__advanceIPKhlEvRT_T0_St26random_access_iterator_tag
	.section	.text._ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_,"axG",@progbits,_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_,comdat
	.weak	_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_
	.type	_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_, @function
_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_:
.LFB9622:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9622:
	.size	_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_, .-_ZNSt16allocator_traitsISaIhEE8max_sizeERKS0_
	.section	.text._ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv
	.type	_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv, @function
_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv:
.LFB9623:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv
	cmpq	%rax, -16(%rbp)
	seta	%al
	testb	%al, %al
	je	.L276
	call	_ZSt17__throw_bad_allocv@PLT
.L276:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_Znwm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9623:
	.size	_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv, .-_ZN9__gnu_cxx13new_allocatorIhE8allocateEmPKv
	.section	.text._ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_,"axG",@progbits,_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_,comdat
	.weak	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_
	.type	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_, @function
_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_:
.LFB9624:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt4copyIPKhPhET0_T_S4_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9624:
	.size	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_, .-_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPKhPhEET0_T_S6_S5_
	.section	.text._ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_,"axG",@progbits,_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_,comdat
	.weak	_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_
	.type	_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_, @function
_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_:
.LFB9625:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %rdi
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	movq	%r12, %rdx
	movq	%rbx, %rsi
	call	_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9625:
	.size	_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_, .-_ZSt12__relocate_aIPhS0_SaIhEET0_T_S3_S2_RT1_
	.section	.text._ZNSt13move_iteratorIPhEC2ES0_,"axG",@progbits,_ZNSt13move_iteratorIPhEC5ES0_,comdat
	.align 2
	.weak	_ZNSt13move_iteratorIPhEC2ES0_
	.type	_ZNSt13move_iteratorIPhEC2ES0_, @function
_ZNSt13move_iteratorIPhEC2ES0_:
.LFB9627:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9627:
	.size	_ZNSt13move_iteratorIPhEC2ES0_, .-_ZNSt13move_iteratorIPhEC2ES0_
	.weak	_ZNSt13move_iteratorIPhEC1ES0_
	.set	_ZNSt13move_iteratorIPhEC1ES0_,_ZNSt13move_iteratorIPhEC2ES0_
	.section	.text._ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_,"axG",@progbits,_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_,comdat
	.weak	_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_
	.type	_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_, @function
_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_:
.LFB9629:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$1, -1(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9629:
	.size	_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_, .-_ZSt18uninitialized_copyISt13move_iteratorIPhES1_ET0_T_S4_S3_
	.section	.text._ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_,"axG",@progbits,_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_,comdat
	.weak	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_
	.type	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_, @function
_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_:
.LFB9630:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	movq	%rbx, %rsi
	movq	%rcx, %rdi
	call	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9630:
	.size	_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_, .-_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET0_T_SA_S9_
	.section	.text._ZSt12__niter_baseIPKhET_S2_,"axG",@progbits,_ZSt12__niter_baseIPKhET_S2_,comdat
	.weak	_ZSt12__niter_baseIPKhET_S2_
	.type	_ZSt12__niter_baseIPKhET_S2_, @function
_ZSt12__niter_baseIPKhET_S2_:
.LFB9631:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9631:
	.size	_ZSt12__niter_baseIPKhET_S2_, .-_ZSt12__niter_baseIPKhET_S2_
	.section	.text._ZSt12__niter_baseIPhET_S1_,"axG",@progbits,_ZSt12__niter_baseIPhET_S1_,comdat
	.weak	_ZSt12__niter_baseIPhET_S1_
	.type	_ZSt12__niter_baseIPhET_S1_, @function
_ZSt12__niter_baseIPhET_S1_:
.LFB9632:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9632:
	.size	_ZSt12__niter_baseIPhET_S1_, .-_ZSt12__niter_baseIPhET_S1_
	.section	.text._ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_,"axG",@progbits,_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_,comdat
	.weak	_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_
	.type	_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_, @function
_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_:
.LFB9633:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$1, -1(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9633:
	.size	_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_, .-_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_
	.section	.text._ZSt12__niter_wrapIPhET_RKS1_S1_,"axG",@progbits,_ZSt12__niter_wrapIPhET_RKS1_S1_,comdat
	.weak	_ZSt12__niter_wrapIPhET_RKS1_S1_
	.type	_ZSt12__niter_wrapIPhET_RKS1_S1_, @function
_ZSt12__niter_wrapIPhET_RKS1_S1_:
.LFB9634:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9634:
	.size	_ZSt12__niter_wrapIPhET_RKS1_S1_, .-_ZSt12__niter_wrapIPhET_RKS1_S1_
	.section	.text._ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv,"axG",@progbits,_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv
	.type	_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv, @function
_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv:
.LFB9733:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movabsq	$9223372036854775807, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9733:
	.size	_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv, .-_ZNK9__gnu_cxx13new_allocatorIhE8max_sizeEv
	.section	.text._ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E,"axG",@progbits,_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E,comdat
	.weak	_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E
	.type	_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E, @function
_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E:
.LFB9734:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-32(%rbp), %rax
	subq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jle	.L298
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
.L298:
	movq	-8(%rbp), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9734:
	.size	_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E, .-_ZSt14__relocate_a_1IhhENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E
	.section	.text._ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_,"axG",@progbits,_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_,comdat
	.weak	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_
	.type	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_, @function
_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_:
.LFB9735:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9735:
	.size	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_, .-_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPhES3_EET0_T_S6_S5_
	.section	.text._ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_,"axG",@progbits,_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_,comdat
	.weak	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_
	.type	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_, @function
_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_:
.LFB9736:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9736:
	.size	_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_, .-_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEET_S8_
	.section	.text._ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_,"axG",@progbits,_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_,comdat
	.weak	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_
	.type	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_, @function
_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_:
.LFB9737:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt13__copy_move_aILb0EPKhPhET1_T0_S4_S3_
	movq	%rax, %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt12__niter_wrapIPhET_RKS1_S1_
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9737:
	.size	_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_, .-_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEEEPhET1_T0_SA_S9_
	.section	.text._ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_
	.type	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_, @function
_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_:
.LFB9738:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	subq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L307
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
.L307:
	movq	-8(%rbp), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9738:
	.size	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_, .-_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_
	.section	.text._ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_,"axG",@progbits,_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_,comdat
	.weak	_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_
	.type	_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_, @function
_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_:
.LFB9797:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	movq	%rbx, %rsi
	movq	%rcx, %rdi
	call	_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9797:
	.size	_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_, .-_ZSt4copyISt13move_iteratorIPhES1_ET0_T_S4_S3_
	.section	.text._ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE,"axG",@progbits,_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE,comdat
	.weak	_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	.type	_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE, @function
_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE:
.LFB9798:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx17__normal_iteratorIPKhSt6vectorIhSaIhEEE4baseEv
	movq	(%rax), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9798:
	.size	_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE, .-_ZSt12__niter_baseIPKhSt6vectorIhSaIhEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	.section	.text._ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E,"axG",@progbits,_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E,comdat
	.weak	_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	.type	_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E, @function
_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E:
.LFB9824:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13move_iteratorIPhE4baseEv
	movq	%rax, %rdi
	call	_ZSt12__miter_baseIPhET_S1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9824:
	.size	_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E, .-_ZSt12__miter_baseIPhEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	.section	.text._ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_,"axG",@progbits,_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_,comdat
	.weak	_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_
	.type	_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_, @function
_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_:
.LFB9825:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__niter_baseIPhET_S1_
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_
	movq	%rax, %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt12__niter_wrapIPhET_RKS1_S1_
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9825:
	.size	_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_, .-_ZSt14__copy_move_a2ILb1EPhS0_ET1_T0_S2_S1_
	.section	.text._ZNKSt13move_iteratorIPhE4baseEv,"axG",@progbits,_ZNKSt13move_iteratorIPhE4baseEv,comdat
	.align 2
	.weak	_ZNKSt13move_iteratorIPhE4baseEv
	.type	_ZNKSt13move_iteratorIPhE4baseEv, @function
_ZNKSt13move_iteratorIPhE4baseEv:
.LFB9828:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9828:
	.size	_ZNKSt13move_iteratorIPhE4baseEv, .-_ZNKSt13move_iteratorIPhE4baseEv
	.section	.text._ZSt12__miter_baseIPhET_S1_,"axG",@progbits,_ZSt12__miter_baseIPhET_S1_,comdat
	.weak	_ZSt12__miter_baseIPhET_S1_
	.type	_ZSt12__miter_baseIPhET_S1_, @function
_ZSt12__miter_baseIPhET_S1_:
.LFB9829:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9829:
	.size	_ZSt12__miter_baseIPhET_S1_, .-_ZSt12__miter_baseIPhET_S1_
	.section	.text._ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_,"axG",@progbits,_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_,comdat
	.weak	_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_
	.type	_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_, @function
_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_:
.LFB9830:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movb	$1, -1(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9830:
	.size	_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_, .-_ZSt13__copy_move_aILb1EPhS0_ET1_T0_S2_S1_
	.section	.text._ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_
	.type	_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_, @function
_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_:
.LFB9831:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	subq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L324
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memmove@PLT
.L324:
	movq	-8(%rbp), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9831:
	.size	_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_, .-_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB9856:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L328
	cmpl	$65535, -8(%rbp)
	jne	.L328
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L328:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9856:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3addii, @function
_GLOBAL__sub_I__Z3addii:
.LFB9879:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9879:
	.size	_GLOBAL__sub_I__Z3addii, .-_GLOBAL__sub_I__Z3addii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3addii
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
