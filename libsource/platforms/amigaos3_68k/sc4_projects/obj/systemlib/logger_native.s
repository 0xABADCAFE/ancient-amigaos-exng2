#NO_APP
.globl __9SystemLog$verbosity
.data
	.even
__9SystemLog$verbosity:
	.long 0
.globl __9SystemLog$logFile
	.even
__9SystemLog$logFile:
	.long 0
.globl __9SystemLog$logSemaphore
	.even
__9SystemLog$logSemaphore:
	.long 0
.globl __9SystemLog$loggingClassName
.text
LC0:
	.ascii "SystemLog\0"
.data
	.even
__9SystemLog$loggingClassName:
	.long LC0
.text
LC1:
	.ascii "-sysdebug\0"
LC2:
	.ascii "-syslogname\0"
LC3:
	.ascii "memory [logbuffer]\0"
LC4:
	.ascii "a\0"
LC5:
	.ascii "<standard output>\0"
LC6:
	.ascii "%s - opened logfile %s at verbosity level %d\12\0"
	.even
.globl _init__9SystemLog
_init__9SystemLog:
	movel d3,sp@-
	movel d2,sp@-
	pea 1:w
	clrl sp@-
	pea LC1
	jbsr _getArgInteger__7StartupPCclUs
	movel d0,d3
	addqw #8,sp
	movel #1,sp@
	clrl sp@-
	pea LC2
	jbsr _getArgString__7StartupPCcT1Us
	movel d0,d2
	addqw #8,sp
	movel #1,sp@
	pea 46:w
	jbsr _AllocMem
	movel d0,__9SystemLog$logSemaphore
	addql #8,sp
	jne L106
	pea LC3
	jbsr _throwResourceExhausted
	jra L111
	.even
L106:
	movel d0,sp@-
	jbsr _InitSemaphore
L111:
	addql #4,sp
	moveq #3,d0
	cmpl d3,d0
	jcs L108
	movel d3,__9SystemLog$verbosity
L108:
	tstl d2
	jeq L109
	pea LC4
	movel d2,sp@-
	jbsr _fopen
	addql #8,sp
	tstl d0
	jeq L109
	movel d0,__9SystemLog$logFile
	movel d2,d0
	jra L110
	.even
L109:
	movel ___sF,a0
	movel a0@(4),__9SystemLog$logFile
	movel #LC5,d0
L110:
	movel __9SystemLog$verbosity,sp@-
	movel d0,sp@-
	movel __9SystemLog$loggingClassName,sp@-
	pea LC6
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #20,sp
	movel sp@+,d2
	movel sp@+,d3
	rts
LC7:
	.ascii "%s - closing logfile\12\0"
	.even
.globl _done__9SystemLog
_done__9SystemLog:
	movel __9SystemLog$loggingClassName,sp@-
	pea LC7
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #12,sp
	movel __9SystemLog$logFile,d0
	jeq L113
	movel ___sF,a0
	cmpl a0@(4),d0
	jeq L113
	movel d0,sp@-
	jbsr _fclose
	addql #4,sp
L113:
	movel __9SystemLog$logSemaphore,d0
	jeq L114
	pea 46:w
	movel d0,sp@-
	jbsr _FreeMem
	addql #8,sp
L114:
	clrl __9SystemLog$logFile
	clrl __9SystemLog$logSemaphore
	rts
	nop
	.even
.globl _setVerbosity__9SystemLogQ29SystemLog9Verbosity
_setVerbosity__9SystemLogQ29SystemLog9Verbosity:
	movel __9SystemLog$verbosity,d0
	movel sp@(4),__9SystemLog$verbosity
	rts
	nop
LC8:
	.ascii "\0"
LC9:
	.ascii "Error\0"
LC10:
	.ascii "Warning\0"
LC11:
	.ascii "Info\0"
.data
	.even
_levelName.96:
	.long LC8
	.long LC9
	.long LC10
	.long LC11
.text
LC12:
	.ascii "[%s %8s]: \0"
	.even
.globl _write__9SystemLogQ29SystemLog5LevelPCce
_write__9SystemLogQ29SystemLog5LevelPCce:
	link a5,#-4
	movel d3,sp@-
	movel d2,sp@-
	movel a5@(8),d3
	movel __9SystemLog$logSemaphore,sp@-
	jbsr _ObtainSemaphore
	addql #4,sp
	tstl __9SystemLog$logFile
	jeq L117
	cmpl __9SystemLog$verbosity,d3
	jgt L117
	pea a5@(-4)
	jbsr _time
	pea a5@(-4)
	jbsr _localtime
	moveq #16,d2
	addl a5,d2
	lea _levelName.96,a0
	movel a0@(d3:l:4),sp@-
	movel d0,sp@-
	jbsr _asctime
	movel d0,sp@
	pea LC12
	movel __9SystemLog$logFile,sp@-
	jbsr _fprintf
	movel d2,sp@-
	movel a5@(12),sp@-
	movel __9SystemLog$logFile,sp@-
	jbsr _vfprintf
	addw #32,sp
	movel __9SystemLog$logFile,sp@
	jbsr _fflush
	addql #4,sp
L117:
	movel __9SystemLog$logSemaphore,sp@-
	jbsr _ReleaseSemaphore
	addql #4,sp
	movel a5@(-12),d2
	movel a5@(-8),d3
	unlk a5
	rts
	.even
.globl _printf__9SystemLogQ29SystemLog5LevelPCce
_printf__9SystemLogQ29SystemLog5LevelPCce:
	pea a5@
	movel sp,a5
	pea a5@(16)
	movel a5@(12),sp@-
	movel __9SystemLog$logFile,sp@-
	jbsr _vfprintf
	addw #12,sp
	unlk a5
	rts
