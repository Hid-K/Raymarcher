	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.file	1 "/Users/laptevaleksander/Documents/Projects/RayMarching" "./Vec3.h"
	.file	2 "/Users/laptevaleksander/Documents/Projects/RayMarching" "./SceneObjects.h"
	.file	3 "/Users/laptevaleksander/Documents/Projects/RayMarching" "./Camera.h"
	.file	4 "/Users/laptevaleksander/Documents/Projects/RayMarching" "./SceneEnviroment.h"
	.file	5 "/Users/laptevaleksander/Documents/Projects/RayMarching" "./RGB.h"
	.file	6 "/Users/laptevaleksander/Documents/Projects/RayMarching" "SceneObjects.c"
	.globl	_dest                   ## -- Begin function dest
	.p2align	4, 0x90
_dest:                                  ## @dest
Lfunc_begin0:
	.loc	6 27 0                  ## SceneObjects.c:27:0
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	leaq	16(%rbp), %rax
	movq	_sphere@GOTPCREL(%rip), %rcx
Ltmp0:
	.loc	6 28 29 prologue_end    ## SceneObjects.c:28:29
	movq	(%rcx), %rcx
	.loc	6 28 19 is_stmt 0       ## SceneObjects.c:28:19
	leaq	-24(%rbp), %rdi
	movq	(%rcx), %rdx
	movq	%rdx, (%rsp)
	movq	8(%rcx), %rdx
	movq	%rdx, 8(%rsp)
	movq	16(%rcx), %rcx
	movq	%rcx, 16(%rsp)
	movq	(%rax), %rcx
	movq	%rcx, 24(%rsp)
	movq	8(%rax), %rcx
	movq	%rcx, 32(%rsp)
	movq	16(%rax), %rax
	movq	%rax, 40(%rsp)
	callq	_substract
	.loc	6 28 12                 ## SceneObjects.c:28:12
	leaq	-24(%rbp), %rax
	movq	(%rax), %rcx
	movq	%rcx, (%rsp)
	movq	8(%rax), %rcx
	movq	%rcx, 8(%rsp)
	movq	16(%rax), %rax
	movq	%rax, 16(%rsp)
	callq	_length
	.loc	6 28 5                  ## SceneObjects.c:28:5
	addq	$80, %rsp
	popq	%rbp
	retq
Ltmp1:
Lfunc_end0:
	.cfi_endproc
                                        ## -- End function
	.comm	_sphere,8,3             ## @sphere
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple clang version 12.0.0 (clang-1200.0.32.2)" ## string offset=0
	.asciz	"SceneObjects.c"        ## string offset=47
	.asciz	"/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk" ## string offset=62
	.asciz	"MacOSX.sdk"            ## string offset=114
	.asciz	"/Users/laptevaleksander/Documents/Projects/RayMarching" ## string offset=125
	.asciz	"sphere"                ## string offset=180
	.asciz	"SceneObject"           ## string offset=187
	.asciz	"origin"                ## string offset=199
	.asciz	"Vec3"                  ## string offset=206
	.asciz	"x"                     ## string offset=211
	.asciz	"double"                ## string offset=213
	.asciz	"y"                     ## string offset=220
	.asciz	"z"                     ## string offset=222
	.asciz	"parentEnviroment"      ## string offset=224
	.asciz	"SceneEnviroment"       ## string offset=241
	.asciz	"main_camera"           ## string offset=257
	.asciz	"Camera"                ## string offset=269
	.asciz	"direction"             ## string offset=276
	.asciz	"up"                    ## string offset=286
	.asciz	"right"                 ## string offset=289
	.asciz	"FOV"                   ## string offset=295
	.asciz	"ticks_count"           ## string offset=299
	.asciz	"objects"               ## string offset=311
	.asciz	"shader"                ## string offset=319
	.asciz	"RGB"                   ## string offset=326
	.asciz	"r"                     ## string offset=330
	.asciz	"float"                 ## string offset=332
	.asciz	"g"                     ## string offset=338
	.asciz	"b"                     ## string offset=340
	.asciz	"CameraRay"             ## string offset=342
	.asciz	"end"                   ## string offset=352
	.asciz	"parentCamera"          ## string offset=356
	.asciz	"get_distance"          ## string offset=369
	.asciz	"dest"                  ## string offset=382
	.asciz	"point"                 ## string offset=387
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                       ## Abbreviation Code
	.byte	17                      ## DW_TAG_compile_unit
	.byte	1                       ## DW_CHILDREN_yes
	.byte	37                      ## DW_AT_producer
	.byte	14                      ## DW_FORM_strp
	.byte	19                      ## DW_AT_language
	.byte	5                       ## DW_FORM_data2
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.ascii	"\202|"                 ## DW_AT_LLVM_sysroot
	.byte	14                      ## DW_FORM_strp
	.ascii	"\357\177"              ## DW_AT_APPLE_sdk
	.byte	14                      ## DW_FORM_strp
	.byte	16                      ## DW_AT_stmt_list
	.byte	23                      ## DW_FORM_sec_offset
	.byte	27                      ## DW_AT_comp_dir
	.byte	14                      ## DW_FORM_strp
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	2                       ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	3                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	4                       ## Abbreviation Code
	.byte	22                      ## DW_TAG_typedef
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	5                       ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	6                       ## Abbreviation Code
	.byte	13                      ## DW_TAG_member
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	56                      ## DW_AT_data_member_location
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	7                       ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	8                       ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	9                       ## Abbreviation Code
	.byte	21                      ## DW_TAG_subroutine_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	39                      ## DW_AT_prototyped
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	10                      ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	11                      ## Abbreviation Code
	.byte	38                      ## DW_TAG_const_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	12                      ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	64                      ## DW_AT_frame_base
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	39                      ## DW_AT_prototyped
	.byte	25                      ## DW_FORM_flag_present
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	13                      ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	0                       ## EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
.set Lset0, Ldebug_info_end0-Ldebug_info_start0 ## Length of Unit
	.long	Lset0
Ldebug_info_start0:
	.short	4                       ## DWARF version number
.set Lset1, Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset1
	.byte	8                       ## Address Size (in bytes)
	.byte	1                       ## Abbrev [1] 0xb:0x22c DW_TAG_compile_unit
	.long	0                       ## DW_AT_producer
	.short	12                      ## DW_AT_language
	.long	47                      ## DW_AT_name
	.long	62                      ## DW_AT_LLVM_sysroot
	.long	114                     ## DW_AT_APPLE_sdk
.set Lset2, Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset2
	.long	125                     ## DW_AT_comp_dir
	.quad	Lfunc_begin0            ## DW_AT_low_pc
.set Lset3, Lfunc_end0-Lfunc_begin0     ## DW_AT_high_pc
	.long	Lset3
	.byte	2                       ## Abbrev [2] 0x32:0x15 DW_TAG_variable
	.long	180                     ## DW_AT_name
	.long	71                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	6                       ## DW_AT_decl_file
	.byte	24                      ## DW_AT_decl_line
	.byte	9                       ## DW_AT_location
	.byte	3
	.quad	_sphere
	.byte	3                       ## Abbrev [3] 0x47:0x5 DW_TAG_pointer_type
	.long	76                      ## DW_AT_type
	.byte	4                       ## Abbrev [4] 0x4c:0xb DW_TAG_typedef
	.long	87                      ## DW_AT_type
	.long	187                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	13                      ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0x57:0x39 DW_TAG_structure_type
	.long	187                     ## DW_AT_name
	.byte	48                      ## DW_AT_byte_size
	.byte	2                       ## DW_AT_decl_file
	.byte	6                       ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0x5f:0xc DW_TAG_member
	.long	199                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	2                       ## DW_AT_decl_file
	.byte	8                       ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x6b:0xc DW_TAG_member
	.long	224                     ## DW_AT_name
	.long	203                     ## DW_AT_type
	.byte	2                       ## DW_AT_decl_file
	.byte	9                       ## DW_AT_decl_line
	.byte	24                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x77:0xc DW_TAG_member
	.long	319                     ## DW_AT_name
	.long	356                     ## DW_AT_type
	.byte	2                       ## DW_AT_decl_file
	.byte	10                      ## DW_AT_decl_line
	.byte	32                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x83:0xc DW_TAG_member
	.long	369                     ## DW_AT_name
	.long	510                     ## DW_AT_type
	.byte	2                       ## DW_AT_decl_file
	.byte	11                      ## DW_AT_decl_line
	.byte	40                      ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	4                       ## Abbrev [4] 0x90:0xb DW_TAG_typedef
	.long	155                     ## DW_AT_type
	.long	206                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	9                       ## DW_AT_decl_line
	.byte	7                       ## Abbrev [7] 0x9b:0x29 DW_TAG_structure_type
	.byte	24                      ## DW_AT_byte_size
	.byte	1                       ## DW_AT_decl_file
	.byte	6                       ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0x9f:0xc DW_TAG_member
	.long	211                     ## DW_AT_name
	.long	196                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	8                       ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0xab:0xc DW_TAG_member
	.long	220                     ## DW_AT_name
	.long	196                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	8                       ## DW_AT_decl_line
	.byte	8                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0xb7:0xc DW_TAG_member
	.long	222                     ## DW_AT_name
	.long	196                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	8                       ## DW_AT_decl_line
	.byte	16                      ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	8                       ## Abbrev [8] 0xc4:0x7 DW_TAG_base_type
	.long	213                     ## DW_AT_name
	.byte	4                       ## DW_AT_encoding
	.byte	8                       ## DW_AT_byte_size
	.byte	3                       ## Abbrev [3] 0xcb:0x5 DW_TAG_pointer_type
	.long	208                     ## DW_AT_type
	.byte	4                       ## Abbrev [4] 0xd0:0xb DW_TAG_typedef
	.long	219                     ## DW_AT_type
	.long	241                     ## DW_AT_name
	.byte	4                       ## DW_AT_decl_file
	.byte	19                      ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0xdb:0x2d DW_TAG_structure_type
	.long	241                     ## DW_AT_name
	.byte	120                     ## DW_AT_byte_size
	.byte	4                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0xe3:0xc DW_TAG_member
	.long	257                     ## DW_AT_name
	.long	264                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	14                      ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0xef:0xc DW_TAG_member
	.long	299                     ## DW_AT_name
	.long	196                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	16                      ## DW_AT_decl_line
	.byte	104                     ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0xfb:0xc DW_TAG_member
	.long	311                     ## DW_AT_name
	.long	340                     ## DW_AT_type
	.byte	4                       ## DW_AT_decl_file
	.byte	18                      ## DW_AT_decl_line
	.byte	112                     ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	4                       ## Abbrev [4] 0x108:0xb DW_TAG_typedef
	.long	275                     ## DW_AT_type
	.long	269                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	16                      ## DW_AT_decl_line
	.byte	7                       ## Abbrev [7] 0x113:0x41 DW_TAG_structure_type
	.byte	104                     ## DW_AT_byte_size
	.byte	3                       ## DW_AT_decl_file
	.byte	8                       ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0x117:0xc DW_TAG_member
	.long	199                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	10                      ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x123:0xc DW_TAG_member
	.long	276                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	11                      ## DW_AT_decl_line
	.byte	24                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x12f:0xc DW_TAG_member
	.long	286                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
	.byte	48                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x13b:0xc DW_TAG_member
	.long	289                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	13                      ## DW_AT_decl_line
	.byte	72                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x147:0xc DW_TAG_member
	.long	295                     ## DW_AT_name
	.long	196                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	15                      ## DW_AT_decl_line
	.byte	96                      ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	3                       ## Abbrev [3] 0x154:0x5 DW_TAG_pointer_type
	.long	345                     ## DW_AT_type
	.byte	4                       ## Abbrev [4] 0x159:0xb DW_TAG_typedef
	.long	87                      ## DW_AT_type
	.long	187                     ## DW_AT_name
	.byte	4                       ## DW_AT_decl_file
	.byte	10                      ## DW_AT_decl_line
	.byte	3                       ## Abbrev [3] 0x164:0x5 DW_TAG_pointer_type
	.long	361                     ## DW_AT_type
	.byte	9                       ## Abbrev [9] 0x169:0xb DW_TAG_subroutine_type
	.long	372                     ## DW_AT_type
                                        ## DW_AT_prototyped
	.byte	10                      ## Abbrev [10] 0x16e:0x5 DW_TAG_formal_parameter
	.long	431                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	4                       ## Abbrev [4] 0x174:0xb DW_TAG_typedef
	.long	383                     ## DW_AT_type
	.long	326                     ## DW_AT_name
	.byte	5                       ## DW_AT_decl_file
	.byte	7                       ## DW_AT_decl_line
	.byte	7                       ## Abbrev [7] 0x17f:0x29 DW_TAG_structure_type
	.byte	12                      ## DW_AT_byte_size
	.byte	5                       ## DW_AT_decl_file
	.byte	4                       ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0x183:0xc DW_TAG_member
	.long	330                     ## DW_AT_name
	.long	424                     ## DW_AT_type
	.byte	5                       ## DW_AT_decl_file
	.byte	6                       ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x18f:0xc DW_TAG_member
	.long	338                     ## DW_AT_name
	.long	424                     ## DW_AT_type
	.byte	5                       ## DW_AT_decl_file
	.byte	6                       ## DW_AT_decl_line
	.byte	4                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x19b:0xc DW_TAG_member
	.long	340                     ## DW_AT_name
	.long	424                     ## DW_AT_type
	.byte	5                       ## DW_AT_decl_file
	.byte	6                       ## DW_AT_decl_line
	.byte	8                       ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	8                       ## Abbrev [8] 0x1a8:0x7 DW_TAG_base_type
	.long	332                     ## DW_AT_name
	.byte	4                       ## DW_AT_encoding
	.byte	4                       ## DW_AT_byte_size
	.byte	3                       ## Abbrev [3] 0x1af:0x5 DW_TAG_pointer_type
	.long	436                     ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0x1b4:0x5 DW_TAG_const_type
	.long	441                     ## DW_AT_type
	.byte	4                       ## Abbrev [4] 0x1b9:0xb DW_TAG_typedef
	.long	452                     ## DW_AT_type
	.long	342                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	25                      ## DW_AT_decl_line
	.byte	7                       ## Abbrev [7] 0x1c4:0x35 DW_TAG_structure_type
	.byte	80                      ## DW_AT_byte_size
	.byte	3                       ## DW_AT_decl_file
	.byte	18                      ## DW_AT_decl_line
	.byte	6                       ## Abbrev [6] 0x1c8:0xc DW_TAG_member
	.long	199                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	20                      ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x1d4:0xc DW_TAG_member
	.long	352                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	21                      ## DW_AT_decl_line
	.byte	24                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x1e0:0xc DW_TAG_member
	.long	276                     ## DW_AT_name
	.long	144                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	22                      ## DW_AT_decl_line
	.byte	48                      ## DW_AT_data_member_location
	.byte	6                       ## Abbrev [6] 0x1ec:0xc DW_TAG_member
	.long	356                     ## DW_AT_name
	.long	505                     ## DW_AT_type
	.byte	3                       ## DW_AT_decl_file
	.byte	24                      ## DW_AT_decl_line
	.byte	72                      ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	3                       ## Abbrev [3] 0x1f9:0x5 DW_TAG_pointer_type
	.long	264                     ## DW_AT_type
	.byte	3                       ## Abbrev [3] 0x1fe:0x5 DW_TAG_pointer_type
	.long	515                     ## DW_AT_type
	.byte	9                       ## Abbrev [9] 0x203:0xb DW_TAG_subroutine_type
	.long	196                     ## DW_AT_type
                                        ## DW_AT_prototyped
	.byte	10                      ## Abbrev [10] 0x208:0x5 DW_TAG_formal_parameter
	.long	144                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	12                      ## Abbrev [12] 0x20e:0x28 DW_TAG_subprogram
	.quad	Lfunc_begin0            ## DW_AT_low_pc
.set Lset4, Lfunc_end0-Lfunc_begin0     ## DW_AT_high_pc
	.long	Lset4
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	382                     ## DW_AT_name
	.byte	6                       ## DW_AT_decl_file
	.byte	26                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	196                     ## DW_AT_type
                                        ## DW_AT_external
	.byte	13                      ## Abbrev [13] 0x227:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	16
	.long	387                     ## DW_AT_name
	.byte	6                       ## DW_AT_decl_file
	.byte	26                      ## DW_AT_decl_line
	.long	144                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
Ldebug_info_end0:
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	2                       ## Header Bucket Count
	.long	2                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	0                       ## Bucket 0
	.long	1                       ## Bucket 1
	.long	474333612               ## Hash in Bucket 0
	.long	2090181205              ## Hash in Bucket 1
.set Lset5, LNames1-Lnames_begin        ## Offset in Bucket 0
	.long	Lset5
.set Lset6, LNames0-Lnames_begin        ## Offset in Bucket 1
	.long	Lset6
LNames1:
	.long	180                     ## sphere
	.long	1                       ## Num DIEs
	.long	50
	.long	0
LNames0:
	.long	382                     ## dest
	.long	1                       ## Num DIEs
	.long	526
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	8                       ## Header Bucket Count
	.long	8                       ## Header Hash Count
	.long	20                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	3                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.short	3                       ## DW_ATOM_die_tag
	.short	5                       ## DW_FORM_data2
	.short	4                       ## DW_ATOM_type_flags
	.short	11                      ## DW_FORM_data1
	.long	0                       ## Bucket 0
	.long	-1                      ## Bucket 1
	.long	2                       ## Bucket 2
	.long	5                       ## Bucket 3
	.long	-1                      ## Bucket 4
	.long	-1                      ## Bucket 5
	.long	6                       ## Bucket 6
	.long	-1                      ## Bucket 7
	.long	193468704               ## Hash in Bucket 0
	.long	-113419488              ## Hash in Bucket 0
	.long	420963290               ## Hash in Bucket 2
	.long	1343977482              ## Hash in Bucket 2
	.long	-1375063846             ## Hash in Bucket 2
	.long	259121563               ## Hash in Bucket 3
	.long	2089677494              ## Hash in Bucket 6
	.long	-1421774386             ## Hash in Bucket 6
.set Lset7, Ltypes7-Ltypes_begin        ## Offset in Bucket 0
	.long	Lset7
.set Lset8, Ltypes6-Ltypes_begin        ## Offset in Bucket 0
	.long	Lset8
.set Lset9, Ltypes2-Ltypes_begin        ## Offset in Bucket 2
	.long	Lset9
.set Lset10, Ltypes1-Ltypes_begin       ## Offset in Bucket 2
	.long	Lset10
.set Lset11, Ltypes4-Ltypes_begin       ## Offset in Bucket 2
	.long	Lset11
.set Lset12, Ltypes3-Ltypes_begin       ## Offset in Bucket 3
	.long	Lset12
.set Lset13, Ltypes0-Ltypes_begin       ## Offset in Bucket 6
	.long	Lset13
.set Lset14, Ltypes5-Ltypes_begin       ## Offset in Bucket 6
	.long	Lset14
Ltypes7:
	.long	326                     ## RGB
	.long	1                       ## Num DIEs
	.long	372
	.short	22
	.byte	0
	.long	0
Ltypes6:
	.long	213                     ## double
	.long	1                       ## Num DIEs
	.long	196
	.short	36
	.byte	0
	.long	0
Ltypes2:
	.long	241                     ## SceneEnviroment
	.long	2                       ## Num DIEs
	.long	208
	.short	22
	.byte	0
	.long	219
	.short	19
	.byte	0
	.long	0
Ltypes1:
	.long	187                     ## SceneObject
	.long	3                       ## Num DIEs
	.long	76
	.short	22
	.byte	0
	.long	87
	.short	19
	.byte	0
	.long	345
	.short	22
	.byte	0
	.long	0
Ltypes4:
	.long	342                     ## CameraRay
	.long	1                       ## Num DIEs
	.long	441
	.short	22
	.byte	0
	.long	0
Ltypes3:
	.long	332                     ## float
	.long	1                       ## Num DIEs
	.long	424
	.short	36
	.byte	0
	.long	0
Ltypes0:
	.long	206                     ## Vec3
	.long	1                       ## Num DIEs
	.long	144
	.short	22
	.byte	0
	.long	0
Ltypes5:
	.long	269                     ## Camera
	.long	1                       ## Num DIEs
	.long	264
	.short	22
	.byte	0
	.long	0
.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
